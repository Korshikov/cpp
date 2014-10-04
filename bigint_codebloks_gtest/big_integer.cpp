#include "big_integer.h"

#include <cstring>
#include <stdexcept>
#include <cstdio>
#include <iostream>

const big_integer ZERRO = 0, ONE = 1, TEN = 10;

big_integer::big_integer()
{
    data = new DataType(1);
    data->at(0)=0;
}

big_integer::big_integer(big_integer const& other)
{
    data = new DataType(other.data->size());
    std::copy(other.data->begin(),other.data->end(),data->begin())
;}

big_integer::big_integer(DataType::iterator rhsBegin,DataType::iterator rhsEnd)
{
    data = new DataType(rhsEnd-rhsBegin);
    std::copy(rhsBegin,rhsEnd,data->begin());
}

/*big_integer::big_integer(int32_t a)
{
    data = new DataType(1);
    data->at(0) =a;
}*/

big_integer::big_integer(int64_t a)
{
    data = new DataType(2);
    data->at(0) =a;
    data->at(1) =a>>wordSize;
    normailze();
}

big_integer::big_integer(std::string const& str)
{
    data = new DataType(1);
    *(data->begin()) = 0;
    char* s = new char[str.size()+1];
    std::strcpy (s, str.c_str());
    bool sing= false;;
    if(s[0]=='-')
    {   sing = true;
        s[0]=0;
    }
    big_integer t(1);
    for(int i = str.size()-1;i>=0;i--)
    {
        if((s[i]<='9')&&(s[i]>0))
        {
            *(this) += big_integer((singlWord) (s[i]-'0'))*t ;
        }
        t = mulLongShort(t,10);
    }
    if(sing)
    {
        *(this) = ~*(this)+1;
    }
    normailze();
    delete[] s;
}

big_integer::~big_integer()
{
    delete data;
}

big_integer& big_integer::normailze()
{
    DataType::iterator thisData = data->end()-1;
    if(*(thisData)&(1<<(wordSize-1)))
    {
        for(;(thisData>data->begin())&&(*thisData==4294967295)&&(*(thisData-1)&1<<(wordSize-1));thisData--)
        ;
    }
    else
    {
        for(;(thisData > data->begin())&&(*thisData==0)&&(!(*(thisData-1)&1<<(wordSize-1)));thisData--)
        ;
    }
    data->resize(thisData-data->begin()+1);
    return *this;
}

big_integer& big_integer::absNormailze()
{
    DataType::iterator thisData = data->end()-1;
        for(;(thisData > data->begin())&&(*thisData==0);thisData--)
        ;
    data->resize(thisData-data->begin()+1);
    return *this;
}

big_integer& big_integer::operator=(big_integer const& other)
{
    data->resize(other.data->size());
    for(DataType::iterator otherData = other.data->begin(), thisData =data->begin();otherData<other.data->end();)
    {
        *(thisData++)=*(otherData++);
    }
    return *this;
}

big_integer& big_integer::operator+=(big_integer const& rhs)
{
    singlWord singleByte = (singlWord)signByteArray[(*(data->end()-1)&1<<(wordSize-1)?1:0)];
    doubleWord summ=0;
    data->resize(std::max(data->size(),rhs.data->size())+1,singleByte);
    DataType::iterator thisData = data->begin(), rhsData = rhs.data->begin();
    singleByte = (singlWord)signByteArray[(*(rhs.data->end()-1)&1<<(wordSize-1)?1:0)];
    for(;thisData<data->end();)
    {
        if(rhsData<rhs.data->end())
        {
            summ += (doubleWord)*(thisData)+(doubleWord)*(rhsData++);
            *(thisData++) = (singlWord) summ;
            summ >>= wordSize;
        }
        else
        {
            summ += (doubleWord)*(thisData) + (doubleWord) singleByte;
            *(thisData++) = (singlWord) summ;
            summ >>= wordSize;
        }
    }
    (*this).normailze();
    return *this;
}

big_integer& big_integer::operator-=(big_integer const& rhs)
{
    singlWord singleByte = (singlWord)signByteArray[(*(data->end()-1)&1<<(wordSize-1)?1:0)];
    doubleWord sub=0;
    data->resize(std::max(data->size(),rhs.data->size())+1,singleByte);
    DataType::iterator thisData = data->begin(), rhsData = rhs.data->begin();
    singleByte = (singlWord)signByteArray[(*(rhs.data->end()-1)&1<<(wordSize-1)?1:0)];
    for(;thisData<data->end();)
    {
        if(rhsData<rhs.data->end())
        {
            sub = (doubleWord)*(thisData)-(doubleWord)*(rhsData++)-sub;
            *(thisData++) = (singlWord) sub;
            sub >>= 63;
        }
        else
        {
            sub = (doubleWord)*(thisData)-(doubleWord)singleByte-sub;
            *(thisData++) = (singlWord) sub;
            sub >>= 63;
        }
    }
    (*this).normailze();
    return *this;
}

big_integer& big_integer::operator*=(big_integer const& rh)
{
    bool sign = (*((this->data->end())-1)&1<<(wordSize-1))^(*(rh.data->end()-1)&1<<(wordSize-1));
    if((*this)<big_integer(0))
    {
        (*this) = -(*this);
    }
    big_integer rhs(rh);
    if(rhs<big_integer(0))
    {
        rhs = -rhs;
    }
    DataType::iterator rhsData = rhs.data -> begin();
    big_integer res = mulLongShort((*this),*(rhsData++));
    singlWord i=1;
    for(;rhsData<rhs.data->end();rhsData++)
    {
        res += mulLongShort((*this),*(rhsData))<<(wordSize*i++);
    }
    if(sign)
    {
        res = -res;
    }

    res.normailze();
    (*this) = res;

    return *this;
}

big_integer mulLongShort(const big_integer& a,const singlWord& b)
{
    big_integer res;
    res.data -> resize(a.data->size()+1,0);
    doubleWord mul=0;
    DataType::iterator r=res.data->begin();
    for(DataType::iterator i=a.data->begin();i<a.data->end();i++,r++)
    {
        mul += (doubleWord)*(i)*(doubleWord)b;
        *(r) = mul;
        mul >>=wordSize;
    }
    (*r)=mul;
    res.normailze();
    return res;
}

/*big_integer& big_integer::operator*=(big_integer const& rh)
{
    bool sign = (*((this->data->end())-1)&1<<(wordSize-1))^(*(rh.data->end()-1)&1<<(wordSize-1));
    if((*this)<big_integer(0))
    {
        (*this) = ~(*this)+1;
    }
    big_integer rhs(rh);
    if(rhs<big_integer(0))
    {
        rhs = ~rhs+1;
    }
    doubleWord n = std::max(data->size(),rhs.data->size())    ;
    DataType *res = new DataType(n*2+1);
    doubleWord mul=0,sum=0;
    doubleWord a,b,i,t;
    bool flag = 0;
    for(i=0;i<=n;i++)
    {
        if((!flag)&&(data->begin()+i<data->end()))
        {
            a= *(data->begin()+i);
        }
        else
        {
            flag = 1;
            a = 0;
        }
        for(t = 0; t+i<=n&&rhs.data->begin()+t<rhs.data->end();t++)
        {
            b= *(rhs.data->begin()+t);
            mul = (doubleWord)a*(doubleWord)b;
            sum = (doubleWord)res->at(i+t)+sum+mul;
            res->at(i+t) = sum;
            sum >>= wordSize;
        }
        for(; t+i<=n;t++)
        {
            //b = 0;
            //mul = (doubleWord)a*(doubleWord)b;
            sum = (doubleWord)res->at(i+t)+sum;//+mul;
            res->at(i+t) = sum;
            sum >>= wordSize;
        }

        if(i+t<=2*n)
        {
            res->at(i+t)+=sum;
        }
        sum = 0;

    }
    delete data;
    data = res;
    if(sign)
    {
        (*this) = ~(*this)+1;
    }
    normailze();

    return *this;
}*/

big_integer& big_integer::operator/=(big_integer const& rhs)
{

    if (rhs == 0)
    {
        throw std::runtime_error("divide by zero");
    }
    if(*(this)==0)
    {
        return *this;
    }

    *this = Div(data->begin(),data->end(),rhs.data->begin(),rhs.data->end()).quotient;
    normailze();
    //mpz_tdiv_q(mpz, mpz, rhs.mpz);

    return *this;
}

big_integer& big_integer::operator%=(big_integer const& rhs)
{
    if (rhs == 0)
    {
        throw std::runtime_error("divide by zero");
    }
    if(*(this)==0)
    {
        return *this;
    }

    *this = Div(data->begin(),data->end(),rhs.data->begin(),rhs.data->end()).remainder;
    //remainder/mpz_tgreaterdiv_r(mpz, mpz, rhs.mpz);
    normailze();
    return *this;
}

big_integer& big_integer::operator&=(big_integer const& rhs)
{
    singlWord SingleByte = (singlWord)signByteArray[(*(data->end()-1)&1<<(wordSize-1)?1:0)];
    data->resize(std::max(data->end()-data->begin(),rhs.data->end()-rhs.data->begin()),SingleByte);
    SingleByte = (singlWord)signByteArray[(*(rhs.data->end()-1)&1<<(wordSize-1)?1:0)];
    DataType::iterator thisData = data->begin(), rhsData = rhs.data->begin();
    for(;thisData<data->end();thisData++)
    {
        *(thisData)= *(thisData) & (rhsData<rhs.data->end()?*(rhsData++):SingleByte);
    }
    return *this;
}

big_integer& big_integer::operator|=(big_integer const& rhs)
{
    singlWord SingleByte = (singlWord)signByteArray[(*(data->end()-1)&1<<(wordSize-1)?1:0)];
    data->resize(std::max(data->end()-data->begin(),rhs.data->end()-rhs.data->begin()),SingleByte);
    SingleByte = (singlWord)signByteArray[(*(rhs.data->end()-1)&1<<(wordSize-1)?1:0)];
    DataType::iterator thisData = data->begin(), rhsData = rhs.data->begin();
    for(;thisData<data->end();thisData++)
    {
        *(thisData)= *(thisData) | (rhsData<rhs.data->end()?*(rhsData++):SingleByte);
    }
    return *this;
}

big_integer& big_integer::operator^=(big_integer const& rhs)
{
    singlWord SingleByte = (singlWord)signByteArray[(*(data->end()-1)&1<<(wordSize-1)?1:0)];
    data->resize(std::max(data->end()-data->begin(),rhs.data->end()-rhs.data->begin()),SingleByte);
    SingleByte = (singlWord)signByteArray[(*(rhs.data->end()-1)&1<<(wordSize-1)?1:0)];
    DataType::iterator thisData = data->begin(), rhsData = rhs.data->begin();
    for(;thisData<data->end();thisData++)
    {
        *(thisData)= *(thisData) ^ (rhsData<rhs.data->end()?*(rhsData++):SingleByte);
    }
    return *this;
}

big_integer& big_integer::operator<<=(const int& rhs)
{
    doubleWord rhsby=rhs/wordSize,rhsbi=rhs%wordSize;
    DataType *resData = new DataType((singlWord)data->size()+rhsby+1);

    doubleWord shift = 0;
    DataType::iterator thisData = data-> begin(),resultData = resData->begin()+rhsby;
    for(;thisData<data->end();)
    {
        shift = (doubleWord)shift | (doubleWord)*(thisData++)<<rhsbi;
        *(resultData++) = shift;
        shift >>= wordSize;
    }
    shift = shift | signByteArray[(*(data->end()-1)&1<<(wordSize-1)?1:0)]<<rhsbi;
    if(shift!=0)
        {
            *(resultData++) = shift;
        }
    delete data;
    /*while((*resultData == 0))
    {
        ;
    }
*/
    //resData->resize(resultData-resData->begin()>0?resultData-resData->begin():1);
    data = resData;
    //if(*(data->end()-1)==0
    normailze();
    return *this;
}

big_integer& big_integer::operator>>=(const int& rhs)
{
    doubleWord rhsby=rhs/wordSize,rhsbi=rhs%wordSize;
    DataType *resData = new DataType((data->size()>rhsby?(singlWord)data->size()-rhsby:1));

    doubleWord shift = 0;
    DataType::iterator thisData = data-> end()-1,resultData = resData->end()-1;
    shift = (doubleWord)signByteArray[(*(data->end()-1)&1<<(wordSize-1)?1:0)]<<wordSize;
    if(thisData<data->begin()+rhs/wordSize)
    {
        *(resultData)=signByteArray[(*(data->end()-1)&1<<(wordSize-1)?1:0)];
    }
    for(;thisData>=data->begin()+rhs/wordSize;)
    {
        shift = shift | *(thisData--);
        *(resultData--) = shift>>rhsbi;
        shift <<= wordSize;
    }

    delete data;
    data = resData;
    //normailze();
    return *this;
}

big_integer big_integer::operator+() const
{
    return *this;
}

big_integer big_integer::operator-() const
{
    big_integer r = big_integer(0)-(*this);
    return r;
}

big_integer big_integer::operator~() const
{
    big_integer res;
    res.data->resize(data->size());
    for(DataType::iterator thisData = data->begin(), resData= res.data->begin(); thisData < data->end();thisData++,resData++)
    {
        *(resData) = ~*(thisData);
    }
    res.normailze();
    return res;
}

big_integer& big_integer::operator++()
{
    *this += 1;
    return *this;
}

big_integer big_integer::operator++(int)
{
    big_integer r = *this;
    ++*this;
    return r;
}

big_integer& big_integer::operator--()
{
    *this-=1;
    return *this;
}

big_integer big_integer::operator--(int)
{
    big_integer r = *this;
    --*this;
    return r;
}

big_integer operator+(big_integer a, big_integer const& b)
{
    return a += b;
}

big_integer operator-(big_integer a, big_integer const& b)
{
    return a -= b;
}

big_integer operator*(big_integer a, big_integer const& b)
{
    return a *= b;
}

big_integer operator/(big_integer a, big_integer const& b)
{
    return a /= b;
}

big_integer operator%(big_integer a, big_integer const& b)
{
    return a %= b;
}

big_integer operator&(big_integer a, big_integer const& b)
{
    return a &= b;
}

big_integer operator|(big_integer a, big_integer const& b)
{
    return a |= b;
}

big_integer operator^(big_integer a, big_integer const& b)
{
    return a ^= b;
}

big_integer operator<<(big_integer a, int b)
{
    return a <<= b;
}

big_integer operator>>(big_integer a, int b)
{
    return a >>= b;
}

bool operator==(big_integer const& a, big_integer const& b)
{
    return compare(a, b) == 0;
}

bool operator!=(big_integer const& a, big_integer const& b)
{
    return compare(a, b) != 0;
}

bool operator<(big_integer const& a, big_integer const& b)
{
    return compare(a, b) < 0;
}

bool operator>(big_integer const& a, big_integer const& b)
{
    return compare(a, b) > 0;
}

bool operator<=(big_integer const& a, big_integer const& b)
{
    return compare(a, b) <= 0;
}

bool operator>=(big_integer const& a, big_integer const& b)
{
    return compare(a, b) >= 0;
}

std::string to_string(big_integer const& a)
{

    std::string res;
    bool sign=false;
    big_integer c=a,b;
    if(a==0)
    {
        return std::string("0");
    }
    if(a<0)
    {
        sign = true;
        c = ~a+1;
    }
    while(c>0)
    {
        b = c%TEN;
        res =  (char)(*(b.data->begin())+'0')+res;
        c/=TEN;
    }

    if(sign)
    {
        res = '-'+res;
    }

    return res;
}

std::ostream& operator<<(std::ostream& s, big_integer const& a)
{
    return s << to_string(a);
}

int8_t compare(big_integer const& a,big_integer const& b)
{
    bool asign = *(a.data->end()-1)&1<<(wordSize-1);
    bool bsign = *(b.data->end()-1)&1<<(wordSize-1);
    if(asign&&(!bsign))
    {
        return -1;
    }
    if((!asign)&&bsign)
    {
        return 1;
    }
    DataType::iterator aData = a.data->end()-1,bData = b.data->end()-1;
    if(asign)
    {
        for(;(aData>a.data->begin())&&(*aData==4294967295);aData--)
        ;
    }
    else
    {
        for(;(aData > a.data->begin())&&(*aData==0);aData--)
        ;
    }

    if(bsign)
    {
        for(;(bData>b.data->begin())&&(*bData==4294967295);bData--)
        ;
    }
    else
    {
        for(;(bData > b.data->begin())&&(*bData==0);bData--)
        ;
    }
    if((a.data->end()-aData)>(b.data->end()-bData))
    {
        if(asign)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
    if((a.data->end()-aData)<(b.data->end()-bData))
    {
        if(asign)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }

    //size(a)==size(b), singl a== singl b;
    while(aData>= a.data->begin())
    {
        if(*aData>*bData)
        {
            if(asign)
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }
        if(*aData<*bData)
        {
            if(asign)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        aData--;bData--;
    }
    return 0;
}

diviPair Div(DataType::iterator aBegin,DataType::iterator aEnd,DataType::iterator bBegin,DataType::iterator bEnd)
{
    bool sign = (*(aEnd-1)&1<<(wordSize-1))^(*(bEnd-1)&1<<(wordSize-1));
    big_integer a(aBegin,aEnd),b(bBegin,bEnd);
    if((*(aEnd-1)&1<<(wordSize-1)))
    {
        a = ~a+ONE;
    }
    if((*(bEnd-1)&1<<(wordSize-1)))
    {
        b = ~b+ONE;
    }
    singlWord m = (aEnd-aBegin)-(bEnd-bBegin), n = (bEnd-bBegin);
    if(*(b.data->end()-1)==0)
    {
        m++;
        n--;
    }
    diviPair res ;
    if((n>m))
    {
        res = recursiveDivRem(a,b);
    }
    else
    {
        res= insideNativeDiv(a,b);
    }
    if(sign)
    {
        res.quotient = ~res.quotient+ONE;
    }
    if(*(aEnd-1)&1<<(wordSize-1))
    {
        res.remainder = ~res.remainder +ONE;
    }
    return res;
}


diviPair insideNativeDiv(big_integer& a,const big_integer& b)
{
    big_integer q;
    doubleWord m = (a.data->end()-a.data->begin())-(b.data->end()-b.data->begin()), n = (b.data->end()-b.data->begin());
    doubleWord qn;
    singlWord mov=0;
    if(*(b.data->end()-1)==0)
    {
        m++;
        n--;
        mov=1;
    }
    q.data->resize(m+1);
    if(a>=((b<<(wordSize*m))))
    {
        q.data->at(m) = *(a.data->end()-1)/ *(b.data->end()-1-mov);
        while(a<(((q.data->at(m)*b)<<(wordSize*m))))
        {
            q.data->at(m)--;
        }
        a -= (((q.data->at(m)*b)<<(wordSize*m)));
    }
    else
    {
        q.data->at(m)=0;
    }
    big_integer bufer;
    for(int64_t t= m-1;t>=0;t--)
    {

        qn = (((n+t<a.data->size()?(doubleWord)a.data->at(n+t)<<wordSize:0))+(n+t-1<a.data->size()?(doubleWord)a.data->at(n+t-1):0))/((doubleWord)b.data->at(n-1));
        qn = std::min(qn,(doubleWord) signByteArray[1]);
        a-=  big_integer(qn)*(b<<(wordSize*t));
        bufer = (b<<(wordSize*t));
        while(*(a.data->end()-1)&1<<(wordSize-1))
        {
            qn--;
            a+=bufer;
        }
        q.data->at(t)=qn;
    }
    diviPair res;
    res.quotient = q;
    res.remainder = a;

    return res;
}

diviPair SvobodaDiv(big_integer a ,big_integer& b)
{
    doubleWord m = (a.data->end()-a.data->begin())-(b.data->end()-b.data->begin()), n = (b.data->end()-b.data->begin());
    if(*(b.data->end()-1)==0)
    {
        m++;
        n--;
    }
    big_integer k = (big_integer(1)<<(wordSize*(n+1)));
    diviPair buf = insideNativeDiv(k,b);
    k = buf.quotient;
    big_integer q;
    q.data->resize(m);
    if (buf.remainder>ZERRO)
    {
        k+=ONE;
    }
    big_integer b1 = k*b;
    for(singlWord i = m-1;i>0;i--)
    {
        q.data->at(i) =  (a.data->size()<n+i? a.data->at(n+i):0);
        a-=mulLongShort(b1,q.data->at(i))<<(wordSize*(i-1));
        if(a<ZERRO)
        {
            q.data->at(i)--;
            a +=  b1 << (wordSize*(i-1));
        }
    }
    diviPair res;
    res.quotient=b;
    res.quotient.data->resize(m);
    res.quotient>>=wordSize;
    buf = insideNativeDiv(a,b);
    res.quotient = res.quotient*k+q.data->at(0);
    res.remainder = buf.remainder;
    return res;
}

diviPair recursiveDivRem(big_integer a,const big_integer& b)
{
    big_integer q,b1,b0,a_,a__,atemp;
    singlWord m = (a.data->size())-(b.data->size());
    if(m<2)
    {
        return insideNativeDiv(a,b);
    }
    singlWord k = m/2;
    b1 = b>>(wordSize*k);
    b0 = b;
    b0.data->resize(k);
    diviPair res0,res1;
    res1 = recursiveDivRem(a>>(wordSize*2*k),b1);
    a.data->resize(k);
    a_ = (res1.remainder<<(wordSize*2*k))+a-res1.quotient*b0<<(wordSize*k);
    while(*(a_.data->end()-1)&1<<(wordSize-1))
    {
        res1.quotient--;
        a_+=b<<(wordSize*k);
    }
    res0 = recursiveDivRem(a_>>(wordSize*k),b1);
    a_.data->resize(k);
    a__ = (res0.remainder<<(wordSize*k)) + a_- res0.quotient*b0;
    while(*(a__.data->end()-1)&1<<(wordSize-1))
    {
        res0.quotient--;
        a__+=b;
    }
    diviPair res;
    res.quotient = (res1.quotient << (wordSize*k)) + res0.quotient;
    res.remainder = a__;
    return res;
}

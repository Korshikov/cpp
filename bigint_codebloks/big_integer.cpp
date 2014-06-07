#include "big_integer.h"

#include <cstring>
#include <stdexcept>
#include <cstdio>

big_integer::big_integer()
{
    data = new DataType(1);
    data->at(0)=0;
}

big_integer::big_integer(big_integer const& other)
{
    data = new DataType(other.data->size());
    std::copy(other.data->begin(),other.data->end(),data->begin());
}

big_integer::big_integer(DataType::iterator rhsBegin,DataType::iterator rhsEnd)
{
    data = new DataType(rhsEnd-rhsBegin);
    std::copy(rhsBegin,rhsEnd,data->begin());
}

big_integer::big_integer(int32_t a)
{
    data = new DataType(1);
    data->at(0) =a;
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
            *(this) += big_integer((uint32_t) (s[i]-'0'))*t ;
        }
        t*= 10;
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
    if(*(thisData)&1<<31)
    {
        for(;(thisData > data->begin())&&(*thisData==4294967295)&&(*(thisData-1)&1<<31);thisData--)
        ;
    }
    else
    {
        for(;(thisData > data->begin())&&(*thisData==0)&&(!(*(thisData-1)&1<<31));thisData--)
        ;
    }
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
    uint32_t singleByte = (uint32_t)signByteArray[(*(data->end()-1)&1<<31?1:0)];
    uint64_t summ=0;
    data->resize(std::max(data->size(),rhs.data->size())+1,singleByte);
    DataType::iterator thisData = data->begin(), rhsData = rhs.data->begin();
    singleByte = (uint32_t)signByteArray[(*(rhs.data->end()-1)&1<<31?1:0)];
    for(;thisData<data->end();)
    {
        if(rhsData<rhs.data->end())
        {
            summ += (uint64_t)*(thisData)+(uint64_t)*(rhsData++);
            *(thisData++) = (uint32_t) summ;
            summ >>= 32;
        }
        else
        {
            summ += (uint64_t)*(thisData) + (uint64_t) singleByte;
            *(thisData++) = (uint32_t) summ;
            summ >>= 32;
        }
    }
    (*this).normailze();
    return *this;
}

big_integer& big_integer::operator-=(big_integer const& rhs)
{
    uint32_t singleByte = (uint32_t)signByteArray[(*(data->end()-1)&1<<31?1:0)];
    uint64_t sub=0;
    data->resize(std::max(data->size(),rhs.data->size())+1,singleByte);
    DataType::iterator thisData = data->begin(), rhsData = rhs.data->begin();
    singleByte = (uint32_t)signByteArray[(*(rhs.data->end()-1)&1<<31?1:0)];
    for(;thisData<data->end();)
    {
        if(rhsData<rhs.data->end())
        {
            sub = (uint64_t)*(thisData)-(uint64_t)*(rhsData++)-sub;
            *(thisData++) = (uint32_t) sub;
            sub >>= 63;
        }
        else
        {
            sub = (uint64_t)*(thisData)-(uint64_t)singleByte-sub;
            *(thisData++) = (uint32_t) sub;
            sub >>= 63;
        }
    }
    (*this).normailze();
    return *this;
}

big_integer& big_integer::operator*=(big_integer const& rhs)
{
    uint32_t thisSingleByte = (uint32_t)signByteArray[(*(data->end()-1)&1<<31?1:0)];
    uint32_t rhsSingleByte = (uint32_t)signByteArray[(*(rhs.data->end()-1)&1<<31?1:0)];
    uint32_t n = std::max(data->size(),rhs.data->size())*2;
    DataType *res = new DataType(n);
    uint64_t mul=0,sum=0;
    uint32_t a,b,i,t;
    for(i=0;i<n;i++)
    {
        if(data->begin()+i<data->end())
        {
            a= *(data->begin()+i);
        }
        else
        {
            a = thisSingleByte;
        }
        for(t = 0; t+i<n;t++)
        {
            if(rhs.data->begin()+t<rhs.data->end())
            {
                b= *(rhs.data->begin()+t);
            }
            else
            {
                b = rhsSingleByte;
            }
            mul = (uint64_t)a*(uint64_t)b;
            sum = (uint64_t)res->at(i+t)+sum+mul;
            res->at(i+t) = sum;
            sum >>= 32;
        }
        if(i+t<n)
        {
            res->at(i+t)+=sum;
        }
        sum = 0;

    }
    delete data;
    data = res;
    normailze();
    return *this;
}

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

    *this = nativeDiv(data->begin(),data->end(),rhs.data->begin(),rhs.data->end()).quotient;
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

    *this = nativeDiv(data->begin(),data->end(),rhs.data->begin(),rhs.data->end()).remainder;
    //remainder/mpz_tgreaterdiv_r(mpz, mpz, rhs.mpz);
    normailze();
    return *this;
}

big_integer& big_integer::operator&=(big_integer const& rhs)
{
    uint32_t SingleByte = (uint32_t)signByteArray[(*(data->end()-1)&1<<31?1:0)];
    data->resize(std::max(data->end()-data->begin(),rhs.data->end()-rhs.data->begin()),SingleByte);
    SingleByte = (uint32_t)signByteArray[(*(rhs.data->end()-1)&1<<31?1:0)];
    DataType::iterator thisData = data->begin(), rhsData = rhs.data->begin();
    for(;thisData<data->end();thisData++)
    {
        *(thisData)= *(thisData) & (rhsData<rhs.data->end()?*(rhsData++):SingleByte);
    }
    return *this;
}

big_integer& big_integer::operator|=(big_integer const& rhs)
{
    uint32_t SingleByte = (uint32_t)signByteArray[(*(data->end()-1)&1<<31?1:0)];
    data->resize(std::max(data->end()-data->begin(),rhs.data->end()-rhs.data->begin()),SingleByte);
    SingleByte = (uint32_t)signByteArray[(*(rhs.data->end()-1)&1<<31?1:0)];
    DataType::iterator thisData = data->begin(), rhsData = rhs.data->begin();
    for(;thisData<data->end();thisData++)
    {
        *(thisData)= *(thisData) | (rhsData<rhs.data->end()?*(rhsData++):SingleByte);
    }
    return *this;
}

big_integer& big_integer::operator^=(big_integer const& rhs)
{
    uint32_t SingleByte = (uint32_t)signByteArray[(*(data->end()-1)&1<<31?1:0)];
    data->resize(std::max(data->end()-data->begin(),rhs.data->end()-rhs.data->begin()),SingleByte);
    SingleByte = (uint32_t)signByteArray[(*(rhs.data->end()-1)&1<<31?1:0)];
    DataType::iterator thisData = data->begin(), rhsData = rhs.data->begin();
    for(;thisData<data->end();thisData++)
    {
        *(thisData)= *(thisData) ^ (rhsData<rhs.data->end()?*(rhsData++):SingleByte);
    }
    return *this;
}

big_integer& big_integer::operator<<=(int rhs)
{
    if (rhs < 0)
    {
        throw std::runtime_error("negative shift");
    }

    uint32_t rhsby=rhs/32,rhsbi=rhs%32;
    DataType *resData = new DataType((uint32_t)data->size()+rhsby+1);

    uint64_t shift = 0;
    DataType::iterator thisData = data-> begin(),resultData = resData->begin()+rhsby;
    for(;thisData<data->end();)
    {
        shift = (uint64_t)shift | (uint64_t)*(thisData++)<<rhsbi;
        *(resultData++) = shift;
        shift >>= 32;
    }
    shift = shift | signByteArray[(*(data->end()-1)&1<<31?1:0)]<<rhsbi;
    *(resultData++) = shift;

    delete data;
    data = resData;
    normailze();
    return *this;
}

big_integer& big_integer::operator>>=(int rhs)
{
    if (rhs < 0)
    {
        throw std::runtime_error("negative shift");
    }
    uint32_t rhsby=rhs/32,rhsbi=rhs%32;
    DataType *resData = new DataType((data->size()>rhsby?(uint32_t)data->size()-rhsby:1));

    uint64_t shift = 0;
    DataType::iterator thisData = data-> end()-1,resultData = resData->end()-1;
    shift = (uint64_t)signByteArray[(*(data->end()-1)&1<<31?1:0)]<<32;
    if(thisData<data->begin()+rhs/32)
    {
        *(resultData)=signByteArray[(*(data->end()-1)&1<<31?1:0)];
    }
    for(;thisData>=data->begin()+rhs/32;)
    {
        shift = shift | *(thisData--);
        *(resultData--) = shift>>rhsbi;
        shift <<= 32;
    }

    delete data;
    data = resData;
    normailze();
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
    big_integer(1);
    while(c!=0)
    {
        for(DataType::iterator i = b.data->end()-1; i>= b.data->begin();i--)
    {
        std::printf("%08X",*(i));
    }
    std::printf("\n");
        for(DataType::iterator i = c.data->end()-1; i>= c.data->begin();i--)
    {
        std::printf("%08X",*(i));
    }
    std::printf("\n");
        b = c%10;
        res =  (char)((char)*(b.data->begin())+'0')+res;
        c/=10;
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
    big_integer c = a-b;
    if((c.data->size()==1)&&(*c.data->begin()==0))
    {
        return 0;
    }
    if(*(c.data->end()-1)&1<<31)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

diviPair nativeDiv(DataType::iterator aBegin,DataType::iterator aEnd,DataType::iterator bBegin,DataType::iterator bEnd)
{
    bool sign = (*(aEnd-1)&1<<31)^(*(bEnd-1)&1<<31);
    big_integer a(aBegin,aEnd),b(bBegin,bEnd);
    if(a<big_integer(0))
    {
        a = ~a+1;
    }
    if(b<big_integer(0))
    {
        b = ~b+1;
    }

    diviPair res = insideNativeDiv(a,b);
    if(sign)
    {
        res.quotient = ~res.quotient+1;
    }
    if(*(aEnd-1)&1<<31)
    {
        res.remainder = ~res.remainder +1;
    }
    return res;
}


diviPair insideNativeDiv(big_integer& a,big_integer& b)
{
    big_integer q;
    uint32_t m = (a.data->end()-a.data->begin())-(b.data->end()-b.data->begin()), n = (b.data->end()-b.data->begin());
    uint64_t qn;
    q.data->resize(m+1);
    if(a>=((big_integer(1)<<(32*m))*b))
    {
        q.data->at(m) = *(a.data->end()-1)/ *(b.data->end()-1);
        if(a<((big_integer(1)<<(32*m))*b)*q.data->at(m))
        {
            q.data->at(m)--;
        }
        a -= (big_integer(1)<<32*m)*b*q.data->at(m);
    }
    else
    {
        q.data->at(m)=0;
    }
    for(uint32_t t= m-1;t<=0;t--)
    {

        qn = (((uint64_t)a.data->at(n+t)<<32)+(uint64_t)a.data->at(n+t-1))/(uint64_t)b.data->at(n-1);
        qn = std::min(qn,(uint64_t) signByteArray[1]);
        a-= big_integer((uint32_t)qn)*(b<<(32*t));
        while(a<0)
        {
            qn--;
            a+=(b<<(32*t));
        }
        q.data->at(t)=qn;
    }
    diviPair res;
    res.quotient = q;
    res.remainder = a;

    return res;
}

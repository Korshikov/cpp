#include "big_integer.h"

#include <cstring>
#include <stdexcept>
#include <cstdio>
#include <iostream>

const big_integer ZERRO = 0, ONE = 1, TEN = 10;

big_integer::big_integer() {
    data = new DataType(1);
    data->at(0) = 0;
}

big_integer::big_integer(big_integer const &other) {
    data = new DataType(other.data->size());
    std::copy(other.data->begin(), other.data->end(), data->begin());
}

big_integer::big_integer(DataType::iterator rhsBegin, DataType::iterator rhsEnd) {
    data = new DataType(rhsEnd - rhsBegin);
    std::copy(rhsBegin, rhsEnd, data->begin());
}



big_integer::big_integer(int64_t a) {
    data = new DataType(2);
    data->at(0) = a;
    data->at(1) = a >> wordSize;
    normailze();
}

big_integer::big_integer(std::string const &str) {
    data = new DataType(1);
    *(data->begin()) = 0;
    char *s = new char[str.size() + 1];
    std::strcpy(s, str.c_str());
    bool sing = false;;
    if (s[0] == '-') {
        sing = true;
        s[0] = 0;
    }
    big_integer t(1);
    for (int i = str.size() - 1; i >= 0; i--) {
        if ((s[i] <= '9') && (s[i] > 0)) {
            *(this) += mulLongShort(t, (singlWord) (s[i] - '0'));
        }
        else {
            delete data;
            delete[] s;
            throw std::runtime_error("unexpected symbol in input string");

        }
        t = mulLongShort(t, 10);
        t.normailze();
    }
    if (sing) {
        *(this) = ~*(this) + 1;
    }
    normailze();
    delete[] s;
}

big_integer::~big_integer() {
    delete data;
}

big_integer &big_integer::normailze() {
    DataType::iterator thisData = data->end() - 1;
    if (*(thisData) & (1 << (wordSize - 1))) {
        for (; (thisData > data->begin()) && (*thisData == MAX_SINGLWORLD) && (*(thisData - 1) & 1 << (wordSize - 1)); thisData--);
    }
    else {
        for (; (thisData > data->begin()) && (*thisData == 0) && (!(*(thisData - 1) & 1 << (wordSize - 1))); thisData--);
    }
    data->resize(thisData - data->begin() + 1);
    return *this;
}



big_integer &big_integer::absNormailze() {
    DataType::iterator thisData = data->end() - 1;
    for (; (thisData > data->begin()) && (*thisData == 0); thisData--);
    data->resize(thisData - data->begin() + 1);
    return *this;
}

big_integer &big_integer::abs() {
    if ((*this) < 0) {
        (*this) = ~(*this) + ONE;
    }
    return *this;
}

big_integer &big_integer::operator=(big_integer const &other) {
    data->resize(other.data->size());
    for (DataType::iterator otherData = other.data->begin(), thisData = data->begin(); otherData < other.data->end();) {
        *(thisData++) = *(otherData++);
    }
    return *this;
}

big_integer &big_integer::operator+=(big_integer const &rhs) {
    singlWord singleByte = (singlWord) signByteArray[(*(data->end() - 1) & 1 << (wordSize - 1) ? 1 : 0)];
    doubleWord summ = 0;
    data->resize(std::max(data->size(), rhs.data->size()) + 1, singleByte);
    DataType::iterator thisData = data->begin(), rhsData = rhs.data->begin();
    singleByte = (singlWord) signByteArray[(*(rhs.data->end() - 1) & 1 << (wordSize - 1) ? 1 : 0)];
    for (; thisData < data->end();) {
        if (rhsData < rhs.data->end()) {
            summ += (doubleWord) *(thisData) + (doubleWord) *(rhsData++);
            *(thisData++) = (singlWord) summ;
            summ >>= wordSize;
        }
        else {
            if (singleByte == 0 && summ == 0) {

                break;
            }
            summ += (doubleWord) *(thisData) + (doubleWord) singleByte;
            *(thisData++) = (singlWord) summ;
            summ >>= wordSize;
        }
    }
    (*this).normailze();
    return *this;
}

big_integer &big_integer::operator-=(big_integer const &rhs) {
    singlWord singleByte = (singlWord) signByteArray[(*(data->end() - 1) & 1 << (wordSize - 1) ? 1 : 0)];
    doubleWord sub = 0;
    data->resize(std::max(data->size(), rhs.data->size()) + 1, singleByte);
    DataType::iterator thisData = data->begin(), rhsData = rhs.data->begin();
    singleByte = (singlWord) signByteArray[(*(rhs.data->end() - 1) & 1 << (wordSize - 1) ? 1 : 0)];
    for (; thisData < data->end();) {
        if (rhsData < rhs.data->end()) {
            sub = (doubleWord) *(thisData) - (doubleWord) *(rhsData++) - sub;
            *(thisData++) = (singlWord) sub;
            sub >>= 63;
        }
        else {
            sub = (doubleWord) *(thisData) - (doubleWord) singleByte - sub;
            *(thisData++) = (singlWord) sub;
            sub >>= 63;
        }
    }
    (*this).normailze();
    return *this;
}

big_integer &big_integer::operator*=(big_integer const &rh) {
    bool sign = (*((this->data->end()) - 1) & 1 << (wordSize - 1)) ^(*(rh.data->end() - 1) & 1 << (wordSize - 1));
    if ((*this) < big_integer(0)) {
        (*this) = -(*this);
    }
    big_integer rhs(rh);
    if (rhs < big_integer(0)) {
        rhs = -rhs;
    }
    DataType::iterator rhsData = rhs.data->begin();
    big_integer res = mulLongShort((*this), *(rhsData));
    rhsData++;
    singlWord i = 1;
    for (; rhsData < rhs.data->end(); rhsData++) {
        res += mulLongShort((*this), *(rhsData)) << (wordSize * i++);
    }
    if (sign) {
        res = ~res + ONE;
    }

    res.normailze();
    (*this) = res;

    return *this;
}

big_integer big_integer::mulLongShort(const big_integer &a, const singlWord &b) {
    big_integer res;
    res.data->resize(a.data->size() + 1, 0);
    doubleWord mul = 0;
    DataType::iterator r = res.data->begin();
    for (DataType::iterator i = a.data->begin(); i < a.data->end(); i++, r++) {
        mul += (doubleWord) *(i) * (doubleWord) b;
        *(r) = mul;
        mul >>= wordSize;
    }
    (*r) = mul;
    return res;
}

big_integer &big_integer::operator/=(big_integer const &rhs) {

    if (rhs == 0) {
        throw std::runtime_error("divide by zero");
    }
    if (*(this) == 0) {
        return *this;
    }

    *this = Div(*(this), rhs).quotient;
    normailze();
    //mpz_tdiv_q(mpz, mpz, rhs.mpz);

    return *this;
}

big_integer &big_integer::operator%=(big_integer const &rhs) {
    if (rhs == 0) {
        throw std::runtime_error("divide by zero");
    }
    if (*(this) == 0) {
        return *this;
    }

    *this = Div(*(this), rhs).remainder;
    //remainder/mpz_tgreaterdiv_r(mpz, mpz, rhs.mpz);
    normailze();
    return *this;
}

big_integer &big_integer::operator&=(big_integer const &rhs) {
    singlWord SingleByte = (singlWord) signByteArray[(*(data->end() - 1) & 1 << (wordSize - 1) ? 1 : 0)];
    data->resize(std::max(data->end() - data->begin(), rhs.data->end() - rhs.data->begin()), SingleByte);
    SingleByte = (singlWord) signByteArray[(*(rhs.data->end() - 1) & 1 << (wordSize - 1) ? 1 : 0)];
    DataType::iterator thisData = data->begin(), rhsData = rhs.data->begin();
    for (; thisData < data->end(); thisData++) {
        *(thisData) = *(thisData) & (rhsData < rhs.data->end() ? *(rhsData++) : SingleByte);
    }
    return *this;
}

big_integer &big_integer::operator|=(big_integer const &rhs) {
    singlWord SingleByte = (singlWord) signByteArray[(*(data->end() - 1) & 1 << (wordSize - 1) ? 1 : 0)];
    data->resize(std::max(data->end() - data->begin(), rhs.data->end() - rhs.data->begin()), SingleByte);
    SingleByte = (singlWord) signByteArray[(*(rhs.data->end() - 1) & 1 << (wordSize - 1) ? 1 : 0)];
    DataType::iterator thisData = data->begin(), rhsData = rhs.data->begin();
    for (; thisData < data->end(); thisData++) {
        *(thisData) = *(thisData) | (rhsData < rhs.data->end() ? *(rhsData++) : SingleByte);
    }
    return *this;
}

big_integer &big_integer::operator^=(big_integer const &rhs) {
    singlWord SingleByte = (singlWord) signByteArray[(*(data->end() - 1) & 1 << (wordSize - 1) ? 1 : 0)];
    data->resize(std::max(data->end() - data->begin(), rhs.data->end() - rhs.data->begin()), SingleByte);
    SingleByte = (singlWord) signByteArray[(*(rhs.data->end() - 1) & 1 << (wordSize - 1) ? 1 : 0)];
    DataType::iterator thisData = data->begin(), rhsData = rhs.data->begin();
    for (; thisData < data->end(); thisData++) {
        *(thisData) = *(thisData) ^ (rhsData < rhs.data->end() ? *(rhsData++) : SingleByte);
    }
    return *this;
}

big_integer &big_integer::operator<<=(const int &rhs) {
    doubleWord rhsby = rhs / wordSize, rhsbi = rhs % wordSize;
    DataType *resData = new DataType((singlWord) data->size() + rhsby + 1);

    doubleWord shift = 0;
    DataType::iterator thisData = data->begin(), resultData = resData->begin() + rhsby;
    for (; thisData < data->end();) {
        shift = (doubleWord) shift | (doubleWord) *(thisData++) << rhsbi;
        *(resultData++) = shift;
        shift >>= wordSize;
    }
    shift = shift | signByteArray[(*(data->end() - 1) & 1 << (wordSize - 1) ? 1 : 0)] << rhsbi;
    if (shift != 0) {
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

big_integer &big_integer::operator>>=(const int &rhs) {
    doubleWord rhsby = rhs / wordSize, rhsbi = rhs % wordSize;
    DataType *resData = new DataType((data->size() > rhsby ? (singlWord) data->size() - rhsby : 1));

    doubleWord shift = 0;
    DataType::iterator thisData = data->end() - 1, resultData = resData->end() - 1;
    shift = (doubleWord) signByteArray[(*(data->end() - 1) & 1 << (wordSize - 1) ? 1 : 0)] << wordSize;
    if (thisData < data->begin() + rhs / wordSize) {
        *(resultData) = signByteArray[(*(data->end() - 1) & 1 << (wordSize - 1) ? 1 : 0)];
    }
    for (; thisData >= data->begin() + rhs / wordSize;) {
        shift = shift | *(thisData--);
        *(resultData--) = shift >> rhsbi;
        shift <<= wordSize;
    }

    delete data;
    data = resData;
    return *this;
}

big_integer big_integer::operator+() const {
    return *this;
}

big_integer big_integer::operator-() const {
    big_integer r = big_integer(0) - (*this);
    return r;
}

big_integer big_integer::operator~() const {
    big_integer res;
    res.data->resize(data->size());
    for (DataType::iterator thisData = data->begin(), resData = res.data->begin(); thisData < data->end(); thisData++, resData++) {
        *(resData) = ~*(thisData);
    }
    res.normailze();
    return res;
}

big_integer &big_integer::operator++() {
    *this += 1;
    return *this;
}

big_integer big_integer::operator++(int) {
    big_integer r = *this;
    ++*this;
    return r;
}

big_integer &big_integer::operator--() {
    *this -= 1;
    return *this;
}

big_integer big_integer::operator--(int) {
    big_integer r = *this;
    --*this;
    return r;
}

big_integer operator+(big_integer a, big_integer const &b) {
    return a += b;
}

big_integer operator-(big_integer a, big_integer const &b) {
    return a -= b;
}

big_integer operator*(big_integer a, big_integer const &b) {
    return a *= b;
}

big_integer operator/(big_integer a, big_integer const &b) {
    return a /= b;
}

big_integer operator%(big_integer a, big_integer const &b) {
    return a %= b;
}

big_integer operator&(big_integer a, big_integer const &b) {
    return a &= b;
}

big_integer operator|(big_integer a, big_integer const &b) {
    return a |= b;
}

big_integer operator^(big_integer a, big_integer const &b) {
    return a ^= b;
}

big_integer operator<<(big_integer a, int b) {
    return a <<= b;
}

big_integer operator>>(big_integer a, int b) {
    return a >>= b;
}

int8_t compare(big_integer const &a, big_integer const &b) {
    bool asign = *(a.data->end() - 1) & 1 << (wordSize - 1);
    bool bsign = *(b.data->end() - 1) & 1 << (wordSize - 1);
    if (asign && (!bsign)) {
        return -1;
    }
    if ((!asign) && bsign) {
        return 1;
    }
    DataType::iterator aData = a.data->end() - 1, bData = b.data->end() - 1;
    if (asign) {
        for (; (aData > a.data->begin()) && (*aData == MAX_SINGLWORLD); aData--);
    }
    else {
        for (; (aData > a.data->begin()) && (*aData == 0); aData--);
    }

    if (bsign) {
        for (; (bData > b.data->begin()) && (*bData == MAX_SINGLWORLD); bData--);
    }
    else {
        for (; (bData > b.data->begin()) && (*bData == 0); bData--);
    }
    if ((a.data->end() - aData) > (b.data->end() - bData)) {
        if (asign) {
            return -1;
        }
        else {
            return 1;
        }
    }
    if ((a.data->end() - aData) < (b.data->end() - bData)) {
        if (asign) {
            return 1;
        }
        else {
            return -1;
        }
    }

    //size(a)==size(b), singl a== singl b;
    while (aData >= a.data->begin()) {
        if (*aData > *bData) {
            if (asign) {
                return -1;
            }
            else {
                return 1;
            }
        }
        if (*aData < *bData) {
            if (asign) {
                return 1;
            }
            else {
                return -1;
            }
        }
        aData--;
        bData--;
    }
    return 0;
}


bool operator==(big_integer const &a, big_integer const &b) {
    return compare(a, b) == 0;
}

bool operator!=(big_integer const &a, big_integer const &b) {
    return compare(a, b) != 0;
}

bool operator<(big_integer const &a, big_integer const &b) {
    return compare(a, b) < 0;
}

bool operator>(big_integer const &a, big_integer const &b) {
    return compare(a, b) > 0;
}

bool operator<=(big_integer const &a, big_integer const &b) {
    return compare(a, b) <= 0;
}

bool operator>=(big_integer const &a, big_integer const &b) {
    return compare(a, b) >= 0;
}


big_integer::operator std::string() const{

    std::string res;
    bool sign = false;
    big_integer c = (*this), b;
    if ((*this) == 0) {
        return std::string("0");
    }
    if ((*this) < 0) {
        sign = true;
        c = ~(*this) + 1;
    }
    while (c > 0) {
        b = c % TEN;
        res = (char) (*(b.data->begin()) + '0') + res;
        c /= TEN;
    }

    if (sign) {
        res = '-' + res;
    }

    return res;
}

std::ostream &operator<<(std::ostream &s, big_integer const &a) {
    return s << std::string(a);
}


diviPair big_integer::Div(big_integer &a, const big_integer &b) {
    bool sign = (*(a.data->end() - 1) & 1 << (wordSize - 1)) ^(*(b.data->end() - 1) & 1 << (wordSize - 1));
    big_integer ao(a), bo(b);
    if ((*(a.data->end() - 1) & 1 << (wordSize - 1))) {
        ao = ~a + ONE;
    }
    if ((*(b.data->end() - 1) & 1 << (wordSize - 1))) {
        bo = ~b + ONE;
    }
    singlWord m = (ao.data->size()) - (bo.data->size()), n = (b.data->size());
    if (*(bo.data->end() - 1) == 0) {
        m++;
        n--;
    }
    diviPair res;
    if ((n >= m) && (m > 10)) {
        res = recursiveDivRem(ao, bo);
    }
    else if (0 && (m > 5) && (*(a.data->end() - 1) < *(b.data->end() - 1))) {
        res = SvobodaDiv(ao, bo);
    }
    else {
        res = insideNativeDiv(ao, bo);
    }
    if (sign) {
        res.quotient = ~res.quotient + ONE;
    }
    if (*(a.data->end() - 1) & 1 << (wordSize - 1)) {
        res.remainder = ~res.remainder + ONE;
    }
    return res;
}


diviPair big_integer::insideNativeDiv(big_integer &a, big_integer b) {
    big_integer q;
    doubleWord m = (a.data->end() - a.data->begin()) - (b.data->end() - b.data->begin()), n = (b.data->end() - b.data->begin());
    doubleWord qn;
    singlWord mov = 0;
    if (*(b.data->end() - 1) == 0) {
        m++;
        n--;
        mov = 1;
    }
    q.data->resize(m + 1);
    if (a >= ((b << (wordSize * m)))) {
        q.data->at(m) = *(a.data->end() - 1) / *(b.data->end() - 1 - mov);
        while (a < (((q.data->at(m) * b) << (wordSize * m)))) {
            q.data->at(m)--;
        }
        a -= (((q.data->at(m) * b) << (wordSize * m)));
    }
    else {
        q.data->at(m) = 0;
    }
    big_integer bufer;
    for (int64_t t = m - 1; t >= 0; t--) {

        qn = (((n + t < a.data->size() ? (doubleWord) a.data->at(n + t) << wordSize : 0)) + (n + t - 1 < a.data->size() ? (doubleWord) a.data->at(n + t - 1) : 0)) / ((doubleWord) b.data->at(n - 1));
        qn = std::min(qn, (doubleWord) signByteArray[1]);
        a -= mulLongShort((b << (wordSize * t)), qn);
        bufer = (b << (wordSize * t)) << 16;
        while (*(a.data->end() - 1) & 1 << (wordSize - 1)) {
            qn -= 1 << 16;
            a += bufer;
        }
        qn += 1 << 16;
        a -= bufer;

        bufer = (b << (wordSize * t)) << 8;
        while (*(a.data->end() - 1) & 1 << (wordSize - 1)) {
            qn -= 1 << 8;
            a += bufer;
        }
        qn += 1 << 8;
        a -= bufer;
        bufer >>= 4;
        while (*(a.data->end() - 1) & 1 << (wordSize - 1)) {
            qn -= 1 << 4;
            a += bufer;
        }
        qn += 1 << 4;
        a -= bufer;

        bufer >>= 2;
        while (*(a.data->end() - 1) & 1 << (wordSize - 1)) {
            qn -= 1 << 2;
            a += bufer;
        }
        qn += 1 << 2;
        a -= bufer;
        bufer >>= 1;
        while (*(a.data->end() - 1) & 1 << (wordSize - 1)) {
            qn -= 1 << 1;
            a += bufer;
        }
        qn += 1 << 1;
        a -= bufer;
        bufer >>= 1;
        while (*(a.data->end() - 1) & 1 << (wordSize - 1)) {
            qn -= 1;
            a += bufer;
        }
        q.data->at(t) = qn;
    }
    diviPair res;
    res.quotient = q;
    res.remainder = a;

    return res;
}



diviPair big_integer::SvobodaDiv(big_integer a, big_integer &b) {
    doubleWord m = (a.data->end() - a.data->begin()) - (b.data->end() - b.data->begin()), n = (b.data->end() - b.data->begin());
    if (*(b.data->end() - 1) == 0) {
        m++;
        n--;
    }
    big_integer k = (ONE << (wordSize * (n + 1)));
    diviPair buf = Div(k, b);
    k = buf.quotient;
    big_integer q;
    q.data->resize(m);
    if (buf.remainder > ZERRO) {
        k += ONE;
    }
    big_integer b1 = k * b;
    for (singlWord i = m - 1; i > 0; i--) {
        q.data->at(i) = (a.data->size() < n + i ? a.data->at(n + i) : 0);
        a -= mulLongShort(b1, q.data->at(i)) << (wordSize * (i - 1));
        while (*(a.data->end() - 1) & 1 << (wordSize - 1)) {
            q.data->at(i)--;
            a += b1 << (wordSize * (i - 1));
        }
    }
    diviPair res;
    res.quotient = b;
    res.quotient.data->resize(m);
    res.quotient >>= wordSize;
    res.quotient <<= wordSize;
    buf = insideNativeDiv(a, b);
    res.quotient = res.quotient * k + q.data->at(0);
    res.remainder = buf.remainder;
    return res;
}

diviPair big_integer::recursiveDivRem(big_integer a, const big_integer &b) {
    big_integer q, b1, b0, a_, a__;
    singlWord m = (a.data->size()) - (b.data->size()), n = b.data->size();
    if (*(b.data->end() - 1) == 0) {
        m++;
        n--;
    }
    if ((m < 2) || (m > n)) {
        return insideNativeDiv(a, b);
    }
    singlWord k = m / 2;
    b1 = b >> (wordSize * k);
    b0 = b;
    b0.data->resize(k);
    diviPair res0, res1;
    res1 = recursiveDivRem(a >> (wordSize * 2 * k), b1);
    res1.quotient.absNormailze();
    res1.remainder.absNormailze();
    a.data->resize(k);
    a_ = (res1.remainder << (wordSize * 2 * k)) + a - res1.quotient * b0 << (wordSize * k);
    big_integer bufer = b << (wordSize * k);
    while (*(a_.data->end() - 1) & 1 << (wordSize - 1)) {
        res1.quotient--;
        a_ += bufer;
    }
    res0 = recursiveDivRem(a_ >> (wordSize * k), b1);
    res0.quotient.absNormailze();
    res0.remainder.absNormailze();
    a_.data->resize(k);
    a__ = (res0.remainder << (wordSize * k)) + a_ - res0.quotient * b0;
    while (*(a__.data->end() - 1) & 1 << (wordSize - 1)) {
        res0.quotient--;
        a__ += b;
    }
    diviPair res;
    res.quotient = (res1.quotient << (wordSize * k)) + res0.quotient;
    res.remainder = a__;
    res.quotient.absNormailze();
    res.remainder.absNormailze();
    return res;
}

std::istream &operator>>(std::istream &input, big_integer &a) {
    std::string s;
    input >> s;
    big_integer b(s);
    a = b;
    return input;
}

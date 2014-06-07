#include "big_integer.h"

#include <cstring>
#include <stdexcept>

big_integer::big_integer()
{
    data = new DataType(1);
    data->push_back(0);
}

big_integer::big_integer(big_integer const& other)
{
    data = new DataType(other.data->size());
    std::copy(other.data->begin(),other.data->end(),data->begin());
}

big_integer::big_integer(int a)
{
    data = new DataType(1);
    data->push_back(a);
}

big_integer::big_integer(std::string const& str)
{
    /*if (mpz_init_set_str(mpz, str.c_str(), 10))
    {
        mpz_clear(mpz);
        throw std::runtime_error("invalid string");
    }*/
}

big_integer::~big_integer()
{
    delete data;
}

big_integer& big_integer::operator=(big_integer const& other)
{
    data->resize(other.data->size());
    std::copy(other.data->begin(),other.data->end(),data->begin());
    return *this;
}

big_integer& big_integer::operator+=(big_integer const& rhs)
{
    uint32_t singleByte = *(data->end()-1)>>31, i=0;
    uint64_t summ=0;
    data->resize(std::max(data->size(),rhs.data->size())+1,singleByte);
    singleByte = *(rhs.data->end()-1)>>31;
    for(;i<rhs.data->size()-1;i++)
    {
        summ += (uint64_t)*(rhs.data->begin()+i)+(uint64_t)*(data->begin()+i);
        *(data->begin()+i) = (uint32_t) summ;
        summ >>= 31;
    }
    for(;i<data->size()-1;i++)
    {
        summ += (uint64_t) singleByte + (uint64_t)*(data->begin()+i);
        *(data->begin() + i) = (uint32_t) summ;
        summ >>= 31;
    }
    *(data->begin()+i) = summ;
    return *this;
}

big_integer& big_integer::operator-=(big_integer const& rhs)
{
    //mpz_sub(mpz, mpz, rhs.mpz);
    return *this;
}

big_integer& big_integer::operator*=(big_integer const& rhs)
{
    //mpz_mul(mpz, mpz, rhs.mpz);
    return *this;
}

big_integer& big_integer::operator/=(big_integer const& rhs)
{
    //mpz_tdiv_q(mpz, mpz, rhs.mpz);
    return *this;
}

big_integer& big_integer::operator%=(big_integer const& rhs)
{
    //mpz_tdiv_r(mpz, mpz, rhs.mpz);
    return *this;
}

big_integer& big_integer::operator&=(big_integer const& rhs)
{
    //mpz_and(mpz, mpz, rhs.mpz);
    return *this;
}

big_integer& big_integer::operator|=(big_integer const& rhs)
{
    //mpz_ior(mpz, mpz, rhs.mpz);
    return *this;
}

big_integer& big_integer::operator^=(big_integer const& rhs)
{
    //mpz_xor(mpz, mpz, rhs.mpz);
    return *this;
}

big_integer& big_integer::operator<<=(int rhs)
{
    //mpz_mul_2exp(mpz, mpz, rhs);
    return *this;
}

big_integer& big_integer::operator>>=(int rhs)
{
    //mpz_div_2exp(mpz, mpz, rhs);
    return *this;
}

big_integer big_integer::operator+() const
{
    return *this;
}

big_integer big_integer::operator-() const
{
    big_integer r;
    //mpz_neg(r.mpz, mpz);
    return r;
}

big_integer big_integer::operator~() const
{
    big_integer r;
    //mpz_com(r.mpz, mpz);
    return r;
}

big_integer& big_integer::operator++()
{
    //mpz_add_ui(mpz, mpz, 1);
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
    //mpz_sub_ui(mpz, mpz, 1);
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
    return 0;//mpz_cmp(a.mpz, b.mpz) == 0;
}

bool operator!=(big_integer const& a, big_integer const& b)
{
    return 0;//mpz_cmp(a.mpz, b.mpz) != 0;
}

bool operator<(big_integer const& a, big_integer const& b)
{
    return 0;//mpz_cmp(a.mpz, b.mpz) < 0;
}

bool operator>(big_integer const& a, big_integer const& b)
{
    return 0;//mpz_cmp(a.mpz, b.mpz) > 0;
}

bool operator<=(big_integer const& a, big_integer const& b)
{
    return 0;//mpz_cmp(a.mpz, b.mpz) <= 0;
}

bool operator>=(big_integer const& a, big_integer const& b)
{
    return 0;//mpz_cmp(a.mpz, b.mpz) >= 0;
}

std::string to_string(big_integer const& a)
{
    //char* tmp = mpz_get_str(NULL, 10, a.mpz);
    std::string res;// = tmp;

    //void (*freefunc)(void*, size_t);
    //mp_get_memory_functions (NULL, NULL, &freefunc);

    //freefunc(tmp, strlen(tmp) + 1);

    return res;
}

std::ostream& operator<<(std::ostream& s, big_integer const& a)
{
    return s << to_string(a);
}

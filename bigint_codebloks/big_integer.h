#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include <climits>
#include <vector>
#include <complex>
#include <algorithm>
#include <stdint.h>

typedef std::vector<uint32_t> DataType;
const uint32_t signByteArray[2] = {0,4294967295};
typedef std::complex<double> complexDouble;
typedef std::vector<complexDouble> vectorComplexDouble;



struct big_integer
{
    big_integer();
    big_integer(big_integer const& other);
    big_integer(DataType::iterator rhsBegin,DataType::iterator rhsEnd);
    big_integer(int32_t a);
    explicit big_integer(std::string const& str);
    ~big_integer();

    big_integer& normailze();

    big_integer& operator=(big_integer const& other);

    big_integer& operator+=(big_integer const& rhs);
    big_integer& operator-=(big_integer const& rhs);
    big_integer& operator*=(big_integer const& rhs);
    big_integer& operator/=(big_integer const& rhs);
    big_integer& operator%=(big_integer const& rhs);

    big_integer& operator&=(big_integer const& rhs);
    big_integer& operator|=(big_integer const& rhs);
    big_integer& operator^=(big_integer const& rhs);

    big_integer& operator<<=(int rhs);
    big_integer& operator>>=(int rhs);

    big_integer operator+() const;
    big_integer operator-() const;
    big_integer operator~() const;

    big_integer& operator++();
    big_integer operator++(int);

    big_integer& operator--();
    big_integer operator--(int);

    friend bool operator==(big_integer const& a, big_integer const& b);
    friend bool operator!=(big_integer const& a, big_integer const& b);
    friend bool operator<(big_integer const& a, big_integer const& b);
    friend bool operator>(big_integer const& a, big_integer const& b);
    friend bool operator<=(big_integer const& a, big_integer const& b);
    friend bool operator>=(big_integer const& a, big_integer const& b);

    friend std::string to_string(big_integer const& a);

public:
    DataType *data;
};

big_integer operator+(big_integer a, big_integer const& b);
big_integer operator-(big_integer a, big_integer const& b);
big_integer operator*(big_integer a, big_integer const& b);
big_integer operator/(big_integer a, big_integer const& b);
big_integer operator%(big_integer a, big_integer const& b);

big_integer operator&(big_integer a, big_integer const& b);
big_integer operator|(big_integer a, big_integer const& b);
big_integer operator^(big_integer a, big_integer const& b);

big_integer operator<<(big_integer a, int b);
big_integer operator>>(big_integer a, int b);

bool operator==(big_integer const& a, big_integer const& b);
bool operator!=(big_integer const& a, big_integer const& b);
bool operator<(big_integer const& a, big_integer const& b);
bool operator>(big_integer const& a, big_integer const& b);
bool operator<=(big_integer const& a, big_integer const& b);
bool operator>=(big_integer const& a, big_integer const& b);

std::string to_string(big_integer const& a);
std::ostream& operator<<(std::ostream& s, big_integer const& a);

int8_t compare(big_integer const& a,big_integer const& b);

struct diviPair
{
    big_integer quotient;
    big_integer remainder;
};

diviPair insideNativeDiv(big_integer& a,big_integer& b);
diviPair nativeDiv(DataType::iterator aBegin,DataType::iterator aEnd,DataType::iterator bBegin,DataType::iterator bEnd);


#endif // BIG_INTEGER_H

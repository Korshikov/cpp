#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include <climits>
#include <vector>
#include <complex>
#include <algorithm>
#include <cstdint>

typedef u_int64_t doubleWord;
typedef u_int32_t singlWord;
typedef std::vector <singlWord> DataType;
u_int8_t const wordSize = 32;
const singlWord MAX_SINGLWORLD = 0xffffffff;
const singlWord signByteArray[2] = {0, MAX_SINGLWORLD};


struct diviPair;

class big_integer {
public:
    big_integer();

    big_integer(big_integer const &other);

    big_integer(int64_t a);

    explicit big_integer(std::string const &str);

    ~big_integer();

    big_integer &abs();

    big_integer &operator=(big_integer const &other);

    big_integer &operator+=(big_integer const &rhs);

    big_integer &operator-=(big_integer const &rhs);

    big_integer &operator*=(big_integer const &rhs);

    big_integer &operator/=(big_integer const &rhs);

    big_integer &operator%=(big_integer const &rhs);

    big_integer &operator&=(big_integer const &rhs);

    big_integer &operator|=(big_integer const &rhs);

    big_integer &operator^=(big_integer const &rhs);

    big_integer &operator<<=(const int &rhs);

    big_integer &operator>>=(const int &rhs);

    big_integer operator+() const;

    big_integer operator-() const;

    big_integer operator~() const;

    big_integer &operator++();

    big_integer operator++(int);

    big_integer &operator--();

    big_integer operator--(int);

    friend bool operator==(big_integer const &a, big_integer const &b);

    friend bool operator!=(big_integer const &a, big_integer const &b);

    friend bool operator<(big_integer const &a, big_integer const &b);

    friend bool operator>(big_integer const &a, big_integer const &b);

    friend bool operator<=(big_integer const &a, big_integer const &b);

    friend bool operator>=(big_integer const &a, big_integer const &b);

    friend std::string to_string(big_integer const &a);

    friend int8_t compare(big_integer const &a, big_integer const &b);

private:
    big_integer(DataType::iterator rhsBegin, DataType::iterator rhsEnd);

    DataType *data;

    big_integer &normailze();

    big_integer &absNormailze();

    big_integer mulLongShort(const big_integer &a, const singlWord &b);

    diviPair Div(big_integer &a, const big_integer &b);

    diviPair insideNativeDiv(big_integer &a, big_integer b);

    diviPair recursiveDivRem(big_integer a, const big_integer &b);

    diviPair SvobodaDiv(big_integer a, big_integer &b);

};

big_integer operator+(big_integer a, big_integer const &b);

big_integer operator-(big_integer a, big_integer const &b);

big_integer operator*(big_integer a, big_integer const &b);

big_integer operator/(big_integer a, big_integer const &b);

big_integer operator%(big_integer a, big_integer const &b);

big_integer operator&(big_integer a, big_integer const &b);

big_integer operator|(big_integer a, big_integer const &b);

big_integer operator^(big_integer a, big_integer const &b);

big_integer operator<<(big_integer a, int b);

big_integer operator>>(big_integer a, int b);

bool operator==(big_integer const &a, big_integer const &b);

bool operator!=(big_integer const &a, big_integer const &b);

bool operator<(big_integer const &a, big_integer const &b);

bool operator>(big_integer const &a, big_integer const &b);

bool operator<=(big_integer const &a, big_integer const &b);

bool operator>=(big_integer const &a, big_integer const &b);

std::string to_string(big_integer const &a);

std::ostream &operator<<(std::ostream &s, big_integer const &a);

std::istream &operator>>(std::istream &input, big_integer &a);


int8_t compare(big_integer const &a, big_integer const &b);

struct diviPair {
    big_integer quotient;
    big_integer remainder;
};


#endif // BIG_INTEGER_H

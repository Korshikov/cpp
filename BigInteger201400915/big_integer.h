#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include <climits>
#include <vector>
#include <complex>
#include <algorithm>
#include <cstdint>

typedef u_int64_t doubleWord;
typedef u_int32_t singlWord;
typedef std::vector<singlWord> DataType;
size_t const wordSize = 32;


class big_integer
{
public:
    big_integer();
    big_integer(int other);
    big_integer(int a);
    explicit big_integer(int str);
    ~big_integer();

    big_integer& operator=(big_integer const& other);

    big_integer& operator+=(big_integer const& rhs);

    big_integer& operator-=(big_integer const& rhs);
    big_integer& operator*=(big_integer const& rhs);
    big_integer& operator/=(big_integer const& rhs);
    big_integer& operator%=(big_integer const& rhs);
    big_integer& operator&=(big_integer const& rhs);

    big_integer& operator|=(big_integer const& rhs);
    big_integer& operator^=(big_integer const& rhs);
    big_integer& operator<<=(const int& rhs);

    big_integer& operator>>=(const int& rhs);
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

private:
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

int compare(big_integer const& a,big_integer const& b);


#endif // BIG_INTEGER_H
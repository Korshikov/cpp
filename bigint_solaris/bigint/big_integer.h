/* 
 * File:   big_integer.h
 * Author: delf
 *
 * Created on 15 Июнь 2014 г., 14:16
 */

#ifndef BIG_INTEGER_H
#define	BIG_INTEGER_H

#include <big_integer_data.h>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>


typedef big_integer_data dataType;

class big_integer {
public:
big_integer();
    big_integer(big_integer const& other);
    big_integer(doubleWord a);
    //explicit big_integer(std::string const& str);
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

    //friend std::string to_string(big_integer const& a);


private:
    dataType *data;
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

//std::string to_string(big_integer const& a);
//std::ostream& operator<<(std::ostream& s, big_integer const& a);

int8_t compare(big_integer const& a,big_integer const& b);

struct diviPair
{
    big_integer quotient;
    big_integer remainder;
};

diviPair insideNativeDiv(big_integer& a,big_integer& b);

#endif	/* BIG_INTEGER_H */


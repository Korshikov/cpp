/* 
 * File:   big_integer_data.h
 * Author: delf
 *
 * Created on 15 Июнь 2014 г., 14:26
 */





#ifndef BIG_INT_DATA_H
#define	BIG_INT_DATA_H

#include <vector>
#include <cstdint>
#include <stdlib.h>

typedef u_int32_t singleWord;
typedef u_int64_t doubleWord;
typedef u_int32_t indexType;
const u_int8_t wordSize = 32;
const singleWord signByteArray[2] = {0,4294967295};


class big_integer_data {
public:
    big_integer_data();
    big_integer_data(const doubleWord& rhs);
    big_integer_data(const big_integer_data& rhs);
    virtual ~big_integer_data();
    singleWord& at(const indexType& i);
    singleWord& modifideAt(const indexType& i);
    big_integer_data* connect();
    void disconnect();
    big_integer_data pice(indexType begin, indexType end);
    indexType size() const;
    big_integer_data& resize(indexType newSize);
    big_integer_data& normalize();
private:
    std::vector<singleWord> *data;
    singleWord counter;
};

#endif	/* BIG_INT_DATA_H */


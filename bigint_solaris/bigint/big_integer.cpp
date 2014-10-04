/* 
 * File:   big_integer.cpp
 * Author: delf
 * 
 * Created on 15 Июнь 2014 г., 14:16
 */

#include "big_integer.h"


big_integer::big_integer() {
    data = new dataType(0);
}

big_integer::big_integer(const big_integer& orig) {
    
}

big_integer::~big_integer() {
}


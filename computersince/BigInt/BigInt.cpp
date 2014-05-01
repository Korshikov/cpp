#include "BigInt.h"

bool BigInt::getSingleBit(){
    return number[length-1] >> sizeof(elementType);
}

elementType BigInt::getEmptyLiderElement(){
    return number[length-1] >>> sizeof(elementType);
}

BigInt::BigInt()
{
    number.push(0);
    length = 1;
}

BigInt::~BigInt()
{
    number.clear();
}



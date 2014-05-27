#include "BigInt.h"

BigInt::BigInt()
{
    data = new std::vector<vectorElement>;
    data->clear();
}

BigInt::~BigInt()
{
    delete data;
}


BigInt BigInt::operator+(BigInt const& b){

    return b;
}

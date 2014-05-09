#include "BigInt.h"

BigInt::BigInt()
{
    value.value=NULL;
    value.valueOrLen=0;
}

BigInt::BigInt(int number)
{
    value.value=NULL;
    value.valueOrLen=number;
}

BigInt::BigInt(long number)
{
    value.value=NULL;
    value.valueOrLen=number;
}

BigInt::BigInt(long long number)
{
    value.value=NULL;
    value.valueOrLen=number;
}
BigInt::~BigInt()
{
    //dtor
}

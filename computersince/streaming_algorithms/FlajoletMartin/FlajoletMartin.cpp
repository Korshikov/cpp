/*#include "FlajoletMartin.hpp"

template <typename T>
unsigned FlajoletMartin<T>::zero(T value)
{
    unsigned z=0;
    for(;!(value & 1 << z ) && (z < CHAR_BIT * sizeof value); ++z)
    {;}
    return z;
}

template <typename T>
unsigned FlajoletMartin<T>::counter(std::istream& stream)
{
    unsigned z =0;
    T buffer;
    std::hash<T> hashFunction;
    while(stream >> buffer)
    {
        z = std::max(z, zero(hashFunction(buffer)));
    }
    return (unsigned) pow(2.,z+0.5);
}*/
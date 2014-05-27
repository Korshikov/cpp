#ifndef BIGINT_H
#define BIGINT_H

#include <vector>
#include <algorithm>

typedef unsigned long long vectorElement;

class BigInt
{
    public:
        BigInt();
        virtual ~BigInt();
        BigInt operator+(BigInt const& b);
        BigInt operator-(BigInt const& b);
        BigInt operator*(BigInt const& b);
        BigInt operator/(BigInt const& b);
        BigInt operator%(BigInt const& b);
    protected:
        std::vector<vectorElement> *data;
    private:
};

#endif // BIGINT_H

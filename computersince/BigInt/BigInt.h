#ifndef BIGINT_H
#define BIGINT_H
#include <climits>
#include <string>
#include <vector>

typedef long long int elementType;

class BigInt
{
    public:
        /** Default constructor */
        BigInt();
        /** Default destructor */
        virtual ~BigInt();

        bool getSingleBit();

    protected:
    private:
        long long int length;
        vector<elementType> number;

        elementType getEmptyLiderElement();


};

#endif // BIGINT_H

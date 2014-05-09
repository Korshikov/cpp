#ifndef BIGINT_H
#define BIGINT_H


class BigInt
{
    public:
        BigInt();
        virtual ~BigInt();
    protected:
        union BigIntValue{
            long long valueOrLen; //if number < LLONG_MAX - value else array len;
            long long* value;
        };
        BigIntValue value;
    private:
};

#endif // BIGINT_H

#ifndef SMALLVECTOR_H
#define SMALLVECTOR_H
#include <vector>
#include <cstdint>

class smallVector
{
    public:
        smallVector(const uint32_t& a);
        virtual ~smallVector();
    protected:
    private:
        uint32_t countConnect;
        std::vector<uint32_t> *data;
};

#endif // SMALLVECTOR_H

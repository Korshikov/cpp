#ifndef MATRICES_H
#define MATRICES_H
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>





class matrices
{
    public:
        matrices(size_t x,size_t y);
        matrices(char* file_name);
        void print();
        friend matrices operator+ (const matrices &a, const matrices &b);
        friend matrices operator* (const matrices &a, const matrices &b);
    protected:
        std::vector<double> data;
        size_t x;
        size_t y;
    private:
};

#endif // MATRICES_H

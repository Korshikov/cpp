#include <cstdio>

using namespace std;

struct Matrix2_2{
    long long matrix[2][2];

    Matrix2_2(){
        matrix[0][0]=1;
        matrix[0][1]=0;
        matrix[1][0]=0;
        matrix[1][1]=1;
    }

    Matrix2_2(long long a,long long b,long long c,long long d){
        matrix[0][0]=a;
        matrix[0][1]=b;
        matrix[1][0]=c;
        matrix[1][1]=d;
    }

    Matrix2_2& operator=(const Matrix2_2& right) {
        if (this == &right) {
            return *this;
        }
        matrix[0][0] = right.matrix[0][0];
        matrix[0][1] = right.matrix[0][1];
        matrix[1][0] = right.matrix[1][0];
        matrix[1][1] = right.matrix[1][1];
        return *this;
    }

    Matrix2_2 const operator*(Matrix2_2 a){
        return Matrix2_2(matrix[0][0]*a.matrix[0][0]+matrix[0][1]*a.matrix[1][0],
                        matrix[0][0]*a.matrix[0][1]+matrix[0][1]*a.matrix[1][1],
                        matrix[1][0]*a.matrix[0][0]+matrix[1][1]*a.matrix[1][0],
                        matrix[1][0]*a.matrix[0][1]+matrix[1][1]*a.matrix[1][1]
                         );
    }

    Matrix2_2 const& operator*=(Matrix2_2& right){
        Matrix2_2 result;
        result.matrix[0][0]=matrix[0][0]*right.matrix[0][0]+matrix[0][1]*right.matrix[1][0];
        result.matrix[0][1]=matrix[0][0]*right.matrix[0][1]+matrix[0][1]*right.matrix[1][1];
        result.matrix[1][0]=matrix[1][0]*right.matrix[0][0]+matrix[1][1]*right.matrix[1][0];
        result.matrix[1][1]=matrix[1][0]*right.matrix[0][1]+matrix[1][1]*right.matrix[1][1];
        matrix[0][0] = result.matrix[0][0];
        matrix[0][1] = result.matrix[0][1];
        matrix[1][0] = result.matrix[1][0];
        matrix[1][1] = result.matrix[1][1];
        return *this;
    }


};

int main()
{
    Matrix2_2 q(0,1,1,1),e,r;
    r = e*q;
    printf("%lld %lld\n%lld %lld",r.matrix[0][0],r.matrix[0][1],r.matrix[1][0],r.matrix[1][1]);

    return 0;
}

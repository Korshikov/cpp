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

    Matrix2_2& operator=(const int& right) {
        matrix[0][0] = right;
        matrix[0][1] = 0;
        matrix[1][0] = 0;
        matrix[1][1] = right;
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

    Matrix2_2 const& operator%=(const long long& right){
        matrix[0][0] %= right;
        matrix[0][1] %= right;
        matrix[1][0] %= right;
        matrix[1][1] %= right;
        return *this;
    }

};

template< typename T >
T binPower (T a, long long n) {
    T res = 1;
    while (n) {
        if (n & 1)
            res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

template< typename T >
T binPowerByMod (T a, long long n, long long r) {
    T res;
    res =1;
    while (n) {
        a %= r;
        if (n & 1) {
            res *= a;
        }
        a *= a;
        n >>= 1;
        res %= r;
    }
    return res;
}

int main()
{
    const Matrix2_2 q(0,1,1,1);
    Matrix2_2 fib;
    long long n,r;
    scanf("%lld %lld",&n,&r);

    fib =  binPowerByMod<Matrix2_2>(q, n+1, r);
    printf("%lld",fib.matrix[0][0]);


    //printf("%lld %lld\n%lld %lld",r.matrix[0][0],r.matrix[0][1],r.matrix[1][0],r.matrix[1][1]);

    return 0;
}

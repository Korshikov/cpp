#include <cstdio>


using namespace std;


struct Matrix2_2 {
    long long matrix[2][2];

    Matrix2_2() {
        matrix[0][0] = 1;
        matrix[0][1] = 0;
        matrix[1][0] = 0;
        matrix[1][1] = 1;
    }

    Matrix2_2(long long a, long long b, long long c, long long d) {
        matrix[0][0] = a;
        matrix[0][1] = b;
        matrix[1][0] = c;
        matrix[1][1] = d;
    }

    Matrix2_2 &operator=(const Matrix2_2 &right) {
        if (this == &right) {
            return *this;
        }
        matrix[0][0] = right.matrix[0][0];
        matrix[0][1] = right.matrix[0][1];
        matrix[1][0] = right.matrix[1][0];
        matrix[1][1] = right.matrix[1][1];
        return *this;
    }

    Matrix2_2 &operator=(const int &right) {
        matrix[0][0] = right;
        matrix[0][1] = 0;
        matrix[1][0] = 0;
        matrix[1][1] = right;
        return *this;
    }

    Matrix2_2 const operator*(Matrix2_2 a) {
        return Matrix2_2(matrix[0][0] * a.matrix[0][0] + matrix[0][1] * a.matrix[1][0],
                matrix[0][0] * a.matrix[0][1] + matrix[0][1] * a.matrix[1][1],
                matrix[1][0] * a.matrix[0][0] + matrix[1][1] * a.matrix[1][0],
                matrix[1][0] * a.matrix[0][1] + matrix[1][1] * a.matrix[1][1]
        );
    }

    Matrix2_2 const &operator*=(Matrix2_2 &right) {
        Matrix2_2 result;
        result.matrix[0][0] = matrix[0][0] * right.matrix[0][0] + matrix[0][1] * right.matrix[1][0];
        result.matrix[0][1] = matrix[0][0] * right.matrix[0][1] + matrix[0][1] * right.matrix[1][1];
        result.matrix[1][0] = matrix[1][0] * right.matrix[0][0] + matrix[1][1] * right.matrix[1][0];
        result.matrix[1][1] = matrix[1][0] * right.matrix[0][1] + matrix[1][1] * right.matrix[1][1];
        matrix[0][0] = result.matrix[0][0];
        matrix[0][1] = result.matrix[0][1];
        matrix[1][0] = result.matrix[1][0];
        matrix[1][1] = result.matrix[1][1];
        return *this;
    }

    Matrix2_2 const &operator%=(const long long &right) {
        matrix[0][0] %= right;
        matrix[0][1] %= right;
        matrix[1][0] %= right;
        matrix[1][1] %= right;
        return *this;
    }

};

template<typename T>
T binPower(T a, long long n) {
    T res;
    while (n) {
        if (n & 1)
            res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

const Matrix2_2 q(0, 1, 1, 1);


long long fib(int a) {
    Matrix2_2 fib;
    fib =  binPower<Matrix2_2>(q, a+1);
    return fib.matrix[0][0];
}

int main()
{
    int n;
    scanf("%d",&n);

    //cin >> n;
    //cout << d << endl;
    printf("%lld",fib(n+1));

    return 0;
}

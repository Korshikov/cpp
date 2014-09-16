#include <iostream>
#include "fib.hpp"

using namespace std;

int main()
{
    int n;
    //scanf("%d",&n);

    cin >> n;

    long long d = fib(n);
    cout << d << endl;
    //printf("%lld",fib(n));

    return 0;
}

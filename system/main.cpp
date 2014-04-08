#include <iostream>

using namespace std;

int main()
{
    int a,b,p,r,q=1;
    r=0;

    cin >> a >>p;

    while (a>0)
    {
        b=a%p;
        a/=p;
        r+=b*q;
        q*=10;
    }

    cout << r << endl;
    return 0;
}

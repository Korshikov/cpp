#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    freopen("product.in","r",stdin);
    freopen("product.out","w+",stdout);

    long long int a,b;
    scanf("%lld %lld",&a,&b);
 //   cin >> a >> b ;
    printf("%lld",a*b);
    //cout << a*b;

    fclose(stdout);
    fclose(stdin);
    return 0;
}

#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cmath>

using namespace std;



unsigned long long int C(unsigned long n,unsigned long k,unsigned long long m)
{
    double res= 1;
    for(unsigned i=1;i<=k;++i)
    {
        res *= ((n-k+i)/i);
        res=fmod(res,m);
    }
    return (unsigned long long) res + 0.1;
}

unsigned long int catalan(unsigned int n,unsigned long int m)
{
    return (C(2*n,n,m*(n+1llu))/(n+1))%m;
    /*if(n==0)
    {
        return 1;
    }
    if(temp[n]==0)
    {
        unsigned long long t=0;
        for(unsigned i=0;i<n;i++)
        {
            t+=catalan(i,m)*catalan(n-i-1,m);
            t%=m;
        }
        temp[n]=t;
    }
    return temp[n];
    //unsigned long long  t=((((4ll*n-2)*(catalan(n-1,m)))/(n+1)));
//    return t%(m<<2);*/


}

int main()
{
    freopen("catalan.in","r",stdin);
    //freopen("catalan.out","w+",stdout);


    unsigned int n;
    unsigned long int m;
    scanf("%u %lu",&n,&m);


    printf("%lu",catalan(n,m));
    printf("\n%llu",C(2*n,n,m));

    fclose(stdin);
    fclose(stdout);
    return 0;
}

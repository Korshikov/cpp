#include <cstdio>
#include <cstdlib>
#include <climits>

using namespace std;

unsigned long int temp[1023];

unsigned long int catalan(unsigned int n,unsigned long int m)
{
    if(m==1)
    {
        return 0;
    }
    if(n==0)
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
//    return t%(m<<2);
}

int main()
{
    freopen("catalan.in","r",stdin);
    freopen("catalan.out","w+",stdout);


    unsigned int n;
    unsigned long int m;
    scanf("%u %lu",&n,&m);


    printf("%lu",catalan(n,m));

    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    freopen("sum0.in","r",stdin);
    freopen("sum0.out","w+",stdout);
    int n;
    
    int x,y,a0;
    scanf("%d", &n);
    scanf("%d%d%d",&x,&y,&a0);
    long long *a  = new long long[n];
    a[0] = a0;
    if(n>1)
    {
        a[1]=((x*a[0] + y)% 65536);
        for (int i = 2; i < n; i++)
        {
            a[i]=((x*a[i-1] + y)% 65536);
            a[i-1]+= a[i-2];
            
        }
        a[n-1]+=a[n-2];   
    }


    int m,z,t;
    unsigned b0,b1;
    scanf("%d%d%d%u",&m,&z,&t,&b0);

    b1 = (z*b0+t)% 1073741824;

    if(m==0)
    {
        printf("0\n");
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    
    long long s=(a[max(b0%n,b1%n)]-(min(b0%n,b1%n)==0?0:a[min(b0%n,b1%n)-1]));
    
    
    
    for(int i=1;i<m;i++)
    {
        b0 = (z*b1+t)% 1073741824;
        b1 = (z*b0+t)% 1073741824;
        s+= (a[max(b0%n,b1%n)]-(min(b0%n,b1%n)==0?0:a[min(b0%n,b1%n)-1]));
        //printf("%u %u\n", b0%n,b1%n );
    }

    printf("%lld\n",s);

    fclose(stdin);
    fclose(stdout);
    return 0;
}

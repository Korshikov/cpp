#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    int n,m,p,q,t;
    int nr,mr;
    for(int i=0;i<T;i++){
        scanf("%d %d %d %d %d",&n,&m,&p,&q,&t);
        nr = t/p;
        mr = t/q;
        if(m%mr==0&&n%nr==0){
            printf("%d",m/mr+n/nr);
        }else
        if((m%mr)*q+(n%nr)*p<=t){
            printf("%d\n", m/mr+n/nr+1);
        }else
        {
            printf("%d\n", m/mr+n/nr+2);
        }

    }
    return 0;
}

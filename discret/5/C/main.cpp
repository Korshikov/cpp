#include <cstdio>
#include <cstdlib>

using namespace std;

int n,k;
long long m,coose_memory[31][31];


long long coose(int n, int k)
{
    if((n==k)||(k==0))
        return 1;
    if (coose_memory[n][k]!=0)
        return coose_memory[n][k];
    coose_memory[n][k]=coose(n-1,k-1)+coose(n-1,k);
    return coose_memory[n][k];
}

void gen()
{
    int temp=1;
    for(int i=0;i<k;i++)
    {
        while(m>=coose(n-temp,k-i-1))
        {
            m-=coose(n-temp,k-i-1);
            temp++;
        }
        printf("%d ",temp++);
    }
}


int main() {
    freopen("num2choose.in","r",stdin);
    freopen("num2choose.out","w+",stdout);

    scanf("%d %d %lld",&n,&k,&m);

    gen();

    return 0;
}

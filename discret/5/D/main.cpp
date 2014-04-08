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
    int temp=1,bufer;
    for(int i=0;i<k;i++)
    {
        scanf("%d",&bufer);
        while(temp<bufer)
        {
            m+=coose(n-temp,k-i-1);
            temp++;
        }
        temp++;
    }
}


int main() {
    freopen("choose2num.in","r",stdin);
    freopen("choose2num.out","w+",stdout);

    scanf("%d %d",&n,&k);

    gen();

    printf("%lld",m);

    return 0;
}

#include <cstdio>
#include <cstdlib>

using namespace std;

int n,razb[20];
long long k,factorial_memory[20];
bool used[20];

long long factorial(int n)
{
    if(n==0)
        return 1;
    if (factorial_memory[n]!=0)
        return factorial_memory[n];
    factorial_memory[n]=factorial(n-1)*n;
    return factorial_memory[n];
}

int num_by_prem(int n)
{
    int i,k=0;
    for(i=1;i<n;i++)
        if(!used[i])
            k++;
    used[n]=true;
    return k;
}

void gen()
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",&razb[i]);
        k+= factorial(n-i-1)*num_by_prem(razb[i]);
    }
}


int main() {
    freopen("perm2num.in","r",stdin);
    freopen("perm2num.out","w+",stdout);

    scanf("%d",&n);

    gen();

    printf("%lld",k);

    return 0;
}

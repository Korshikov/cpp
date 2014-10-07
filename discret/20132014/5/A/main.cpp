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

int perm_by_num(int n)
{
    int i,k=0;
    for(i=1;k<=n;)
        if(!used[i++])
            k++;
    used[--i]=true;
    return i;
}

void gen()
{
    for(int i=0;i<n;i++)
    {
        razb[i]=perm_by_num(k/factorial(n-i-1));
        k%=factorial(n-i-1);
        printf("%d ",razb[i]);
    }
}


int main() {
    freopen("num2perm.in","r",stdin);
    freopen("num2perm.out","w+",stdout);

    scanf("%d %lld",&n ,&k);

    gen();

    return 0;
}

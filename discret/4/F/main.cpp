#include <cstdio>
#include <cstdlib>

using namespace std;

int n,razb[10];

void print(int levl=0)
{
    for(int i=0;i<levl;i++)
        printf("%d ",razb[i]);
    printf("\n");
}

void gen(int levl=1, int prev=0)
{
    if (levl>n)
        return;
    for(int i=prev+1;i<=n;i++)
    {
        razb[levl-1] = i;
        print(levl);
        gen(levl+1,i);
    }
}


int main() {
    freopen("subsets.in","r",stdin);
    freopen("subsets.out","w+",stdout);

    scanf("%d", &n);

    print();
    gen();

    return 0;
}

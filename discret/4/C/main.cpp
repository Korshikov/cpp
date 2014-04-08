#include <cstdio>
#include <cstdlib>

using namespace std;

int n,k,soch[16];

void print(int levl=0)
{
    if(levl==k)
    {
        for(int i=0;i<k;i++)
        printf("%d ",soch[i]);
        printf("\n");
        return;
    }
    for(int i=(levl>0?soch[levl-1]+1:1); i < n-k+levl+2; i++)
    {
        soch[levl]=i;
        print(levl+1);
    }
}


int main()
{
    freopen("choose.in","r",stdin);
    freopen("choose.out","w+",stdout);

    scanf("%d %d",&n,&k);

    print();

    return 0;
}

#include <cstdio>
#include <cstdlib>

using namespace std;

int n,open,balans;
bool str[20];

void print(int levl=0)
{
    if((open==n))
    {
        for(int i=0;i<levl;i++)
            if(str[i])
                printf("(");
            else
                printf(")");
        for(int i=levl;i<2*n;i++)
            printf(")");
        printf("\n");
        return;
    }
    str[levl]=true;
    open++;
    balans++;
    print(levl+1);
    open--;
    balans--;
    if(balans>0)
    {
        balans--;
        str[levl]=false;
        print(levl+1);
        balans++;
    }
}


int main()
{
    freopen("brackets.in","r",stdin);
    freopen("brackets.out","w+",stdout);

    scanf("%d",&n);

    print();

    return 0;
}

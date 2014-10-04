#include <cstdio>
#include <cstdlib>

using namespace std;

int arra[64];

void print_array(int l)
{
    for(int i=0;i<l;i++)
    {
        printf("%d ",arra[i]);
    }
    printf("\n");
}

void _partition(int a,int l=0)
{
    if(a==0)
    {
        print_array(l);
        return;
    }
    for(int i=1;(i<=a)&&((l==0)||(i<=arra[l-1]));i++)
    {
        arra[l]=i;
        _partition(a-i,l+1);
    }
}

int main()
{
    freopen("partition.in","r",stdin);
    freopen("partition.out","w+",stdout);

    int a;
    scanf("%d",&a);
    _partition(a);


    fclose(stdout);
    fclose(stdin);
    return 0;
}

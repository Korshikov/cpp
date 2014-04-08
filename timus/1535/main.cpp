#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);

    if (n==1)
    {
        printf("1\n1");
        return 0;
    }

    if (n==2)
    {
        printf("1 2\n1 2");
        return 0;
    }

    printf("1 %d ",n);
    for (int i=2; n-3-(i-2)*2>1; i++)
        if(n-3-(i-2)*2>2)
            printf("%d %d ",i,n-i);
        else
            printf("%d ",i);
    printf("%d ",n-1);

    return 0;
}

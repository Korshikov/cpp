#include <cstdio>

using namespace std;

int main()
{
    int n,k, k2;
    long k1;
    scanf("%d %d %ld",&n,&k,&k1);
    for(int i=1; i< k;i++)
    {
        scanf("%d",&k2);
        k1 = (k1+k2)-n;
        if (k1 <= 0)
        {
            printf("0");
            return 0;
        }

    }
    printf("%ld",k1);
    return 0;
}

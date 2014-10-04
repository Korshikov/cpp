#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    freopen("sum.in","r",stdin);
    freopen("sum.out","w+",stdout);

    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d",a+b);

    fclose(stdout);
    fclose(stdin);
    return 0;
}

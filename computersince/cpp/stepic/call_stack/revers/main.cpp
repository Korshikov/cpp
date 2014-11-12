#include <cstdio>
#include <cstdlib>

using namespace std;

void revers()
{
    int a;
    scanf("%d",&a);
    if(a==0){
        return;
    }
    revers();
    printf("%d ",a);
    return;
}

int main()
{
    revers();
    return 0;
}

#include <cstdio>

using namespace std;

int main()
{
    int n,t,s,b;
    scanf("%d %d %d",&n,&t,&s);
    for(int i=0; i<n ;i++)
    {
        scanf("%d",&b);
        printf("%f ",(t+(b-s))/2.+s);
    }
    return 0;
}

#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int ar[10]={0,0,0,0,0,0,0,0,0,0};
    while(n>0){
        scanf("%d",ar);
        ar[ar[0]]++;
        n--;
    }
    n=1;
    while(n<10){
        while(ar[n]>0){
            printf("%d ",n);
            ar[n]--;
        }
        n++;
    }


    return 0;
}

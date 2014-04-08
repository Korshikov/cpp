#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>


using namespace std;

unsigned int n,k;
unsigned int start_coose[100002];

void print()
{
    for(unsigned int i=0;i<k;i++)
        printf("%u ",start_coose[i]);
}

int main() {
    freopen("nextchoose.in","r",stdin);
    freopen("nextchoose.out","w+",stdout);

    scanf("%u %u",&n,&k);
    for(unsigned int i=0;i<k;i++)
        scanf("%u",start_coose+i);

    int i=k-1;
    for(;i>-1;i--)
        if(k-i-1<n-start_coose[i])
            break;
    if(i==-1)
    {
        printf("-1");
        return 0;
    }
    for(int t=0;t<i;t++)
        printf("%u ",start_coose[t]);
    start_coose[i]++;
    printf("%u ",start_coose[i++]);
    for(;k-i>0;i++)
    {
        start_coose[i]=start_coose[i-1]+1;
        printf("%u ",start_coose[i]);
    }

    return 0;
}

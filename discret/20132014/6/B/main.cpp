#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>


using namespace std;

unsigned int n;
unsigned int start_perm[100002];

void print()
{
    for(unsigned int i=0;i<n;i++)
        printf("%u ",start_perm[i]);
}

unsigned int* minim(unsigned int* start,unsigned int* finish)
{
    unsigned int* mini=start;
    unsigned int ne_menee=*(start-1);
    while(start<finish)
    {
        if((*start<*mini)&&(*start>ne_menee))
            mini=start;
        start++;
    }
    return mini;
}

unsigned int* maxi(unsigned int* start,unsigned int* finish)
{
    unsigned int* maxim=start;
    unsigned int ne_bolee = *(start-1);
    while(start<finish)
    {
        if((*start>*maxim)&&(*start<ne_bolee))
            maxim=start;
        start++;
    }
    return maxim;
}

bool comp_po_ub(unsigned int a, unsigned int b)
{
    return a>b;
}

bool prev()
{
    int i;
    for(i=n-2;i>-1;i--)
        if(start_perm[i]>start_perm[i+1])
            break;
    if(i==-1)
    {

        for(i=0;n-i>0;i++)
            printf("0 ");
        return false;
    }
    swap(start_perm[i],*maxi(start_perm+i+1,start_perm+n));
    sort(start_perm+i+1,start_perm+n,comp_po_ub);
    print();
    return true;
}

void next(bool no_print=false)
{
    int i;
    for(i=n-2;i>-1;i--)
        if(start_perm[i]<start_perm[i+1])
            break;
    if(i==-1)
    {
        if(!no_print)
            for(i=0;n-i>0;i++)
                printf("0 ");
        return;
    }
    swap(start_perm[i],*minim(start_perm+i+1,start_perm+n));
    sort(start_perm+i+1,start_perm+n);
    if(!no_print)
        print();
}


int main() {
    freopen("nextperm.in","r",stdin);
    freopen("nextperm.out","w+",stdout);

    scanf("%u",&n);
    for(unsigned int i=0;i<n;i++)
        scanf("%u",start_perm+i);

    if(prev())
        next(true);
    printf("\n");
    next();

    return 0;
}

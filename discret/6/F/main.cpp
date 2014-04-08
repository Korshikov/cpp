#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>


using namespace std;

unsigned int n,multip[100000];

void print_zerro(int n)
{
    for(int i=0;i<n;i++)
        printf("0 ");
}



int main() {
    freopen("nextmultiperm.in","r",stdin);
    freopen("nextmultiperm.out","w+",stdout);

    scanf("%u",&n);

    int max_inv=-1;

    for(unsigned int i=0;i<n;i++)
    {
        scanf("%u",multip+i);
        if((i>0)&&(multip[i]>multip[i-1]))
            max_inv=i;
    }

    if (max_inv == -1) {
        print_zerro(n);
        return 0;
    } else {
        sort(multip+ max_inv, multip+n);
        unsigned int j=max_inv;
        for(;((multip[j] <= multip[max_inv-1])&&(j<n));j++)
            ;
        swap(multip[max_inv-1], multip[j]);
    }
    for(unsigned int i=0;i<n;i++)
        printf("%u ",multip[i]);
    return 0;
}

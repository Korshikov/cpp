#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

unsigned cur = 0;
unsigned a,b;

unsigned nextRand()
{
    cur*= a;
    cur += b;
    return cur >> 8;
    //return cur >> 28;
}

unsigned long long n[16777217];
//long long n[16];

int main() {
    freopen("fastadd.in","r",stdin);
    freopen("fastadd.out","w+",stdout);
    
    
    unsigned m,q;
    scanf("%u%u",&m,&q);
    scanf("%u%u",&a,&b);
    
    

    unsigned add;
    unsigned l;
    unsigned r;

    while(m--)
    {
        add = nextRand();
        l = nextRand();
        r = nextRand();
        if(l>r)
        {
            swap(l,r);
        }           
        n[l]+= add;
        n[r+1]-= add;
    }

    long long unsigned sum = n[0];

    //for(unsigned i = 1;i<16;i++)
    for(unsigned i = 1;i<16777217;i++)
    {
        sum += n[i] ;
        n[i] = sum;
    }
    
    sum = n[0];
    

    //for(unsigned i = 1;i<16;i++)
    for(unsigned i = 1;i<16777217;i++)
    {
        sum += n[i] ;
        n[i] = sum;
        
    }
    

    sum = 0;

    while(q--)
    {
        l = nextRand();
        r = nextRand();
        if(l>r)
        {
            swap(l,r);
        }                
        sum += n[r] - (l==0? 0: n[l-1]);
    }

    printf("%u\n",sum);

    fclose(stdin);
    fclose(stdout);
    return 0;
}

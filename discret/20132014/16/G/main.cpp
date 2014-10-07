#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>


using namespace std;

struct comp{
    int a;
    int b;

    comp(int e,int k)
    {
        a = e;
        b = k;
    }

};

vector<comp> a;
bool c[16],b[16];
unsigned n,m,k,r;

bool ch()
{
    for(int i=1;i<n;i++){
        if(b[i]<b[i-1])
        {
            printf("No");
            exit(0);
        }
    }
}


void tru()
{
    for(int i=0;i<16;i++)
    {
        b[i]=c[i];
    }
    for(int i=0;i<a.size();i++)
    {
        if(b[a[i].a]>b[a[i].b])
        {
            swap(b[a[i].a],b[a[i].b]);
        }
    }
    ch();
}

void gen(int k=0)
{
    if (k>n)
    {
        tru();
    }
    c[k]= 0;
    gen(k+1);
    c[k]= 1;
    gen(k+1);
}


int main()
{
    freopen("netcheck.in","r",stdin);
    scanf("%u %u %u",&n,&m,&k);
    int h,b;
    for(int i=0;i<k;i++)
    {
        scanf("%u",&r);
        for(int t=0;t<r;t++)
        {
            scanf("%d %d",&h,&b);
            if(h>b)
            {
                swap(h,b);
            }
            a.push_back(comp(h,b));
        }
    }
    gen(0);
    printf("Yes");



    return 0;
}

#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cmath>

using namespace std;



unsigned int mina,minb,minc,mins = UINT_MAX;

int main()
{
    freopen("refrator.in","r",stdin);
    freopen("refrator.out","w+",stdout);


    unsigned int v;
    scanf("%u",&v);

    unsigned c;
    for(unsigned a=1; a*a*a<=v;++a)
    {
        for(unsigned b=a;a*b*b<=v*2;++b)
        {
            c=v/(a*b);
            if((a*b*c==v)&&(mins>a*b+a*c+b*c))
            {
                mina=a;
                minb=b;
                minc=c;
                mins=a*b+a*c+b*c;
            }
        }
    }

    printf("%u %u %u %u",2*mins,mina,minb,minc);

    fclose(stdin);
    fclose(stdout);
    return 0;
}

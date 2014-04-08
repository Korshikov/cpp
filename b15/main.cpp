#include <cstdio>

//#define x(a) (i&(1<<a))

using namespace std;

int i,co=0;


bool x(int a)
{

    return (bool(i&(1<<a)));
}

int main()
{
    for(i = 0; i < 1024; i++)
    {
        for(int t=1; t<9;t++)
            if((x(t)!=x(t+1))&&(x(t)!=x(t+2)))
            {
                co++;
                break;
            }
    }


    printf("%d",1024-co);
    return 0;
}

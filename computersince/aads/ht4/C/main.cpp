#include <algorithm>
#include <climits>
#include <cstdio>
#include <map>

using namespace std;

const unsigned long m = 4294967296;

map< unsigned long ,unsigned> memory;

unsigned long f(long unsigned n)
{
    if(n<3)
    {
        return 1;
    }
    map<unsigned long,unsigned>::iterator i = memory.find(n);
    if (i != memory.end())
    {
        return (*i).second;
    }
    if(n&1)
    {
        memory[n]=(f((6*n)/7) + f((2*n)/3))%m;
    }
    else
    {
        memory[n]=(f(n-1) + f(n-3))%m;
    }
    
    return memory[n];
}

int main()
{
    freopen("function.in","r",stdin);
    freopen("function.out","w+",stdout);

    unsigned long n;
    scanf("%lu",&n);
    
    printf("%lu",f(n) );

    fclose(stdin);
    fclose(stdout);

    return 0;
}

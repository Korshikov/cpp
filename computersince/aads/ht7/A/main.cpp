#include <algorithm>
#include <climits>
#include <cstdio>
#include <map>

using namespace std;


int main()
{
    freopen("e2m.in","r",stdin);
    freopen("e2m.out","w+",stdout);

    unsigned long n,m;
    scanf("%lu %lu",&n,&m);
    
    int graph[n*n];

    const unsigned long nxn  = n*n;

    for(unsigned long t=0;t<nxn;++t)
    {
        graph[t] = 0;
    }

    unsigned long a,b;
    for(unsigned long t=0;t<m;++t)
    {
        scanf("%lu%lu",&a,&b);
        graph[(a-1)+n*(b-1)] = graph[(a-1)*n+(b-1)] = 1;
    }

    for(unsigned long i=0;i<n;++i)
    {
        for(unsigned long t=0;t<n;++t)
        {
            printf("%d ", graph[i*n+t]);
        }
        printf("\n");
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

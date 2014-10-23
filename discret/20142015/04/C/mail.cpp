#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <algorithm>

int n,m;
const int MAX_N = 200;
const int INF = 107374182;
int distance[MAX_N][MAX_N];


int main()
{
    std::freopen("pathsg.in","r",stdin);
    std::freopen("pathsg.out","w+",stdout);

    std::scanf("%d %d",&n,&m);
    

    for(int i= n-1; i>=0;--i)
    {
        for(int t=n-1;t>=0;--t)
        {
            distance[i][t] = INF;
        }
    }

    for(int i=n-1;i>=0;--i)
    {
        distance[i][i] = 0;
    }


    int b1,b2,b3;
    for(int i = 0; i<m;++i)
    {
        std::scanf("%d %d %d",&b1,&b2,&b3);
        distance[b1-1][b2-1] = b3;
    }

    for(int i = 0; i<n;++i)
    {
        for(int t = 0; t<n;++t)
        {
            for(int k = 0;k<n;++k)
            {
                distance[t][k] = std::min(distance[t][k],distance[t][i]+distance[i][k]);
            }
        }
    }
    
    for (int i = 0; i < n; ++i)
    {
        for (int t = 0; t < n; ++t)
        {
            std::printf("%d ",distance[i][t] );
        }
        std::printf("\n");
    }

    std::fclose(stdin);
    std::fclose(stdout);

    return 0;
}

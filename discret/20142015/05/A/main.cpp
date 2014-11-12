#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>


const int INF = INT_MAX;

struct point
{
    int x, y;
    point(int x = 0, int y = 0) : x(x), y(y) {};
    
};

int distance(point const & a,point const & b)
{
    return (a.x - b.x)*(a.x - b.x)+(a.y-b.y)*(a.y-b.y);
};


int main()
{
    std::freopen("spantree.in","r",stdin);
    std::freopen("spantree.out", "w+", stdout);
    unsigned n;
    std::scanf("%u",&n);
    
    point p[n];
    int x, y;
    
    for (unsigned i = 0; i < n; i++)
    {
        std::scanf("%d%d",&x,&y);
        p[i].x=x;
        p[i].y=y;
    }

    int dist[n];
    bool used[n];

    for(unsigned i=0;i<n;++i)
    {
        dist[i] = INF;
        used[i] = false;
    }

    dist[0] = 0;
    used[0] = true;

    int minPos=0;
    int minValue = 0;
    double ans = 0;

    for(unsigned i = 0;i<n-1;++i)
    {
        for(unsigned t=0;t<n;++t)
        {
            dist[t]=std::min(dist[t],distance(p[minPos],p[t]));
        }

        minPos = -1;
        minValue = INF;
        for(unsigned t= 0;t<n;++t)
        {
            if((!used[t])&&(dist[t]<minValue))
            {
                minPos = t;
                minValue = dist[t];
            }
        }

        if(minPos!=-1)
        {
            ans += std::sqrt(minValue);
            used[minPos] = true;
        }
    }



    std::printf("%.20f\n", ans);
	return 0;

}

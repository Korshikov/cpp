#include <cstdio>
#include <cstdlib>
#include <climits>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n,m,s;
const int MAX_N = 30000;
const long long int INF = LLONG_MAX / 4;

struct edge{
	int from;
	int to;
	long long weight;
};

int main()
{
    freopen("path.in","r",stdin);
    //freopen("path.out","w+",stdout);

    scanf("%d %d %d",&n,&m,&s);
    std::vector<edge> edges(m);
    s--;
    
    for(std::vector<edge>::iterator i=edges.begin();i != edges.end();++i)
    {
        scanf("%d %d %lld",&(*i).from,&(*i).to,&(*i).weight);
        (*i).from--;
        (*i).to--;        
    }

    vector<long long> distance(n,INF);

    distance[s] = 0;
    for (int i = 0; i < n; ++i)
    {
    	for (std::vector<edge>::iterator i = edges.begin(); i != edges.end(); ++i)
    	{
    		if ((distance[(*i).to] != -INF) &&
    			(distance[(*i).from] != -INF) &&
    			(distance[(*i).from] !=  INF) &&
    			(distance[(*i).to] > distance[(*i).from] + (*i).weight))
    		{
    			distance[(*i).to] = std::max(distance[(*i).from] + (*i).weight, -INF);
    		}
    		if(distance[(*i).from == -INF])
    		{
    			distance[(*i).to] = -INF;
    		}
    	}
    }
   
    std::vector<long long> oldDistance(n);
    std::copy(distance.begin(),distance.end(),oldDistance.begin());

	for (int i = 0; i < n; ++i)
    {
    	for (std::vector<edge>::iterator i = edges.begin(); i != edges.end(); ++i)
    	{
    		if ((distance[(*i).to] != -INF) &&
    			(distance[(*i).from] != -INF) &&
    			(distance[(*i).from] !=  INF) &&
    			(distance[(*i).to] > distance[(*i).from] + (*i).weight))
    		{
    			distance[(*i).to] = std::max(distance[(*i).from] + (*i).weight, -INF);
    		}
    		if(distance[(*i).from == -INF])
    		{
    			distance[(*i).to] = -INF;
    		}
    	}
    }

	for(vector<long long>::iterator i = distance.begin(), t = oldDistance.begin();i!=distance.end();++i,++t)
	{
		if(*i == INF)
		{
			printf("*\n");
		}
		else 
		if((*i!=*t)||(*i == -INF))
		{
			printf("-\n");
		}
		else
		{
			printf("%lld\n",*t );
		}
	}

    fclose(stdin);
    fclose(stdout);

    return 0;
}

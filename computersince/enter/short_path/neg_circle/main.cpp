#include <cstdio>
#include <cstdlib>
#include <climits>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n,m;

struct edge{
	int from;
	int to;
	long long weight;
};

int main()
{
    //freopen("circle.in","r",stdin);
    //freopen("path.out","w+",stdout);

    scanf("%d %d",&n,&m);
    std::vector<edge> edges(m);
    
    for(std::vector<edge>::iterator i=edges.begin();i != edges.end();++i)
    {
        scanf("%d %d %lld",&(*i).from,&(*i).to,&(*i).weight);
        (*i).from--;
        (*i).to--;        
    }

    vector<long long> distance(n,0);

    for (int i = 0; i < n; ++i)
    {
    	for (std::vector<edge>::iterator i = edges.begin(); i != edges.end(); ++i)
    	{
    		if (distance[(*i).to] > distance[(*i).from] + (*i).weight)
    		{
    			distance[(*i).to] = distance[(*i).from] + (*i).weight;
    		}
    	}
    }
   
    /*std::vector<long long> oldDistance(n);
    std::copy(distance.begin(),distance.end(),oldDistance.begin());*/

	
    for (int i = 0; i < n; ++i)
    {
    	for (std::vector<edge>::iterator i = edges.begin(); i != edges.end(); ++i)
    	{
    		if ((distance[(*i).to] > distance[(*i).from] + (*i).weight))
    		{
                printf("1\n");
                exit(0);
    		}
    	}
    }

	printf("0\n");

    //fclose(stdin);
    //fclose(stdout);

    return 0;
}

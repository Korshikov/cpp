#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n,m,s,f;
const int MAX_N = 2000;
const int INF = 1073741824;
vector< pair<int,int> >  graph[MAX_N];


int main()
{
    freopen("pathmgep.in","r",stdin);
    freopen("pathmgep.out","w+",stdout);

    /*scanf("%d %d",&n,&m);
    
    int bufer1,bufer2,bufer3;
 
    for(int i=0;i<m;++i)
    {
        scanf("%d %d %d",&bufer1,&bufer2,&bufer3);
        graph[bufer1-1].push_back(make_pair(bufer2-1,bufer3));
        graph[bufer2-1].push_back(make_pair(bufer1-1,bufer3));
    }*/

    scanf("%d %d %d",&n,&s,&f);
    f--;
    s--;

    for (int i = 0; i < n; ++i)
    {
    	for (int t = 0; t < n; ++t)
    	{
    		scanf("%d",&m);
    		if(m!=-1)
    		{
    			graph[i].push_back(make_pair(t,m));
    		}
    	}
    }

    vector<int> distance(n,INF);
    vector<int> parent(n);
    distance[s] = 0;
    set< pair<int,int> > queue;
	queue.insert(make_pair(distance[s],s));

	while (!queue.empty()) 
	{
		int v = queue.begin()->second;
		queue.erase(queue.begin());
 
		for (vector< pair<int,int> >::iterator i = graph[v].begin();i!=graph[v].end();++i) 
		{
			if (distance[v] + i->second < distance[i->first]) 
			{
				queue.erase (make_pair (distance[i->first], i->first));
				distance[i->first] = distance[v] + i->second;
				parent[i->first] = v;
				queue.insert (make_pair (distance[i->first], i->first));
			}
		}
	}
/*
	for(vector<int>::iterator i = distance.begin();i!=distance.end();++i)
	{
		printf("%d ",*i );
	}
*/
	printf("%d\n",(distance[f]==INF?-1:distance[f]) );

    fclose(stdin);
    fclose(stdout);

    return 0;
}

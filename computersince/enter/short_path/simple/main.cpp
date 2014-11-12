#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n,m;
const int MAX_N = 30000;
const int INF = 1073741824;
vector< pair<int,int> >  graph[MAX_N];


int main()
{
    //freopen("input","r",stdin);


    scanf("%d %d",&n,&m);
    
    int bufer1,bufer2,bufer3;
 
    for(int i=0;i<m;++i)
    {
        scanf("%d %d %d",&bufer1,&bufer2,&bufer3);
        graph[bufer1-1].push_back(make_pair(bufer2-1,bufer3));
        graph[bufer2-1].push_back(make_pair(bufer1-1,bufer3));
    }
    int s,e;
    scanf("%d %d",&s,&e);
    e--;s--;

    vector<int> distance(n,INF);
    vector<int> parent(n);
    distance[s] = 0;
    set< pair<int,int> > queue;
	queue.insert(make_pair(0,s));

	while (!queue.empty()) 
	{
		int v = queue.begin()->second;
		queue.erase (queue.begin());
 
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
	if(distance[e]!=INF)
	{
		printf("%d\n",distance[e] );
	}
	else
	{
		printf("-1\n");
	}
    

    return 0;
}

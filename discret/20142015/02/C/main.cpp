#include <cstdio>
#include <cstdlib>
#include <vector>
#include <climits>
#include <set>

using namespace std;

const int inf = 1000000000;
int n,m,start,finish;
vector<vector< pair<int,int> > > graph;
vector<int> depend;
vector<int> color;
vector<int> topsort;


void dfs(int v)
{
    color[v]= 1;
    for(vector<pair<int,int> >::iterator i=graph[v].begin();i!=graph[v].end();++i)
    {
        switch(color[i->first])
        {
        case 0:
            dfs(i->first);
            break;
        }
    }
    topsort.push_back(v);
    color[v]=2;
}



int main()
{
    freopen("shortpath.in","r",stdin);
    freopen("shortpath.out","w+",stdout);

    scanf("%d %d %d %d",&n,&m,&start,&finish);
    --start;--finish;
    depend.assign(n,inf);
    color.assign(n,0);
    for(int i=0;i<n;i++)
    {
        graph.push_back(vector< pair<int,int> >());
    }

    int bufer1,bufer2,bufer3;

    for(int i=0;i<m;++i)
    {
        scanf("%d %d %d",&bufer1,&bufer2,&bufer3);
        graph[bufer1-1].push_back(make_pair(bufer2-1,bufer3));
    }

    dfs(start);

    depend[start]=0;

    for(vector<int>::reverse_iterator i=topsort.rbegin();i!=topsort.rend();++i)
    {
        for(vector< pair<int,int> >::iterator t=graph[*i].begin();t!=graph[*i].end();++t)
        {
            if(depend[t->first]>depend[*i]+t->second)
            {
                depend[t->first]=depend[*i]+t->second;
            }
        }
    }


    if(depend[finish]==inf)
    {
        printf("Unreachable");
    }
    else
    {
        printf("%d",depend[finish]);
    }


    fclose(stdin);
    fclose(stdout);

    return 0;
}

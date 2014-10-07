#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,time=0,comp=0;
const int MAX_N = 100000;
vector<pair<int,int> >  graph[MAX_N];
vector<char> color;
vector<int> timeIn;
vector<int> up;
vector<int> bridge;
//vector<int> parent;

void dfs(int v,int insertEdge)
{
    color[v]= 1;
    timeIn[v]=time++;
    up[v] = timeIn[v];
    for(vector<pair<int,int> >::iterator i=graph[v].begin();i!=graph[v].end();++i)
    {
        if(insertEdge == (*i).second)
        {
            continue;
        }
        if((color[(*i).first]) != 0)
        {
            up[v] = min(up[v],timeIn[(*i).first]);
        }
        else
        {
            dfs((*i).first,(*i).second);
            up[v] = min(up[v],up[(*i).first]);
            if(up[(*i).first]>timeIn[v])
            {
                bridge.push_back((*i).second);
            }
        }
    }
    color[v]=2;
}


int main()
{
    freopen("bridges.in","r",stdin);
    freopen("bridges.out","w+",stdout);

    scanf("%d %d",&n,&m);
    color.assign(n,0);
    timeIn.assign(n,0);
    up.assign(n,0);
    bridge.clear();

    int bufer1,bufer2;

    for(int i=0;i<m;++i)
    {
        scanf("%d %d",&bufer1,&bufer2);
        graph[bufer1-1].push_back(make_pair(bufer2-1,i));
        graph[bufer2-1].push_back(make_pair(bufer1-1,i));
    }

    for(int i=0;i<n;++i)
    {
        if(color[i]==0)
        {
            dfs(i,-1);
        }
    }

    printf("%d \n",bridge.size());

    sort(bridge.begin(), bridge.end());

    for(vector<int>::iterator i=bridge.begin();i!=bridge.end();++i)
    {
        printf("%d ",*i+1);
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

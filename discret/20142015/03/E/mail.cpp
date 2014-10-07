#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n,m,time=0,comp=0;
const int MAX_N = 100000;
vector<pair<int,int> >  graph[MAX_N];
vector<char> color;
vector<int> timeIn;
vector<int> up;
set<int> bridge;
vector<int> components;

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
                bridge.insert((*i).second);
            }
        }
    }
    color[v]=2;
}

void dfs2(int v,int comp)
{
    color[v]=0;
    components[v]=comp;
    for(vector<pair<int,int> >::iterator i=graph[v].begin();i!=graph[v].end();++i)
    {
        if((color[(*i).first]==2)&&(!bridge.count((*i).second)))
        {
            dfs2((*i).first,comp);
        }
    }
}


int main()
{
    freopen("bicone.in","r",stdin);
    freopen("bicone.out","w+",stdout);

    scanf("%d %d",&n,&m);
    color.assign(n,0);
    timeIn.assign(n,0);
    components.assign(n,0);
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

    for(int i=0;i<n;++i)
    {
        if(color[i]==2)
        {
            dfs2(i,++comp);
        }
    }

    printf("%d\n",comp );
    for(vector<int>::iterator i= components.begin();i!=components.end();++i)
    {
        printf("%d ", *i);
    }
    /*printf("%d \n",bridge.size());

    sort(bridge.begin(), bridge.end());

    for(vector<int>::iterator i=bridge.begin();i!=bridge.end();++i)
    {
        printf("%d ",*i+1);
    }*/



    fclose(stdin);
    fclose(stdout);

    return 0;
}

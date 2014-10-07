#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n,m,time=0,comp=0;
const int MAX_N = 100000;
vector<int >  graph[MAX_N];
vector<char> color;
vector<int> timeIn;
vector<int> up;
set<int> point;
//vector<int> parent;

void dfs(int v,int parent)
{
    color[v]= 1;
    timeIn[v]=time++;
    up[v] = timeIn[v];
    int children =0;
    for(vector<int>::iterator i=graph[v].begin();i!=graph[v].end();++i)
    {
        if(parent == (*i))
        {
            continue;
        }
        if(((color[(*i)]) != 0)&&(*i!=parent))
        {
            up[v] = min(up[v],timeIn[(*i)]);
        }
        else
        {
            dfs((*i),v);
            up[v] = min(up[v],up[(*i)]);
            if((up[(*i)]>=timeIn[v])&&(parent != -1))
            {
                point.insert(v);
            }
            ++children;
        }
    }
    color[v]=2;
    if((parent==-1)&&(children>1))
    {
        point.insert(v);
    }
}



int main()
{
    freopen("points.in","r",stdin);
    freopen("points.out","w+",stdout);

    scanf("%d %d",&n,&m);
    color.assign(n,0);
    timeIn.assign(n,0);
    up.assign(n,0);
    point.clear();

    int bufer1,bufer2;

    for(int i=0;i<m;++i)
    {
        scanf("%d %d",&bufer1,&bufer2);
        graph[bufer1-1].push_back(bufer2-1);
        graph[bufer2-1].push_back(bufer1-1);
    }

    for(int i=0;i<n;++i)
    {
        if(color[i]==0)
        {
            dfs(i,-1);
        }
    }

    printf("%d \n",point.size());

    //sort(point.begin(), point.end());

    for(set<int>::iterator i=point.begin();i!=point.end();++i)
    {
        printf("%d ",*i+1);
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

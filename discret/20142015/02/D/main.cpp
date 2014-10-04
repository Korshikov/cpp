#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int n,m,time=0;
int start;
vector<vector<int> > graph;
vector<char> color;
vector<int> topsort;
vector<int> result;

void dfs(int v)
{
    color[v]= 1;
    bool lose_neber = false;
    for(vector<int>::iterator i=graph[v].begin();i!=graph[v].end();++i)
    {
        switch(color[*i])
        {
        case 0:
            dfs(*i);
            break;
        }
        if(result[*i]==-1)
        {
            lose_neber=true;
        }
    }
    color[v]=2;
    if(lose_neber)
    {
        result[v]=1;
    }
    else
    {
        result[v]=-1;
    }
}

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w+",stdout);

    topsort.clear();
    scanf("%d %d %d",&n,&m,&start);
    start--;
    color.assign(n,0);
    result.assign(n,0);
    for(int i=0;i<n;i++)
    {
        graph.push_back(vector<int>());
    }

    int bufer1,bufer2;

    for(int i=0;i<m;++i)
    {
        scanf("%d %d",&bufer1,&bufer2);
        graph[bufer1-1].push_back(bufer2-1);
    }

    dfs(start);

    if(result[start]==1)
    {
        printf("First ");
    }
    else
    {
        printf("Second ");
    }
    printf("player wins");

    fclose(stdin);
    fclose(stdout);

    return 0;
}

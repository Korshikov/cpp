#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>

using namespace std;

int n,m,time=0;
vector<vector<int> > graph;
vector<char> color;
vector<int> parent;
int start_cycle,finish_cycle;

void dfs(int v)
{
    color[v]= 1;
    for(vector<int>::iterator i=graph[v].begin();i!=graph[v].end();++i)
    {
        switch(color[*i])
        {
        case 0:
            parent[*i]=v;
            dfs(*i);
            break;
        case 1:
            //circle
            printf("YES\n");
            start_cycle = *i;
            finish_cycle = v;
            stack<int> cycle;
            for(int t=v; t!=*i;t=parent[t])
            {
                cycle.push(t);

            }
            cycle.push(*i);
            while(!cycle.empty())
            {
                printf("%d ",cycle.top()+1);
                cycle.pop();
            }

            std::exit(0);
            break;
        }
    }
    color[v]=2;
}

int main()
{
    freopen("cycle.in","r",stdin);
    freopen("cycle.out","w+",stdout);

    scanf("%d %d",&n,&m);
    color.assign(n,0);
    parent.assign(n,-1);
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

    for(int i=0;i<n;++i)
    {
        if(color[i]==0)
        {
            dfs(i);
        }
    }

    printf("NO");

    fclose(stdin);
    fclose(stdout);

    return 0;
}

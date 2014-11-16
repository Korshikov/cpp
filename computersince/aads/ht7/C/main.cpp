#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int n,m,time=0;
vector<vector<int> > graph;
vector<char> color;
//vector<int> parent;
vector<int> topsort;

void dfs(int v)
{
    color[v]= 1;
    for(vector<int>::iterator i=graph[v].begin();i!=graph[v].end();++i)
    {
        switch(color[*i])
        {
        case 0:
            dfs(*i);
            break;
        }
    }
    topsort.push_back(v);
    color[v]=2;
}

int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w+",stdout);

    topsort.clear();
    scanf("%d %d",&n,&m);
    color.assign(n,0);
    if(m!=n-1)
    {
        printf("NO\n");
        fclose(stdin);
        fclose(stdout);
        exit(0);
    }
    for(int i=0;i<n;i++)
    {
        graph.push_back(vector<int>());
    }

    int bufer1,bufer2;

    for(int i=0;i<m;++i)
    {
        scanf("%d %d",&bufer1,&bufer2);
        graph[bufer1-1].push_back(bufer2-1);
        graph[bufer2-1].push_back(bufer1-1);
    }

    dfs(0);

    for(int i=0;i<n;++i)
    {
        if(color[i]==0)
        {
            printf("NO\n");
            fclose(stdin);
            fclose(stdout);
            exit(0);
        }
    }

    printf("YES\n");
    fclose(stdin);
    fclose(stdout);

    return 0;
}

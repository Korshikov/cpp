
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n,m,time=0;
set<int> graph[200000];
vector<char> color;
vector<int> topsort;

void dfs(int v)
{
    color[v]= 1;
    for(set<int>::iterator i=graph[v].begin();i!=graph[v].end();++i)
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
    freopen("hamiltonian.in","r",stdin);
    freopen("hamiltonian.out","w+",stdout);

    topsort.clear();
    scanf("%d %d",&n,&m);
    color.assign(n,0);

    int bufer1,bufer2;

    for(int i=0;i<m;++i)
    {
        scanf("%d %d",&bufer1,&bufer2);
        graph[bufer1-1].insert(bufer2-1);
    }

    for(int i=0;i<n;++i)
    {
        if(color[i]==0)
        {
            dfs(i);
        }
    }

    for(vector<int>::reverse_iterator i=topsort.rbegin();(i+1)!=topsort.rend();++i)
    {
        if(graph[*i].find(*(i+1))==graph[*i].end())
        {
            printf("NO");
            fclose(stdin);
            fclose(stdout);

            return 0;
        }

    }

    printf("YES");

    fclose(stdin);
    fclose(stdout);

    return 0;
}

#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int n,m,time=0,comp=0;
const int MAX_N = 100000;
vector<int>  graph[MAX_N];
vector<char> color;
vector<int> component;
//vector<int> parent;

void dfs(int v,int comp)
{
    color[v]= 1;
    component[v]=comp;
    for(vector<int>::iterator i=graph[v].begin();i!=graph[v].end();++i)
    {
        if((color[*i]) == 0)
        {
            dfs(*i,comp);
        }
    }
    color[v]=2;
}


int main()
{
    freopen("components.in","r",stdin);
    freopen("components.out","w+",stdout);

    scanf("%d %d",&n,&m);
    color.assign(n,0);
    component.assign(n,0);

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
            dfs(i,++comp);
        }
    }

    printf("%d \n",comp);

    for(vector<int>::iterator i=component.begin();i!=component.end();++i)
    {
        printf("%d ",*i);
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

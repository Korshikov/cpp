#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
const int MAX_N = 100000;
vector<int >  graph[MAX_N];
vector<char> color;


//vector<int> parent;

void dfs(int v,char colorThis = -1)
{
    color[v]= colorThis;
    for(vector<int>::iterator i=graph[v].begin();i!=graph[v].end();++i)
    {
        if(color[(*i)] == 0)
        {
            dfs(*i,- colorThis);
        }
        else
        {
            if(color[v]==color[(*i)])
            {
                printf("NO");
                fclose(stdin);
                fclose(stdout);
                exit(0);
            }
        }
    }
}

int main()
{
    freopen("bipartite.in","r",stdin);
    freopen("bipartite.out","w+",stdout);

    scanf("%d %d",&n,&m);
    color.assign(n,0);
    
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

    printf("YES");


 /*   printf("%d \n",point.size());

    //sort(point.begin(), point.end());

    for(set<int>::iterator i=point.begin();i!=point.end();++i)
    {
        printf("%d ",*i+1);
    }
*/
    fclose(stdin);
    fclose(stdout);

    return 0;
}

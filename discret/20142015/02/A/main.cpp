#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

/*int n,m;
int time=0;
int* grapth;
int* color;
//int* parent;
//int* timeout;
int* topsort;

void dfs(int v)
{
    color[v]=1;
    for(int i=0;i<n;i++)
    {
        if((i!=v)&&(grapth[v*n+i]!=0))
        {
            if(color[i]==0)
            {
                dfs(i);
            }
            if(color[i]==1)
            {
                printf("-1");
                fclose(stdin);
                fclose(stdout);
                std::exit(0);
                return;
            }

        }
    }
    topsort[n-(++time)]=v;
    color[v]=2;
}


int main()
{
    freopen("topsort.in","r",stdin);
    freopen("topsort.out","w+",stdout);

    scanf("%d %d",&n,&m);
    grapth = new int[n*n];
    color = new int[n];
    //parent = new int[n];
    //timeout = new int[n];
    topsort = new int[n];
    int bufer1,bufer2;
    for(int i=0;i<n*n;i++)
    {
        grapth[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        color[i]=0;
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&bufer1,&bufer2);
        grapth[(bufer1-1)*n+(bufer2-1)]=1;

    }
    for(int i=0;time<n;i++)
    {
        if(color[i]==0)
        {
            dfs(i);
        }
    }

    //printf("Yes\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",topsort[i]+1);
    }


    fclose(stdin);
    fclose(stdout);

    delete[] grapth;
    delete[] color;
    //delete[] parent;
    delete[] topsort;

    return 0;
}
*/


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
        case 1:
            //circle
            printf("-1");
            std::exit(0);
            break;
        }
    }
    topsort.push_back(v);
    color[v]=2;
}

int main()
{
    freopen("topsort.in","r",stdin);
    freopen("topsort.out","w+",stdout);

    topsort.clear();
    scanf("%d %d",&n,&m);
    color.assign(n,0);
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

    for(vector<int>::reverse_iterator i=topsort.rbegin();i!=topsort.rend();++i)
    {
        printf("%d ",*i+1);
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

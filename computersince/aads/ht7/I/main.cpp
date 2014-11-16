#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>

using namespace std;

int n,m,time=0,comp=0;
vector<vector<int> > graph;
vector<vector<int> > rgraph;
vector<char> color;
vector<int> component;
//vector<int> parent;
vector<int> topsort;

set<pair<int,int> > conden_g;

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

void dfs2(int v,int componenta)
{
    color[v]= 1;
    for(vector<int>::iterator i=rgraph[v].begin();i!=rgraph[v].end();++i)
    {
        if(color[*i]==2)
        {
            dfs2(*i,componenta);
        }
        }

    color[v]=0;
    component[v]=componenta;
}

int main()
{
    freopen("condense2.in","r",stdin);
    freopen("condense2.out","w+",stdout);

    topsort.clear();
    scanf("%d %d",&n,&m);
    color.assign(n,0);
    component.assign(n,0);
    for(int i=0;i<n;i++)
    {
        graph.push_back(vector<int>());
        rgraph.push_back(vector<int>());
    }

    int bufer1,bufer2;

    for(int i=0;i<m;++i)
    {
        scanf("%d %d",&bufer1,&bufer2);
        graph[bufer1-1].push_back(bufer2-1);
        rgraph[bufer2-1].push_back(bufer1-1);
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
        if(color[*i]==2)
        {
            dfs2(*i,comp++);
        }
    }
    //printf("%d \n",comp);
    /*
    for(vector<int>::iterator i=component.begin();i!=component.end();++i)
    {
        printf("%d ",*i);
    }
    */

    const int com = comp;
    
    int res = 0;
    int k=0;


    for (std::vector<vector<int> >::iterator i =graph.begin(); i != graph.end(); ++i,++k)
    {
        for (std::vector<int>::iterator t = (*i).begin(); t != (*i).end(); ++t)
        {
            if((component[k]!=component[*t]))
            {
                //printf("%d %d %d %d %d\n",k,*t,component[k],component[*t],((component[k]!=component[*t])&&(conden_g[component[k]][component[*t]]==0)));
                conden_g.insert(make_pair(component[k],component[*t]));
                //conden_g[component[*t]][component[k]]==1;   
            }
        }
    }

    printf("%d\n", conden_g.size());


    fclose(stdin);
    fclose(stdout);

    return 0;
}

#include <cstdio>
#include <set>
#include <vector>

using namespace std;

bool* nvisited;
int* res;
vector< vector<int>* > graph,transgraph;
int n,m,n2;

int t=0;

void BFS(const vector< vector<int>* >& graph,int v,bool top=false){
    nvisited[v]=false|!top;
    for(unsigned i=0;i<(*graph[v]).size();i++){
        if(nvisited[(((*graph[v])[i]))]==top){
            BFS(graph,(*graph[v])[i],top);
        }

    }
    if(top){
        res[--n2]=v;
    }
}



int main()
{
    scanf("%d %d",&n,&m);
    nvisited = new bool[n];
    for(int i=0;i<n;i++){
        nvisited[i]=true;
        graph.push_back(new vector<int>);
        transgraph.push_back(new vector<int>);
    }
    int b1,b2;
    for(int i=0;i<m;i++){
        scanf("%d %d",&b1,&b2);
        (*graph[--b1]).push_back(--b2);
        (*transgraph[b2]).push_back(b1);
    }
    n2 = n;
    res = new int[n];
    for(int i =0;n2>0;i++){
        if(nvisited[i]){
            BFS(transgraph,i,true);
        }
    }

    unsigned co =0;

    for(int i=0;i<n;i++){
        if(!nvisited[res[i]]){
            BFS(graph,res[i]);
            co++;
        }
    }

    printf("%d",co);



    return 0;
}

#include <cstdio>
#include <set>
#include <vector>

using namespace std;

set<int> nvisited;
int* res;
vector< vector<int>* > graph;
int n,m,n2;

int t=0;

void BFS(int v){
    nvisited.erase(v);
    for(unsigned i=0;i<(*graph[v]).size();i++){
        if(nvisited.find(((*graph[v])[i]))!=nvisited.end()){
            BFS((*graph[v])[i]);
        }

    }
    res[--n2]=v;
}



int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        nvisited.insert(i);
        graph.push_back(new vector<int>);
    }
    int b1,b2;
    for(int i=0;i<m;i++){
        scanf("%d %d",&b1,&b2);
        (*graph[--b1]).push_back(--b2);
    }
    n2 = n;
    res = new int[n];
    while(!nvisited.empty()){
        BFS(*nvisited.begin());
    }

    for(int i=0;i<n;i++){
        printf("%d ",res[i]+1);
    }

    delete res;
    for(int i=0;i<n;i++){
        delete graph[i];
    }


    return 0;
}

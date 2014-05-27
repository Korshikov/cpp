#include <cstdio>
#include <cstdlib>
#include <set>

using namespace std;

set<int> nvisited;
int** graph;
int n,m;
int* start_t;
int* end_t;
int t=0;

void BFS(int v){
    nvisited.erase(v);
    start_t[v] = t++;
    for(int i=0;i<n;i++){
        if(graph[v][i]==1){
            if(nvisited.find(i)!=nvisited.end()){
                BFS(i);
            }else{
                if((start_t[i]<t)&&(end_t[i]==0)){
                    printf("True");
                    exit(0);
                }
            }

        }
    }
    end_t[v]=t++;
}

int main()
{
    scanf("%d %d",&n,&m);
    graph = new int*[n];
    start_t = new int[n];
    end_t = new int[n];
    for(int i=0;i<n;i++){
        nvisited.insert(i);
        graph[i] = new int[n];
        for(int t=0;t<n;t++){
            graph[i][t]=0;
        }
        start_t[i]=0;
        end_t[i]=0;
    }
    int b1,b2;
    for(int i=0;i<m;i++){
        scanf("%d %d",&b1,&b2);
        graph[--b1][--b2]=1;
    }

    while(!nvisited.empty()){
        BFS(*nvisited.begin());
    }
    printf("False");

    return 0;
}

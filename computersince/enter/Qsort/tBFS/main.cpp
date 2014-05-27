#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

queue<int> vi;
int* distans;
vector< vector<int>* > graph;
int n,m,n2;

int t=0;

void BFS(){
    int v = vi.front();
    vi.pop();
    for(unsigned i=0;i<(*graph[v]).size();i++){
        if(distans[(*graph[v])[i]]==-1){
            vi.push((*graph[v])[i]);
            distans[(*graph[v])[i]]= distans[v]+1;
        }

    }
}



int main()
{
    scanf("%d %d",&n,&m);
    distans = new int[n];
    for(int i=0;i<n;i++){
        distans[i]=-1;
        graph.push_back(new vector<int>);
    }
    int b1,b2;
    for(int i=0;i<m;i++){
        scanf("%d %d",&b1,&b2);
        (*graph[--b1]).push_back(--b2);
        (*graph[b2]).push_back(b1);
    }

    scanf("%d %d",&b1,&b2);
    vi.push(--b1);
    distans[b1]=0;
    while(!vi.empty()){
        BFS();
    }

    printf("%d",distans[--b2]);

    delete distans;
    for(int i=0;i<n;i++){
        delete graph[i];
    }


    return 0;
}

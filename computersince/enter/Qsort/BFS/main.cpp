#include <cstdio>
#include <set>

using namespace std;

int main()
{
    int n,m;
    set<int> nvisited;
    scanf("%d %d",&n,&m);
    int** graph = new int*[n];
    for(int i=0;i<n;i++){
        nvisited.insert(i);
        graph[i] = new int[n];
        for(int t=0;t<n;t++){
            graph[i][t]=0;
        }
    }
    int b1,b2;
    for(int i=0;i<m;i++){
        scanf("%d %d",&b1,&b2);
        graph[--b1][--b2]=1;
        graph[b2][b1]=1;
    }
    scanf("%d %d",&b1,&b2);
    if(--b1==--b2){
        printf("True");
        return 0;
    }
    set<int> v;
    v.insert(b1);
    while(!v.empty()){
        int vi = *v.begin();
        nvisited.erase(vi);
        v.erase(v.begin());
        for(int i=0;i<n;i++){
            if((graph[vi][i]==1)&&(nvisited.find(i)!=nvisited.end())){
                if(i==b2){
                    printf("True");
                    return 0;
                }
                v.insert(i);
            }
        }
    }
    printf("False");





    return 0;
}

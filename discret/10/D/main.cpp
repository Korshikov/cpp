#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int parent[600002],n;



int getParent(int item){
    if(item==parent[item])
        return item;
    parent[item]= getParent(parent[item]);
    return parent[item];
}

/*void unuon(int set1,int set2){
    set1=getParent(set1);
    set2=getParent(set2);
    if(set1==set2)
        return;
    if(coun[set1]>coun[set2]){
        parent[set2]=set1;
        coun[set1]+=coun[set2];
        maximum[set1]= max(maximum[set1],maximum[set2]);
    }else{
        parent[set1]=set2;
        coun[set2]+=coun[set1];
        maximum[set2]= max(maximum[set1],maximum[set2]);
    }

}*/

int unionWithNextGroup(int item){
    int ret = getParent(item);
    parent[ret]=getParent(ret%n+1);
    return ret;
}

int main()
{
    freopen("parking.in","r",stdin);
    freopen("parking.out","w+",stdout);
    int b1;
    scanf("%d\n",&n);
    for(int i=0;i<=n;++i){
        parent[i]=i;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b1);
        printf("%d ",unionWithNextGroup(b1));
    }

    return 0;
}

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int parent[100002],minimum[100002],maximum[100002],coun[100002];

int getParent(int item){
    if(item==parent[item])
        return item;
    parent[item]= getParent(parent[item]);
    return parent[item];
}

void unuon(int set1,int set2){
    set1=getParent(set1);
    set2=getParent(set2);
    if(set1==set2)
        return;
    if(coun[set1]>coun[set2]){
        parent[set2]=set1;
        coun[set1]+=coun[set2];
        minimum[set1]= min(minimum[set1],minimum[set2]);
        maximum[set1]= max(maximum[set1],maximum[set2]);
    }else{
        parent[set1]=set2;
        coun[set2]+=coun[set1];
        minimum[set2]= min(minimum[set1],minimum[set2]);
        maximum[set2]= max(maximum[set1],maximum[set2]);
    }

}

int main()
{
    freopen("dsu.in","r",stdin);
    freopen("dsu.out","w+",stdout);
    int n,b1,b2;
    scanf("%d\n",&n);
    for(int i=1;i<=n;++i){
        parent[i]=i;
        minimum[i]=i;
        maximum[i]=i;
        coun[i]=1;
    }
    char c;
    while ((scanf("%c", &c) != EOF)&&(c!=EOF)){
        if(c=='u'){
            scanf("nion %d %d\n",&b1,&b2);
            unuon(b1,b2);
            continue;
        }
        if(c=='g'){
            scanf("et %d\n",&b1);
            b1 = getParent(b1);
            printf("%d %d %d\n",minimum[b1],maximum[b1],coun[b1]);
        }



    }

    return 0;
}

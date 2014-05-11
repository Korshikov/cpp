#include <cstdio>


using namespace std;

int parent[100002],coun[100002];

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

    }else{
        parent[set1]=set2;
        coun[set2]+=coun[set1];

    }

}

int main()
{
    int n,b1,b2,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i){
        parent[i]=i;
        coun[i]=1;
    }
    char c;
    for(int i =0;i<m;i++){
        scanf("\n%c", &c);
        if(c=='U'){
            scanf("nion %d %d",&b1,&b2);
            unuon(b1,b2);
            continue;
        }
        if(c=='C'){
            scanf("heck %d %d",&b1,&b2);
            b1 = getParent(b1);
            b2 = getParent(b2);
            if(b1==b2){
                printf("True\n");
            }else{
                printf("False\n");
            }
        }



    }

    return 0;
}

#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

struct point{
    int position;
    long long type;
    unsigned number;

    point& operator= (const point& data){
        position= data.position;
        type = data.type;
        number = data.number;
        return *this;
    }
};

bool comparator(point& a,point& b){
    if(a.position<b.position){
        return true;
    }
    if(a.position>b.position){
        return false;
    }
    return a.type>b.type;
}

bool comparator2(point& a,point& b){
    return a.number<b.number;
}


template<typename T>
void qSort(T* aBegin,T* aEnd, bool (*comp)(T&,T&)){
    T x=*(aBegin+(aEnd-aBegin)/2);
    T t;
    int i=0;
    int j = aEnd-aBegin-1;
    do{
        while(comp(aBegin[i],x)){
            i++;
        }
        while(comp(x,aBegin[j])){
            j--;
        }
        if(i<=j){
            if(i<j){
                t = aBegin[i];
                aBegin[i]=aBegin[j];
                aBegin[j]=t;
            }
            i++;
            j--;
        }
    }while(i<j);
    if(j>0){
        qSort(aBegin,aBegin+j+1,comp);
    }
    if(aBegin+i<aEnd){
        qSort(aBegin+i,aEnd,comp);
    }


}

template<typename T>
int qSortPartition(T* aBegin,T* aEnd, bool (*comp)(T&,T&)){
    T x=*(aBegin+(aEnd-aBegin)/2);
    T t;
    int i=0;
    int j = aEnd-aBegin-1;
    while(i<j){
        while(comp(aBegin[i],x)){
            i++;
        }
        while(comp(x,aBegin[j])){
            j--;
        }
        if(i<=j){
            if(i<j){
                t = aBegin[i];
                aBegin[i]=aBegin[j];
                aBegin[j]=t;
            }
            i++;
            j++;
        }else{
            return j;
        }
    }
    return j;
}

int main()
{
    int n,m,l,b1,b2;
    scanf("%d %d",&n,&m);
    l=2*n+m;
    point* arra = new point[l];
    for(int i=0;i<n;i++){
        scanf("%d %d",&b1,&b2);
        arra[i*2].position = min(b1,b2);
        arra[i*2+1].position= max(b1,b2);
        arra[i*2+0].type = 1;
        arra[i*2+0].number = UINT_MAX;
        arra[i*2+1].type = -1;
        arra[i*2+1].number = UINT_MAX;
    }
    for(int i=0;i<m;i++){
        scanf("%d",&arra[i+n*2].position);
        arra[i+n*2].type=0;
        arra[i+n*2].number = i;
    }
    //sort(arra,arra+l,&comparator);
    qSort(arra,arra+l,&comparator);
    int c=0;
    for(int i=0;i<l;i++){
        c+= arra[i].type;
        if(arra[i].type==0){
            arra[i].type=c;
        }
    }
    //sort(arra,arra+l,&comparator2);
    qSort(arra,arra+l,&comparator2);
    for(int i=0;i<l;i++){
        if(arra[i].number==UINT_MAX){
            break;
        }else{
            printf("%lld ",arra[i].type);
        }
    }

    return 0;
}
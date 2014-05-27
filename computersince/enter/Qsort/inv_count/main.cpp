#include <cstdio>
#include <algorithm>

using namespace std;

long unsigned  invers =0;

template<typename T>
T* merge_(T* a,unsigned na,T* b,unsigned nb){
    unsigned ia=0,ib=0;
    T* res = new T[na+nb];
    while((ia<na)&&(ib<nb)){
        if(a[ia]<=b[ib]){
            res[ia+ib]=a[ia++];
        }else{
            res[ia+ib]=b[ib++];
            invers += na - ia;
        }
    }
    while(ia<na){
        res[ia+ib]=a[ia++];
    }
    while(ib<nb){
        res[ia+ib]=b[ib++];
    }

    return res;
}

template<typename T>
T* mergeSort_(T* a,unsigned na){
    if(na<=1){
        return a;
    }
    T* a1 = mergeSort_(a,na/2);
    T* a2 = mergeSort_(a+na/2, na-na/2);
    return merge_(a1,na/2,a2,na-na/2);
}



int main()
{
    int n;
    scanf("%d",&n);
    int* a = new int[n];
    for(int i =0;i<n;i++){
        scanf("%d",&a[i]);
    }
    mergeSort_(a,n);
    printf("%lu",invers);
    return 0;
}

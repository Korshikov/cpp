#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int binarySearchFirst(int* a, int value, int l,int r);
int binarySearchEnd(int* a, int value, int l,int r);

int binarySearchFirst(int* a,int value, int n){
    return binarySearchFirst(a,value,-1,n);
}

int binarySearchFirst(int* a, int value, int l,int r){
    if(r-l== 1){
        return l;
        if(a[r]==value){
            return r+1;
        }else if(a[l]==value){
            return l+1;
        }else{
            return -1;
        }
    }
    int midle = l + (r-l)/2;
    if(a[midle]<value){
        return binarySearchFirst(a,value,midle,r);
    }else{
        return binarySearchFirst(a,value,l,midle);
    }
}

int binarySearchEnd(int* a,int value, int n){
    return binarySearchEnd(a,value,-1,n);
}

int binarySearchEnd(int* a, int value, int l,int r){
    if(r-l== 1){
        return r-1;
        if(a[r]==value){
            return r+1;
        }else if(a[l]==value){
            return l+1;
        }else{
            return -1;
        }
    }
    int midle = l + (r-l)/2;
    if(a[midle]<=value){
        return binarySearchEnd(a,value,midle,r);
    }else{
        return binarySearchEnd(a,value,l,midle);
    }
}

int main()
{
    freopen("find3.in","r",stdin);
    freopen("find3.out","w+",stdout);
    int n;
    scanf("%d",&n);
    int* a = new int[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int k,b,b2;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        scanf("%d %d",&b,&b2);
        printf("%d ",binarySearchEnd(a,b2,n)-binarySearchFirst(a,b,n));
    }

    fclose(stdin);
    fclose(stdout);
    delete[] a;
    return 0;
}

#include <cstdio>
#include <cstdlib>

using namespace std;

int binarySearchFirst(int* a, int value, int l,int r);
int binarySearchEnd(int* a, int value, int l,int r);

int binarySearchFirst(int* a,int value, int n){
    return binarySearchFirst(a,value,-1,n);
}

int binarySearchFirst(int* a, int value, int l,int r){
    if(r-l== 1){
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
    freopen("binsearch.in","r",stdin);
    freopen("binsearch.out","w+",stdout);
    int n;
    scanf("%d",&n);
    int* a = new int[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int k,b;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        scanf("%d",&b);
        printf("%d ",binarySearchFirst(a,b,n));
        printf("%d\n",binarySearchEnd(a,b,n));
    }

    fclose(stdin);
    fclose(stdout);
    delete[] a;
    return 0;
}

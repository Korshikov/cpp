#include <cstdio>
#include <cstdlib>

using namespace std;

int binarySearch(int* a, int value, int l,int r);
int binarySearch(int* a,int value, int n);


int binarySearch(int* a,int value, int n){
    return binarySearch(a,value,0,n-1);
}

int binarySearch(int* a, int value, int l,int r){
    if(r-l== 1){
        if(a[r]==value){
            return r+1;
        }else if(a[l]==value){
            return l+1;
        }else{
            return -1;
        }
    }
    int midle = r + (l-r)/2;
    if(a[midle]<value){
        return binarySearch(a,value,midle,r);
    }else{
        return binarySearch(a,value,l,midle);
    }
}

int main()
{
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
        printf("%d ",binarySearch(a,b,n));
    }


    return 0;
}

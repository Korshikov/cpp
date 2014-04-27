#include <cstdio>
#include <cstdlib>

using namespace std;

int binarySearch(int* a, int value, int l,int r);
int binarySearch(int* a,int value);

int binarySearch(int* a,int value){
    return binarySearch(a,value,0,sizeof(a)/sizeof(a[0])+1);
}

int binarySearch(int* a, int value, int l,int r){
    return -1;
}

int main()
{
    int n;
    scanf("%d",&n);
    int* a = new int[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    return 0;
}

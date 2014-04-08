#include <cstdio>
#include <cstdlib>

using namespace std;

/*bool testheap(int item,int* heap,int n){
	return ((2*item>=n)||
                (((heap[item]<=heap[2*item])&&(testheap(2*item,heap,n)))&&
                    ((2*item+1>=n)||
                     ((heap[item]<=heap[2*item+1])&&(testheap(2*item+1,heap,n))))));
}*/

int main()
{
    int n, heap[300000];
    freopen("isheap.in","r",stdin);
    freopen("isheap.out","w+",stdout);
    scanf("%d",&n);
    //heap = (int*) malloc(sizeof(int)*(n+1));
    for(int i=1;i<=n;++i){
        scanf("%d",&heap[i]);
    }
    /*if(testheap(1,heap,n)){
        printf("YES");
    }else{
        printf("NO");
    }*/
    for(int i= 1;2*i<=n;++i){
        if((heap[i]>heap[2*i])||((2*i+1<=n)&&(heap[i]>heap[2*i+1]))){
            printf("NO");
            //free(heap);
            return 0;
        }
    }
    printf("YES");
    //free(heap);
    return 0;
}

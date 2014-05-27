#include <cstdio>
#include <cstdint>
#include <cinttypes>
#include <algorithm>

using namespace std;

template<typename T>
T orderStatistic(T* a,const unsigned& n,unsigned k,unsigned start=0, unsigned end=0)
{
    if(end==0)
    {
        end = n-1;
    }
    unsigned pivot_index =
}

int main()
{
    freopen("kth.in","r",stdin);
    freopen("kth.out","w+",stdout);

    unsigned n,k;
    scanf("%u %u",&n,&k);
    int32_t *a = new int32_t[n];
    int A,B,C;
    if(n>1)
    {
        scanf("%d %d %d %" SCNd32 " %" SCNd32 ,&A,&B,&C,&a[0], &a[1]);
        for(unsigned i=2;i<n;i++){
            a[i]=A*a[i-2]+B*a[i-1]+C;
        }
    }else{
        scanf("%d %d %d %" SCNd32 ,&A,&B,&C,&a[0]);
    }

    printf("%" PRId32 ,orderStatistic(a,n,--k));

    fclose(stdin);
    fclose(stdout);
    delete[] a;
    return 0;
}

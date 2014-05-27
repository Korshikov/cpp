#include <cstdio>
#include <cstdint>
#include <cinttypes>
#include <algorithm>

using namespace std;


template<typename T>
T orderStatistic(T* a,const unsigned& n,unsigned k)
{
    unsigned l=0,r=n-1,i,t;
    T pivot;
    while(1)
        {
        i=l;
        t=r;
        pivot = a[l];
        while(1)
        {
            while(a[i++]<pivot)
            {
                ;
            }
            i--;
            while(a[t--]>pivot)
            {
                ;
            }
            t++;
            if(i<t)
            {
                if(a[i]!=a[t])
                {
                    swap(a[i],a[t]);
                }
                t--;
            }
            else
            {
                break;
            }
        }


        if((t==k)||((a[l]==a[t])&&(a[t]==a[r])&&(l<k)&&(k<r)))
        {
            return a[k];
        }
        if(t>k)
        {
            r = t-1;
        }
        else
        {
            l = t+1;
        }
    }

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

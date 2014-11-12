#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;


    int n,a,b;

    unsigned int cur = 0; // беззнаковое 32-битное число
    unsigned int nextRand24() {
        cur = cur * a + b; // вычисляется с переполнениями
        return cur >> 8; 
    }
    unsigned int nextRand32() {
        unsigned int a = nextRand24(), b = nextRand24();
        return (a << 8) ^ b; 
    }


unsigned kth( unsigned* arr,const unsigned&  l,const unsigned& r,unsigned k)
{
    unsigned x = arr[(l+r) / 2];
    unsigned i=l,j=r;
    while(i<=j)
    {
        while(arr[i] < x) i++;
        while(arr[j] > x) j--;

        if(i<=j)
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    if(l<=k && k<=j)
        return kth(arr,l,j,k);
    if( i<=k && k<=r)
        return kth(arr,i,r,k);
    return arr[k];
}

unsigned long long getSum(const unsigned* ar,long long el,const unsigned& n)
{
    unsigned long long sum = 0;
    for(unsigned i=0 ; i<n;++i)
    {
        sum += abs(ar[i]-el);       
    }
    return sum;
}



int main() {
    freopen("postman.in","r",stdin);
    freopen("postman.out","w+",stdout);


    scanf("%d%d%d",&n,&a,&b);


    unsigned ar[n];
    for(int i=0;i<n;++i)
    {
        ar[i] = nextRand32();
    }
    if(n<2)
    {
        printf("0\n");
        
        fclose(stdin);
        fclose(stdout);

        return 0;

    }



    printf("%llu\n",min(getSum(ar, kth(ar,0,n-1,n/2),n),getSum(ar, kth(ar,0,n-1,(n/2)+1),n)) );

    fclose(stdin);
    fclose(stdout);

    return 0;
}

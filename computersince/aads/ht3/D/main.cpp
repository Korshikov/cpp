#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;


int n;
long long int cases;
long long int minini;


int main()
{
    freopen("cucarach.in","r",stdin);
    freopen("cucarach.out","w+",stdout);
    
    scanf("%d",&n);

    long long int maximx=0;
    long long int maximy=0;
    long long int minimx= UINT_MAX;
    long long int minimy= UINT_MAX;

    long long int b1,b2;

    for(int i=0;i<n;i++){
        scanf("%lld %lld",&b1,&b2);
        maximx = max(b1,maximx);
        minimx = min(b1,minimx);
        maximy = max(b2,maximy);
        minimy = min(b2,minimy);
    }

    minini = max(abs(minimx - ((maximx-minimx)/2+minimx)),abs(maximx - ((maximx-minimx)/2+minimx))) + max(abs(minimy -((maximy-minimy)/2+minimy)), abs(maximy -((maximy-minimy)/2+minimy))) ;
    cases = 0;
    //printf("%lld %lld\n", minini, cases );
    //printf("%lld %lld\n", abs(minimx - ((maximx-minimx+1)/2+minimx)), abs(maximx - ((maximx-minimx+1)/2+minimx)) );

    if(max(abs(minimx - ((maximx-minimx+1)/2+minimx)),abs(maximx - ((maximx-minimx+1)/2+minimx))) + max(abs(minimy -((maximy-minimy)/2+minimy)), abs(maximy -((maximy-minimy)/2+minimy)))<minini)
    {
        minini=max(abs(minimx - ((maximx-minimx+1)/2+minimx)),abs(maximx - ((maximx-minimx+1)/2+minimx))) + max(abs(minimy -((maximy-minimy)/2+minimy)), abs(maximy -((maximy-minimy)/2+minimy)));
        cases = 1;
      //  printf("%lld %lld\n", minini, cases );
    }
    if(max(abs(minimx - ((maximx-minimx)/2+minimx)),abs(maximx - ((maximx-minimx)/2+minimx))) + max(abs(minimy -((maximy-minimy+1)/2+minimy)), abs(maximy -((maximy-minimy+1)/2+minimy)))<minini)
    {
        minini=max(abs(minimx - ((maximx-minimx)/2+minimx)),abs(maximx - ((maximx-minimx)/2+minimx))) + max(abs(minimy -((maximy-minimy+1)/2+minimy)), abs(maximy -((maximy-minimy+1)/2+minimy)));
        cases = 2;
        //printf("%lld %lld\n", minini, cases );
    }
    if(max(abs(minimx - ((maximx-minimx+1)/2+minimx)),abs(maximx - ((maximx-minimx+1)/2+minimx))) + max(abs(minimy -((maximy-minimy+1)/2+minimy)), abs(maximy -((maximy-minimy+1)/2+minimy)))<minini)
    {
        minini=max(abs(minimx - ((maximx-minimx+1)/2+minimx)),abs(maximx - ((maximx-minimx+1)/2+minimx))) + max(abs(minimy -((maximy-minimy+1)/2+minimy)), abs(maximy -((maximy-minimy+1)/2+minimy)));
        cases = 3;
        //printf("%lld %lld\n", minini, cases );
    }
    
    switch (cases)
    {
        case 0:
        printf("%u %u\n",(maximx-minimx)/2+minimx,(maximy-minimy)/2+minimy);
        break;
        case 1:
        printf("%u %u\n",(maximx-minimx+1)/2+minimx,(maximy-minimy)/2+minimy);
        break;
        case 2:
        printf("%u %u\n",(maximx-minimx)/2+minimx,(maximy-minimy+1)/2+minimy);
        break;
        case 3:
        printf("%u %u\n",(maximx-minimx+1)/2+minimx,(maximy-minimy+1)/2+minimy);
        break;
        
    }

    fclose(stdin);
    fclose(stdout);
    
    return 0;
}

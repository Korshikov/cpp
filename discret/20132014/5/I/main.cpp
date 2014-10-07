#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

int n,memory_of_count[101][101];
long long k;

int gen_parts_of_n_with_subs_no_more_m(int n,int m )
{
    if (memory_of_count[n][m]!= 0)
        return memory_of_count[n][m];
    if((n<0)||(m<1)||(n<m))
        return 0;
    if((n==m))
    {
        memory_of_count[n][m]=1;
        return 1;
    }

    memory_of_count[n][m]=gen_parts_of_n_with_subs_no_more_m(n-m,m)+gen_parts_of_n_with_subs_no_more_m(n,m+1);
    return memory_of_count[n][m];
}

void gen()
{
    if(n==0)
        return;
    int i;
    for(i=n;i>0;i--)
        if(gen_parts_of_n_with_subs_no_more_m(n,i)>=k)
            break;
    k-=gen_parts_of_n_with_subs_no_more_m(n,i+1);
    printf("%d",i);
    n-=i;
    if (n>0)
        printf("+");
    gen();


}



int main() {
    //freopen("num2part.in","r",stdin);
    //freopen("num2part.out","w+",stdout);

    scanf("%d %lld",&n,&k);
    k = gen_parts_of_n_with_subs_no_more_m(n,1)-k;


    gen();

    return 0;
}

#include <cstdio>
#include <cstdlib>

using namespace std;

int n;
long long k, count_not_ful_memory[41][20];



long long count_not_ful(int n,int balans)
{
    if(balans<0)
        return 0;
    if(balans>n)
        return 0;
    if((balans+n)&1)
        return 0;
    if(balans==n)
        return 1;
    if(n==0)
        return 0;
    if((count_not_ful_memory[n][balans])==0)
        count_not_ful_memory[n][balans] =count_not_ful(n-1,balans-1)+count_not_ful(n-1,balans+1);
    return count_not_ful_memory[n][balans];
}

void gen(int glub=0,int levl=0)
{
    if(levl==2*n)
        return;
    if(((k<count_not_ful(2*n-levl-1,glub+1))&&(glub<n))||(glub==0))
        printf("(");
    else
    {
        k-=count_not_ful(2*n-levl-1,glub+1);
        glub-=2;
        printf(")");
    }
    gen(glub+1,levl+1);
}


int main() {
    freopen("num2brackets.in","r",stdin);
    freopen("num2brackets.out","w+",stdout);

    scanf("%d %lld",&n,&k);

    gen();


    return 0;
}

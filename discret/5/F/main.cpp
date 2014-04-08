#include <cstdio>
#include <cstdlib>
#include <cstring>

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
    freopen("brackets2num.in","r",stdin);
    freopen("brackets2num.out","w+",stdout);

    int glub=0;
    char s[40];
    //scanf("%d %lld",&n,&k);

    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
            glub++;
        else
        {
            k+=count_not_ful(n-i-1,glub+1);
            glub--;
        }
    }

    //gen();
    printf("%lld",k);

    return 0;
}

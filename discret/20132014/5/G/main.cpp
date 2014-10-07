#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>

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
    freopen("num2brackets2.in","r",stdin);
    freopen("num2brackets2.out","w+",stdout);


    scanf("%d %lld",&n,&k);

    int glub=0,memory_len=0;
    stack<char> memory;
    long long temp;

    for(int i=2*n-1; i>-1;i--)
    {
        if(glub<n)
            temp=count_not_ful(i,glub+1)<<((i-glub-1)/2);
        else
            temp=0;
        if(k<temp)
        {
            printf("(");
            memory.push('(');
            memory_len++;
            glub++;
            continue;
        }

        k-=temp;

        if((memory_len>0)&&(memory.top() == '(')&&(glub>0))
            temp=count_not_ful(i,glub-1)<<((i-glub+1)/2);
        else
            temp=0;
         if(k<temp)
        {
            printf(")");
            memory.pop();
            memory_len--;
            glub--;
            continue;
        }
        k-=temp;

        if(glub<n)
            temp=count_not_ful(i,glub+1)<<((i-glub-1)/2);
        else
            temp=0;

        if(k<temp)
        {
            printf("[");
            memory.push('[');
            memory_len++;
            glub++;
            continue;
        }

        k-=temp;

        printf("]");
        memory.pop();
        memory_len--;
        glub--;

    }

//   printf("%lld",k);

    return 0;
}

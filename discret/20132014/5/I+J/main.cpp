#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

int n,memory_of_count[101][101];
queue<int> input;
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
    input.push(i);
    //printf("%d",i);
    n-=i;
    //if (n>0)
    //    printf("+");
    gen();


}



int main() {
    //freopen("num2part.in","r",stdin);
    //freopen("num2part.out","w+",stdout);

    for(int num = 99; num<100;num++)
        for(int p=0;p<gen_parts_of_n_with_subs_no_more_m(num,1);p++)
    {

    n=num;
    k=p;
    //scanf("%d %lld",&n,&k);
    long long k_memory = k;
    int n_memory=n;
    k = gen_parts_of_n_with_subs_no_more_m(n,1)-k;


    gen();


     //char input_str[20];
    int bufer=0,last_n;
    k=0;
    /*scanf("%s",input_str);
    for(unsigned int i=0;i<strlen(input_str);i++)
        if(input_str[i]=='+')
        {
            n+=bufer;
            input.push(bufer);
            bufer=0;
        }
        else
        {
            bufer= bufer*10+input_str[i]-'0';
        }
    n+=bufer;
    input.push(bufer);
    */
    n=n_memory;
    last_n=n;


    while(!input.empty())
    {
        bufer = input.front();
        k+= gen_parts_of_n_with_subs_no_more_m(n,bufer+1);
        n-=bufer;
        input.pop();
    }

    k = gen_parts_of_n_with_subs_no_more_m(last_n,1)-k-1;

if (k!=k_memory)
{
    printf("%d %lld %lld",n_memory,k,k_memory);
    return 0;
}

    }
    return 0;
}

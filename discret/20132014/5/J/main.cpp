#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

long long n,memory_of_count[101][101];
queue<int> input;
long long k;

long long gen_parts_of_n_with_subs_no_more_m(int n,int m )
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
    freopen("part2num.in","r",stdin);
    freopen("part2num.out","w+",stdout);

    char input_str[400];
    int bufer=0,last_n;
    scanf("%s",input_str);
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
    last_n=n;

    while(!input.empty())
    {
        bufer = input.front();
        k+= gen_parts_of_n_with_subs_no_more_m(n,bufer+1);
        n-=bufer;
        input.pop();
    }

    k = gen_parts_of_n_with_subs_no_more_m(last_n,1)-k-1;

    printf("%lld",k);


    //gen();



    return 0;
}

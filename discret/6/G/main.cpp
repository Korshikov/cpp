
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

int n;
int input[200000];
int k;

void print()
{
    printf("%d=",n);
    for(int i=0;i<k-1;i++)
        printf("%d+",input[i]);
    printf("%d",input[k-1]);
    return;
}



int main() {
    freopen("nextpartition.in","r",stdin);
    freopen("nextpartition.out","w+",stdout);

    char input_str[300000];
    int bufer=0;
    scanf("%s",input_str);
    unsigned int len = strlen(input_str);
    for(unsigned int i=0;i<len;i++)
        if(input_str[i]=='=')
        {
            n=bufer;
            bufer=0;
        }
        else
        if(input_str[i]=='+')
        {
            input[k]=bufer;
            bufer=0;
            k++;
        }
        else
        {
            bufer= bufer*10+input_str[i]-'0';
        }
    input[k]=(bufer);
    k++;
    if(n==input[k-1])
    {
        printf("No solution");
        return 0;
    }
    if(input[k-1]==input[k-2])
    {
        input[k-2]+=input[k-1];
        k--;
        print();
        return 0;
    }
    int i=k-2,need=input[i+1];
    for(;(i>-1)&&(input[i]>input[i+1]-1)&&(input[i]!=input[0]);i--)
        need+=input[i];
    if(input[i]+1>=need)
    {
        input[i]+=need;
        k=i+1;
        print();
        return 0;
    }
    input[i]++;
    need--;
    for(i=i+1;need>=input[i-1];i++)
    {
        input[i]=input[i-1];
        need-=input[i];
    }
    k=i;
    input[i-1]+=need;
    print();
    return 0;
}

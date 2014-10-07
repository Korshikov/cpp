#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>


using namespace std;

unsigned int n;
char input_str[200005];


int main() {
    freopen("nextbrackets.in","r",stdin);
    freopen("nextbrackets.out","w+",stdout);

    scanf("%s",input_str);

    int i,len=strlen(input_str);
    i=len-1;
    for(int balans=0;i>0;i--)
    {
        if(input_str[i]==')')
        {
            balans++;
        }
        else
        {
            balans--;
        }
        if((input_str[i]=='(')&&(balans>0))
        {
            balans--;
            for(int t=0;t<i;t++)
                printf("%c",input_str[t]);
            printf(")");
            n=(len-i-1-balans)/2;
            for(unsigned int t=0;t<n;t++)
                printf("(");
            for(unsigned int t=0;t<(len-i-n-1);t++)
                printf(")");
            return 0;
        }
    }
    printf("-");


    return 0;
}

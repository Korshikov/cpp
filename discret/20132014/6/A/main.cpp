#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

char input_str[200001];


void prev_and_next()
{
    unsigned int i_p=0,i_n=0,l=strlen(input_str);
    for(unsigned int i=l-1;i>0;i--)
        {
            if((i_p==0)&&(input_str[i]=='1'))
            {
                i_p=i;
                if(i_n!=0)
                    break;
                continue;
            }
            if((i_n==0)&&(input_str[i]=='0'))
            {
                i_n=i;
                if(i_p!=0)
                    break;
                continue;
            }

        }
    char substr[200002];
    if((i_p==0)&&(input_str[0]=='0'))
    {
        printf("-\n");
    }
    else
    {
        memcpy( substr, &input_str[0], i_p );
        substr[i_p]='\0';
        printf("%s",substr);
        printf("0");
        for(;i_p<l-1;i_p++)
            printf("1");
        printf("\n");
    }


    if((i_n==0)&&(input_str[0]=='1'))
    {
        printf("-\n");
        return;
    }
    memcpy( substr, &input_str[0], i_n );
    substr[i_n]='\0';
    printf("%s",substr);
    printf("1");
    for(;i_n<l-1;i_n++)
        printf("0");
    printf("\n");

    return;
}

int main() {
    freopen("nextvector.in","r",stdin);
    freopen("nextvector.out","w+",stdout);

    scanf("%s",input_str);

    prev_and_next();

    return 0;
}

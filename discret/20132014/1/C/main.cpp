#include <cstdio>
#include <cstdlib>
#include <algorithm>


using namespace std;

unsigned ecvival[26] , pos;
char c;

int next_char(unsigned c)
{
    if(ecvival[0]==c)
        return 0;
    for(int i=1; i<26;i++)
        if(c==ecvival[i])
        {
            pos=i;
            break;
        }
    copy(ecvival,ecvival+pos,ecvival+1);
    ecvival[0] = c;
    return pos;
}

int main()
{
    freopen("mtf.in","r",stdin);
    freopen("mtf.out","w+",stdout);
    for(char e='a';e<='z';e++)
        ecvival[e-'a']=e-'a';
    while((scanf("%c",&c)!= EOF)&&(c!=EOF)&&(c>='a')&&(c<='z'))
    {
        printf("%d ",next_char(c-'a')+1);
        //scanf("%c",&c);
    }



    return 0;
}

#include <cstdio>
#include <iostream>
#include <map>
#include <string>



using namespace std;
int n=25;
map<string, int> transliter;
char c,a='a';


int main()
{
    freopen("lzw.in","r",stdin);
    freopen("lzw.out","w+",stdout);
    for(c='a';c<='z';c++)
        transliter[string(&c)]=(int)c-'a';

    string str,bufe;
    while((scanf("%c",&c)!= EOF)&&(c!=EOF))
    {
        bufe = str+string(&c);
        if((transliter.find(bufe)->second==0)&&(bufe!=string(&a)))
        {
            printf("%d ",transliter.find(str)->second);
            transliter[bufe]=++n;
            str= string(&c);
        }else
        {
            str+=c;
        }

    }
    //printf("%d ",transliter.find(str)->second);
    return 0;
}

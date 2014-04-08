#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;


char str[1000];
string arra[1000],b;
int main()
{
    freopen("bwt.in","r",stdin);
    freopen("bwt.out","w+",stdout);
    scanf("%s",str);
    unsigned c =strlen(str);
    for(unsigned i=0;i<c;i++)
    {
        for(unsigned t=0; t< c;t++)
            b+=str[(t+i)%c];
        arra[i]=b;
        b.clear();
    }
    sort(arra,arra+c);

    for(unsigned i=0;i<c;i++)
        printf("%c",arra[i][c-1]);

    return 0;
}

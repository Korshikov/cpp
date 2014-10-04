#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

vector<bool> hasMark;
int haventMark = 15000;

int main()
{
    freopen("collection.in","r",stdin);
    freopen("collection.out","w+",stdout);


    int n,b;
    hasMark.assign(15001,false);
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&b);
        if(!(hasMark[b]))
        {
            --haventMark;
            hasMark[b]=true;
        }
    }

    printf("%d",haventMark);

    fclose(stdin);
    fclose(stdout);
    return 0;
}

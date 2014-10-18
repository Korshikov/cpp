#include <algorithm>
#include <climits>
#include <cstdio>

using namespace std;

const size_t N_MAX = 100000;
const size_t NAME_LENGTH_MAX = 10;

struct cildren
{
    size_t l;
    size_t r;
    char name[NAME_LENGTH_MAX];
};

int main()
{
    freopen("meeting.in","r",stdin);
    freopen("meeting.out","w+",stdout);

    int n;
    scanf("%d",&n);
    
    cildren* circl = new cildren[n];
    
    scanf("%s",&circl[0].name);
    circl[0].l=n-1;
    circl[0].r=1;

    for(int i=1;i<n-1;++i)
    {
        scanf("%s",&circl[i].name);
        circl[i].l=i-1;
        circl[i].r=i+1;
    }
    
    scanf("%s",&circl[n-1].name);
    circl[n-1].l=n-2;
    circl[n-1].r=0;

    int b;

    for(;n>3;--n)
    {
        scanf("%d",&b);
        b--;
        printf("%s %s\n",circl[circl[b].l].name,circl[circl[b].r].name);
        circl[circl[b].l].r = circl[b].r;
        circl[circl[b].r].l = circl[b].l;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

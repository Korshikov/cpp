#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

std::vector<pair<int,int> > v;
int n,m;

bool comp(pair<int,int> a,pair<int,int> b)
{
    return a.first > b.first;
}

int main()
{
    freopen("arrival.in","r",stdin);
    freopen("arrival.out","w+",stdout);

    scanf("%d %d",&n,&m);
    v.resize(m);
    int bufer,sum=0;
    for(int i=0;i<m;++i)
    {
        scanf("%d",&bufer);
        v[i]=make_pair(bufer,i);
        sum+=bufer;
    }
    if(sum<n)
    {
        printf("-1\n");
        return 0;
    }
    sort(v.begin(),v.end(),comp);
    sum=0;
    for(bufer=0;sum<n;++bufer)
    {
        sum+=v[bufer].first;
    }
    printf("%d\n",bufer);
    for(int i=0;i< bufer;++i)
    {
        printf("%d ", v[i].second+1);
    }


    //printf("%u %u %u %u",2*mins,mina,minb,minc);

    fclose(stdin);
    fclose(stdout);
    return 0;
}

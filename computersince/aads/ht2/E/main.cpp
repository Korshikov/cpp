#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

std::vector<comand> v;
int n;

char 

int main()
{
    freopen("ejudge.in","r",stdin);
    //freopen("ejudge.out","w+",stdout);

    scanf("%d",&n);
    v.resize(n);
    int bufer,bufer2;
    for(int i=0;i<n;++i)
    {
        scanf("%d %d",&bufer,&bufer2);
        v[i].ok = bufer;
        v[i].time = bufer2;
        v[i].number = i;
    }
    
    sort(v.begin(),v.end());
    
    for(bufer=0;bufer<n;++bufer)
    {
        printf("%d ",v[bufer].number+1 );    
    }
    

    //printf("%u %u %u %u",2*mins,mina,minb,minc);

    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


struct comand
{
    int ok ;
    int time ;
    int number ;
    comand()
    {
        ok=0;
        time=0;
        number=0;
    }
    
};

bool operator<(const comand& a, const comand& b)
{
    if(a.ok<b.ok)
    {
        return false;
    }
    if(a.ok>b.ok)
    {
        return true;
    }
    if(a.time>b.time)
    {
        return false;
    }
    if(a.time<b.time)
    {
        return true;
    }
    if(a.number > b.number)
    {
        return false;
    }
        return true;
}


std::vector<comand> v;
int n;


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

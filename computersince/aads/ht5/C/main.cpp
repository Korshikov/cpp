#include <cstdio>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

unsigned parent[50000];
unsigned rank[50000];

unsigned find_set(const unsigned& v)
{
    if(v==parent[v])
    {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_set(unsigned a, unsigned b)
{
    a = find_set(a);
    b = find_set(b);
    if(a==b)
    {
        return;
    }
    if(rank[a] > rank[b])
    {
        parent[b]=a;
        if(rank[a]==rank[b])
        {
            ++rank[a];
        }
    }
    else
    {
        parent[a]=b;
        if(rank[a]==rank[b])
        {
            ++rank[b];
        }
    }

}

int main() {
    freopen("cutting.in","r",stdin);
    freopen("cutting.out","w+",stdout);
    unsigned n,m,k;
    scanf("%u%u%u",&n,&m,&k);
    unsigned b1,b2;
    while(m--)
    { 
        scanf("%u%u\n",&b1,&b2);
    }
    for(unsigned i= 0; i<n;++i)
    {
        parent[i]=i;
    }
    char c;
    stack< pair<unsigned,pair<unsigned,unsigned> > > reqvest;

    for(unsigned i = 0; i< k;++i)
    {
        scanf("%c",&c);
        switch(c)
        {
            case 'a':
            scanf("sk %u %u\n",&b1,&b2);
            reqvest.push(make_pair(1,make_pair(b1,b2)));
            break;
            case 'c':
            scanf("ut %u %u\n",&b1,&b2);
            reqvest.push(make_pair(0,make_pair(b1,b2)));
        }
    }

    stack<bool> ans; 

    while(!reqvest.empty())
    {
        if(reqvest.top().first == 0)
        {
            union_set(reqvest.top().second.first,reqvest.top().second.second);
        }
        else
        {
            ans.push(find_set(reqvest.top().second.first) == find_set(reqvest.top().second.second));
        }
        reqvest.pop();
    }

    while(!ans.empty())
    {
        if(ans.top())
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        ans.pop();
    }

    
    

    fclose(stdin);
    fclose(stdout);
    return 0;
}

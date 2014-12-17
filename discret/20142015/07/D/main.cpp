#include <algorithm>
#include <climits>
#include <cstdio>
#include <vector>

using namespace std;

const int INF = INT_MAX;

class graph
{
public:

    graph(unsigned n):n(n),g(n)
    {

    }

    void add_edge(unsigned from, unsigned to, unsigned weight)
    {
        g[from].push_back(make_pair(to,weight));
    }

    bool test(unsigned min_weight)
    {
        parent = vector< unsigned >(n,UINT_MAX);
        for(unsigned i = 0 ; i<n;++i)
        {
            used = vector<bool>(n,0);
            if(!tryWithReplace(i,min_weight))
            {
                return false;
            }
        }
        return true;
    }

private:
    unsigned n;
    vector< vector< pair<unsigned,unsigned> > > g;
    vector< bool > used;
    vector< unsigned > parent;

    bool tryWithReplace(unsigned v, unsigned min_weight)
    {
        used[v] = true;
        for(auto e: g[v])
        {
            if(e.second<min_weight)
            {
                continue;
            }
            if((parent[e.first]==UINT_MAX)||((!used[parent[e.first]])&&(tryWithReplace(parent[e.first],min_weight))))
            {
                parent[e.first]=v;
                return true;
            }
        }
        return false;
    }
};


int main()
{
    freopen("minimax.in","r",stdin);
    freopen("minimax.out","w+",stdout);


    unsigned n;
    scanf("%u",&n);

    vector< unsigned > weights;
    unsigned w;

    unsigned a;
    unsigned b;

    graph g(n);


    for(a=0;a<n;++a)
    {
        for(b=0 ;b<n;++b)
        {
            scanf("%u",&w);
            weights.push_back(w);
            g.add_edge(a,b,w);
        }
    }

    a = 0;
    b = n*n-1;
    sort(weights.begin(),weights.end());

    while(b-a>1)
    {
        w = (b-a)/2 + a;
        if(g.test(weights[w]))
        {
            a = w;
        }
        else
        {
            b = w;
        }
    }

    printf("%u",weights[a]);

    fclose(stdin);
    fclose(stdout);

    return 0;
}

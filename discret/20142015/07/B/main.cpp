#include <algorithm>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <queue>
#include <vector>

using namespace std;

const long long INF = 2305843009213693952LL;

struct graph
{
	struct edge
	{
		edge(unsigned from, unsigned to, unsigned long long capacity, int cost, long long flow):
		    from(from), to(to), capacity(capacity), cost(cost), flow(flow)
        {}

		unsigned from;
		unsigned to;
		unsigned long long capacity;
		int cost;
		long long flow;
		edge* rev;

		long long remain()
		{	return capacity - flow;}
	};

	graph(int n) : n(n), g(n) {}

	void add_edge(unsigned from, unsigned to, unsigned long long capacity, int cost)
	{
		edge* e1 = new edge(from, to, capacity, cost, 0);
		edge* e2 = new edge(to, from, capacity, -cost, capacity);
		e1->rev = e2;
		e2->rev = e1;
		g[from].push_back(e1);
		g[to].push_back(e2);
	}

	long long min_cost(int s, int t)
	{
		vector<edge*> * path;
		long long ans = 0;
		while ((path = minPath(s, t))!= NULL)
		{
			long long mn = LLONG_MAX;
			long long cost = 0;
			for (auto i:*path)
			{
				mn = min(mn, i->remain());
				cost += i->cost;
			}
			ans += mn * cost;
			for (auto i:*path)
			{
				i->flow += mn;
				i->rev->flow -= mn;
			}
		}
		return ans;
	}

private:

	const int n;
	vector<vector<edge*> > g;

	vector<edge*>* minPath(int s, int t)
	{
		vector<long long> distance(n, INF);
		distance[s] = 0;
		vector<edge*> parent(n, (edge*)NULL);
		priority_queue<pair<long long, int> > q;
		q.push(make_pair(0, s));
		while (!q.empty())
		{
			int now = q.top().second;
			q.pop();
			for (auto i:g[now])
			{
                if ((distance[now] + i->cost < distance[i->to]) && (i->remain() > 0))
				{
					distance[i->to] = distance[now] + i->cost;
					parent[i->to] = i;
					q.push(make_pair(-distance[i->to], i->to));
				}
			}
		}
		if (distance[t] == INF)
			return NULL;
		vector<edge*> * ans = new vector<edge*>;
		edge* now = parent[t];
		while (now != NULL)
		{
			ans->push_back(now);
			now = parent[now->from];
		}
		return ans;
	}


};


int main()
{
    freopen("mincost.in","r",stdin);
    freopen("mincost.out","w+",stdout);

    unsigned n;
    unsigned m;
    scanf("%u%u",&n,&m);

    graph g(n);

    {
        unsigned a;
        unsigned b;
        int capacity;
        int cost;

        for(unsigned i=0; i < m;++i)
        {
            scanf("%u%u%d%d",&a,&b,&capacity,&cost);
            g.add_edge(a-1,b-1,capacity,cost);
        }
    }


	printf("%lld",g.min_cost(0, n - 1));

    fclose(stdout);
    fclose(stdin);

}

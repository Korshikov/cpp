#include <algorithm>
#include <climits>
#include <cstdio>
#include <math>

const int INF = INT_MAX;

struct delta
{
	int x;
	int y;

	delta(int const & dx = INF, int const & dy = INF):
	x(dx),y(dy)
	{}

	void set(int const & dx = INF, int const & dy = INF)
	{
		x=dx;
		y=dy;
	}
 
};

struct point
{
	int x;
	int y;
};

delta deltaDist(point const& a, point const & b) const
{
	return delta(std::abs(a.x - b.x),std::abs(a.y - b.y));
}


int main(void)
{
	unsigned int n;
	std::scanf("%u",&n);
	point points[n];
	for (unsigned int i = 0; i < n; ++i)
	{
		std::scanf("%d%d",&points[i].x,&points[i].y);
	}
	delta deltaDistance[n];
	bool used[n];
	delta resultDeltaDist;
	unsigned min_pos = n+1;
	delta min;
	deltaDistance[0].set(0,0);

	return 0;
}
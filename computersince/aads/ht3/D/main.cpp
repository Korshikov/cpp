#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

struct point
{
    int x;
    int y;

    point& operator= (const point& rhs)
    {
        x=rhs.x;
        y=rhs.y;
        return *(this);
     }
};

int dist_x(point a, point b)
{
    return abs(a.x-b.x);
}
int dist_y(point a, point b)
{
    return abs(a.y-b.y);
}

point max_x( point a, point b)
{
    if(a.x>b.x)
    {
        return a;
    }
    if(a.x<b.x)
        return b;
    if(a.y>b.y)
        return a;
    return b;
}

point max_y( point a, point b)
{
    if(a.y>b.y)
    {
        return a;
    }
    if(a.y<b.y)
        return b;
    if(a.x>b.x)
        return a;
    return b;
}
point min_x( point a, point b)
{
    if(a.x<b.x)
    {
        return a;
    }
    if(a.x>b.x)
        return b;
    if(a.y<b.y)
        return a;
    return b;
}

point min_y( point a, point b)
{
    if(a.y<b.y)
    {
        return a;
    }
    if(a.y>b.y)
        return b;
    if(a.x<b.x)
        return a;
    return b;
}


int main()
{
    freopen("cucarach.in","r",stdin);
    freopen("cucarach.out","w+",stdout);

    int n;
    scanf("%d",&n);

    point bufer;
    point minx,maxx,miny,maxy;

    scanf("%d %d",&bufer.x,&bufer.y);
    minx = bufer;
    maxx = bufer;
    miny = bufer;
    maxy = bufer;


    for(int i=1;i<n;++i)
    {
        scanf("%d %d",&bufer.x,&bufer.y);
        minx = min_x(minx,bufer);
        miny = min_y(miny,bufer);
        maxx = max_x(maxx,bufer);
        maxy = max_y(maxy,bufer);
    }

    point result,result1,result2,result3;

    result.x= (maxx.x - minx.x)/2 + minx.x;
    result.y= (maxy.y - miny.y)/2 + miny.y;
    result1.x= (maxx.x - minx.x)/2 + minx.x +1;
    result1.y= (maxy.y - miny.y)/2 + miny.y;
    result2.x= (maxx.x - minx.x)/2 + minx.x;
    result2.y= (maxy.y - miny.y)/2 + miny.y +1;
    result3.x= (maxx.x - minx.x)/2 + minx.x +1;
    result3.y= (maxy.y - miny.y)/2 + miny.y +1;

    /*printf("%d %d %d %d\n",dist(result,minx),dist(result,maxx),dist(result,miny),dist(result,maxy));
    printf("%d %d %d %d\n",dist(result1,minx),dist(result1,maxx),dist(result1,miny),dist(result1,maxy));
    printf("%d %d %d %d\n",dist(result2,minx),dist(result2,maxx),dist(result2,miny),dist(result2,maxy));
    printf("%d %d %d %d\n",dist(result3,minx),dist(result3,maxx),dist(result3,miny),dist(result3,maxy));*/
    if(max(max(dist_x(result,minx),dist_x(result,maxx)),max(dist_y(result,miny),dist_y(result,maxy)))>
        max(max(dist_x(result1,minx),dist_x(result1,maxx)),max(dist_y(result1,miny),dist_y(result1,maxy))))
    {
        result = result1;
    }
    if(max(max(dist_x(result,minx),dist_x(result,maxx)),max(dist_y(result,miny),dist_y(result,maxy)))>
        max(max(dist_x(result2,minx),dist_x(result2,maxx)),max(dist_y(result2,miny),dist_y(result2,maxy))))
    {
        result = result2;
    }
    if(max(max(dist_x(result,minx),dist_x(result,maxx)),max(dist_y(result,miny),dist_y(result,maxy)))>
        max(max(dist_x(result3,minx),dist_x(result3,maxx)),max(dist_y(result3,miny),dist_y(result3,maxy))))
    {
        result = result3;
    }

    printf("%d %d\n", result.x,result.y);

    fclose(stdin);
    fclose(stdout);

    return 0;
}

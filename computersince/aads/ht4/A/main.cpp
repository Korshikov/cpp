#include <algorithm>
#include <climits>
#include <cstdio>
#include <deque>

using namespace std;

const int m = 1073741824;

int main()
{
    freopen("sleepgame.in","r",stdin);
    freopen("sleepgame.out","w+",stdout);

    int n,k;
    scanf("%d %d",&n,&k);
    deque<int> board;
    int b;

    for(int i=0;i<n;++i)
    {
        scanf("%d",&b);
        board.push_back(b);
    }

    int x,y;
    for(int i=0;i<k;++i)
    {
        x = board.front();
        y = board.back();
        if(x<y)
        {
            board.pop_front();
            board.push_back((x+y)%m);
        }
        else
        {
            board.pop_back();
            board.push_front((m+y-x)%m);   
        }
    }

    while(!board.empty())
    {
        printf("%d ",board.front());
        board.pop_front();
    }
    
    fclose(stdin);
    fclose(stdout);

    return 0;
}

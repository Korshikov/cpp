#include <algorithm>
#include <climits>
#include <cstdio>
#include <set>

using namespace std;


int main()
{
    freopen("threemax.in","r",stdin);
    //freopen("threemax.out","w+",stdout);

    int n,k;
    scanf("%d %d",&n,&k);

    long long int ans = LLONG_MIN;
    int ans_l=0;
    int ans_r=0;
    long long int sum = 0;
    long long int min_sum = LLONG_MAX;
    int minus_pos = -1;
    int b;
    set<int> distinct;
    long long cur;

    for (int i=0; i<n; ++i) 
    {
        scanf("%d",&b);
        sum += b;

        if(distinct.find(b)==distinct.end())
        {
            distinct.insert(b);
        }
        cur = sum - min_sum;
        


        if ((cur > ans)&&(distinct.size()>=k)) 
        {
            ans = cur;
            ans_l = minus_pos + 1;
            ans_r = i;
        }
 
        if (sum < min_sum) 
        {
            printf("%lld %lld %d\n",min_sum,sum,i );
            min_sum = sum;
            minus_pos = i;
            distinct.clear();
        }
        /*
        sum += b;
        distinct.insert(b);
        
        if ((sum > ans)&&(distinct.size()>=k)) 
        {
            ans = sum;
            ans_l = minus_pos + 1;
            ans_r = i;
        }
 
        if ((sum < 0)||distinct.find(b)!=distinct.end())
        {
            sum = 0;
            distinct.clear();
            minus_pos = i;
        }
        */
    }

    printf("%lld\n%d %d",ans,ans_l+1,ans_r+1);


    fclose(stdin);
    fclose(stdout);

    return 0;
}

#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

int n,m,s;

const long long INF = LLONG_MAX / 8;


int main()
{
    
    freopen("negcycle.in","r",stdin);
    freopen("negcycle.out","w+",stdout);

    scanf("%d %d",&n,&m);


    
    vector<long long> distance(n,INF);
    vector<int> parent(n,-1);

    distance[s] = 0;
    

    
    fclose(stdin);
    fclose(stdout);

    return 0;
}

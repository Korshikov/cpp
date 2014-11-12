#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    freopen("incrementator.in","r",stdin);
    //freopen("incrementator.out","w+",stdout);
    
    std::unordered_map<string, int> mymap;
    
    char var[100000];
    int delta;
    while (scanf("%s %d\n",var,&delta) != EOF)
    {
        printf("%d\n",mymap[string(var)]+=delta);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

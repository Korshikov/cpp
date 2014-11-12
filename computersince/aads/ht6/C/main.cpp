#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;


    int a,b;
    long long unsigned n;

    unsigned int cur = 0; // беззнаковое 32-битное число
    unsigned int nextRand24() {
        cur = cur * a + b; // вычисляется с переполнениями
        return cur >> 8; 
    }
    unsigned int nextRand32() {
        unsigned int a = nextRand24(), b = nextRand24();
        return (a << 8) ^ b; 
    }


long long unsigned gcd (long long unsigned a, long long unsigned b) {
    return b ? gcd (b, a % b) : a;
}


int main() {
    freopen("finansist.in","r",stdin);
    //freopen("finansist.out","w+",stdout);


    scanf("%llu%d%d",&n,&a,&b);

    unsigned long long sum = 0;

    for(int i=0;i<n;++i)
    {
        sum+=nextRand32();
    }
    long long unsigned gcD = gcd(sum,n);

    printf("%llu/%llu\n",sum/gcD,n/gcD );
    


    fclose(stdin);
    fclose(stdout);

    return 0;
}

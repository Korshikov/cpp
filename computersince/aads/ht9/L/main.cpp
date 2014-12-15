
#include <algorithm>
#include <cstdio>
#include <climits>

using namespace std;

int main() {
	unsigned n,k,res=0;
	scanf("%u%u",&n,&k);

	if(n--<2)
	{
		printf("0\n");
		return 0;
	}

	if(k==0)
	{
		printf("-1\n");
		return 0;
	}

	while((k>1)&&(n>2))
	{
		n= n/2;
		++res;
		--k;
	}

	printf("%u\n", res+n-1);

    return 0;
}

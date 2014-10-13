#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

size_t in_pointer=0;
size_t find_pointer=0;
int n;
int m;

int a[300000];
int b[300000];



int main()
{
	freopen("find2.in","r",stdin);
	freopen("find2.out","w+",stdout);

	scanf("%d %d",&n,&m);

	for(int i=0;i<n;++i)
	{
		scanf("%d", a+i);
	}
	for(int i=0;i<m;++i)
	{
		scanf("%d", b+i);
	}

	for(find_pointer=0;(find_pointer<m);++find_pointer)
	{
		while(1)
		{
			if(in_pointer==n)
			{
				printf("NO\n");
				break;
			}
			if(a[in_pointer]<b[find_pointer])
			{
				++in_pointer;
				continue;
			}
			if(*(a+in_pointer)==*(b+find_pointer))
			{
				printf("YES\n");
				break;
			}
			if(*(a+in_pointer)>*(b+find_pointer))
			{
				printf("NO\n");
				break;
			}

		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
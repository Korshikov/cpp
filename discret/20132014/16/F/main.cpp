#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("antiqs.in","r",stdin);
    //freopen("antiqs.out","w+",stdout);
    int n;
    scanf("%d",&n);
    int *a = new int[n+1];
    for(int i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    for(int i=2;i<n;i++)
    {
        std::swap(a[i],a[i/2]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    delete[] a;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

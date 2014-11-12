#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <set>
#include <vector>
#include "array.cpp"

using namespace std;

Array<int> a(10,2);
Array<char> b(0);
Array< Array<int> > g(10, Array<int>(10,0));


int main()
{
    for(int i=0;i<a.size();++i)
    {
        //a[i] = i;
        a[i] = a[i]*2;
    }

    Array<int> e(a);

    for(int i=0;i<e.size();++i)
    {
        printf("%d ", e[i]);
        e[i] *= 10;
    }

    a = e;
    a = a;
    printf("\n%d\n",a.size());


    for(int i=0;i<a.size();++i)
    {
        printf("%d ", a[i]);
    }

    return 0;
}

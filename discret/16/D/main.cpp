#include <cstdio>

using namespace std;

typedef long double uses_t;

bool p(const int& n, uses_t* array)
{
    for(int i=2;i<n;i++)
    {
        array[i] = 2 * array[i - 1] - array[i - 2] + 2;
        if(array[i]<0)
        {
            return false;
        }
        if(array[i]>array[i-1])
        {
            return true;
        }
    }
    return true;
}

int main()
{
    int n;
    uses_t array[1000];
    freopen("garland.in","r",stdin);
    freopen("garland.out","w",stdout);
    /*freopen("inpit.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    scanf("%d",&n);
    float read;
    scanf("%f",&read);
    array[0] = read;
    uses_t right = array[0], left = 0;
    array[1] = (right+left) / 2;
    while ((left != array[1]) && (right != array[1])) {
        if (p(n,array))
        {
            right = array[1];
        }
        else
        {
            left = array[1];
        }
        array[1]= (left + right) / 2;
    }
    for(int i=2;i<n;i++)
    {
        array[i] = 2 * array[i - 1] - array[i - 2] + 2;
    }

    printf("%.2f",(float)array[n-1]);
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

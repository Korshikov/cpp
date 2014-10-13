#include <cstdio>
#include <algorithm>

using namespace std;

typedef unsigned int answer_type;

int* a;
int n;
int k;

bool calculate_answer(answer_type ans)
{
    int k1 = 0;
    for(int i=0;i<n;++i)
    {
        k1+=a[i]/ans;
        
    }
    return (k1>=k);
}

answer_type binarySearchByAnsver(answer_type left,answer_type right)
{
    if(right - left<=1)
    {
        if(calculate_answer(right))
        {
            return right;
        }
        return left;
    }
    if(calculate_answer((right + left)/2))
    {
        return binarySearchByAnsver(((right + left)/2),right);
    }
    else
    {
        return binarySearchByAnsver(left,((right + left)/2));
    }
}


int main()
{
    freopen("ropes.in","r",stdin);
    freopen("ropes.out","w+",stdout);
    scanf("%d %d",&n,&k);

    a = new int[n];
    int maxim=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        maxim = max(a[i],maxim);
    }
    
    printf("%d\n",binarySearchByAnsver(0,maxim));

    fclose(stdin);
    fclose(stdout);
    delete[] a;
    return 0;
}

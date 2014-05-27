#include <cstdio>

using namespace std;

int pos = 0;

template<typename T>
bool comp_n(T& a,T& b)
{
    return a[pos]<=b[pos];
}


template<typename T>
T* merge_(T* a,unsigned na,T* b,unsigned nb, bool (*comp)(T& a, T& b)){
    unsigned ia=0,ib=0;
    T* res = new T[na+nb];
    while((ia<na)&&(ib<nb)){
        if(comp(a[ia],b[ib])){
            res[ia+ib]=a[ia++];
        }else{
            res[ia+ib]=b[ib++];
        }
    }
    while(ia<na){
        res[ia+ib]=a[ia++];
    }
    while(ib<nb){
        res[ia+ib]=b[ib++];
    }

    return res;
}

template<typename T>
T* mergeSort_(T* a,unsigned na,bool (*comp)(T& a, T& b)){
    if(na<=1){
        return a;
    }
    T* a1 = mergeSort_(a,na/2,comp);
    T* a2 = mergeSort_(a+na/2, na-na/2,comp);
    return merge_(a1,na/2,a2,na-na/2,comp);
}


int main()
{
    freopen("radixsort.in","r",stdin);
    freopen("radixsort.out","w+",stdout);
    int n,l,k;
    scanf("%d %d %d",&n,&l,&k);
    char** a = new char*[n];
    for(int i=0;i<n;i++)
    {
        a[i]=new char[l];
        scanf("\n%s",a[i]);
    }
    for(pos=l-1;k>0;k--)
    {
        a = mergeSort_(a,n,comp_n);
        pos--;
    }
    for(int i = 0;i<n;i++)
    {
        printf("%s\n",a[i]);
    }
    for(int i=0;i<n;i++)
    {
        delete[] a[i];
    }
    delete[] a;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

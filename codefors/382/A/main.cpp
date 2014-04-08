#include <cstdio>
#include <cstring>

using namespace std;

char l[35],r[35],fre[35],b,fr[35];
int nl,nr,nf,n,i;

int main()
{
    scanf("%s",fre);
    n=strlen(fre);
    for(nl=0;nl<n;)
    {
        if(fre[nl]!='|')
        {
            l[nl]=fre[nl];
            nl++;

        }
        else
            break;
    }
    for(nr=0;nr+nl+1<n;)
    {
        r[nr]=fre[nl+nr+1];
        nr++;
    }
    scanf("%s",fr);
    nl=strlen(l);
    nr=strlen(r);
    nf=strlen(fr);
    n=nl+nr+nf;

    if((n&1)||(nl+nf<nr)||(nr+nf<nl))
    {
        printf("Impossible");
        return 0;
    }
    printf("%s",l);
    for(i=0;i<n/2-nl;i++)
        printf("%c",fr[i]);
    printf("|%s",r);
    for(;i<nf;i++)
        printf("%c",fr[i]);




    return 0;
}

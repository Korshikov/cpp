#include <algorithm>
#include <cstdio>
#include <climits>

using namespace std;

int main() {
    unsigned n;
    unsigned m;

    //freopen("field.in", "r", stdin);

    scanf("%u%u",&n,&m);
    unsigned field[m][n];
    unsigned mem[m][n];

    for(unsigned i=0;i<m;++i)
    {
        for(unsigned t=0;t<n;++t)
        {
            scanf("%u",&field[i][t]);
            mem[i][t] = UINT_MAX;
            
        }
        
    }

    //queue<pair<unsigned , unsigned > > next;
    mem[0][0]=0;
    //next.push(make_pair(0, 0));

    unsigned i,t;
     for(unsigned k =0; k<n+m-1;++k){
        for(i=min(k,m-1),t=k-i;i<m&&t<n;--i,++t){
              
                if(i+1<m)
                {
                    if(mem[i+1][t]>mem[i][t]+max(field[i+1][t],field[i][t])-min(field[i+1][t],field[i][t]))
                    {
                        mem[i+1][t]=mem[i][t]+max(field[i+1][t],field[i][t])-min(field[i+1][t],field[i][t]);
                        
                    }
                }
                if(t+1<n)
                {
                    if(mem[i][t+1]>mem[i][t]+max(field[i][t+1],field[i][t])-min(field[i][t+1],field[i][t]))
                    {
                        mem[i][t+1]=mem[i][t]+max(field[i][t+1],field[i][t])-min(field[i][t+1],field[i][t]);
                        
                    }
                }
        }

    }


    printf("%u",mem[m-1][n-1]);


    return 0;
}

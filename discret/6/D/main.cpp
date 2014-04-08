#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

int n,k;
int input[201][201];
char input_str[500];
long long k;


int main() {
    //freopen("part2num.in","r",stdin);
    //freopen("part2num.out","w+",stdout);



    scanf("%d %d",&n,&k);
    while(n!=0)
    {
    for(int t=0;t<k;t++)
    {
        scanf("%[^\n]s", input_str);
        int e=0;
        int bufer=0;
        for(unsigned int i=0;i<strlen(input_str);i++)
            if(input_str[i]==' ')
            {

                input[t][e]=bufer;
                e++;
                bufer=0;
            }
            else
                if((input_str[i]>='0')&&(input_str[i]<='9'))
                {
                    bufer= bufer*10+input_str[i]-'0';
                }
        if(bufer!=0)
        {
            input[t][e]=bufer;
            e++;
            bufer=0;
        }

    }
        bool fl = false;
for i = n - 1 downto 0
    if  можем добавить в конец подмножества элемент из used
        добавляем
        break
    for j = a[i].size - 1 downto 0
        if можем заменить элемент, другим элементом из массива used
           заменяем
           fl = true
           break
        used.add(a[i][j])   // удаляем элемент и добавляем его в массив
    if (fl) break
// далее выведем все получившиеся подмножества
sort(used)
for i = 0 to used.size - 1
   println(used[i])

        scanf("%d %d",&n,&k);
    }


    return 0;
}

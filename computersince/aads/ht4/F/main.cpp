#include <algorithm>
#include <climits>
#include <cstdio>
#include <stack>

using namespace std;


int main()
{
    freopen("check.in","r",stdin);
    freopen("check.out","w+",stdout);

    int s;
    stack<int> memory;

    while((s = getchar())!=EOF)
    {
        switch(s)
        {
            case '(':
                memory.push(1);
                break;
            case '[':
                memory.push(2);
                break;
            case '{':
                memory.push(3);
                break;
            case ']':
                if((memory.empty())||(memory.top() != 2))
                {
                    printf("NO\n");
                    return 0;
                }
                memory.pop();
                break;
            case ')':
                if((memory.empty())||(memory.top() != 1))
                {
                    printf("NO\n");
                    return 0;
                }
                memory.pop();
                break; 
            case '}':
                if((memory.empty())||(memory.top() != 3))
                {
                    printf("NO\n");
                    return 0;
                }
                memory.pop();
                break;   
        }
    }

    if(memory.empty())
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

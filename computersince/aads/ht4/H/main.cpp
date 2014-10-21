#include <algorithm>
#include <climits>
#include <cstdio>
#include <set>
#include <stack>

using namespace std;

size_t const MAX_N = 100001;


int main()
{
    freopen("brackets.in","r",stdin);
    freopen("brackets.out","w+",stdout);

    size_t array_pos = 0;
    char array[MAX_N];
    size_t left_pos[MAX_N];
    char s;
    stack<int> memory;    
    size_t pos_l=0;
    size_t pos_r=0;
    size_t prev_pos_l=0;
    size_t prev_pos_r=0;
    size_t now_pos_l=0;
    size_t now_pos_r=0;


    while((s = getchar())!=EOF)
    {
        array[array_pos]=s;
        left_pos[array_pos]=array_pos +1;
        switch(s)
        {
            case '(':
                memory.push(array_pos);
                break;
            case '[':
                memory.push(array_pos);
                break;
            case '{':
                memory.push(array_pos);
                break;
            case ']':
                if((!memory.empty())&&(array[memory.top()] == '['))
                {
                    now_pos_r = array_pos;
                    now_pos_l = memory.top();
                    if(now_pos_l > 0)
                    {
                        now_pos_l = left_pos[now_pos_l-1];
                    }
                    if((pos_r-pos_l)<(now_pos_r-now_pos_l))
                    {
                        pos_r = now_pos_r;
                        pos_l = now_pos_l;
                    }
                    left_pos[now_pos_r] = now_pos_l;
                    memory.pop();
                }
                else
                {
                    while(!memory.empty())
                    {
                        memory.pop();
                    }
                }

                break;
            case ')':
                if((!memory.empty())&&(array[memory.top()] == '('))
                {
                    now_pos_r = array_pos;
                    now_pos_l = memory.top();
                    if(now_pos_l > 0)
                    {
                        now_pos_l = left_pos[now_pos_l-1];
                    }
                    if((pos_r-pos_l)<(now_pos_r-now_pos_l))
                    {
                        pos_r = now_pos_r;
                        pos_l = now_pos_l;
                    }
                    left_pos[now_pos_r] = now_pos_l;
                    memory.pop();
                }
                else
                {
                    while(!memory.empty())
                    {
                        memory.pop();
                    }
                }
                break; 
            case '}':
                if((!memory.empty())&&(array[memory.top()] == '{'))
                {
                    now_pos_r = array_pos;
                    now_pos_l = memory.top();
                    if(now_pos_l > 0)
                    {
                        now_pos_l = left_pos[now_pos_l-1];
                    }
                    if((pos_r-pos_l)<(now_pos_r-now_pos_l))
                    {
                        pos_r = now_pos_r;
                        pos_l = now_pos_l;
                    }
                    left_pos[now_pos_r] = now_pos_l;
                    memory.pop();
                }
                else
                {
                    while(!memory.empty())
                    {
                        memory.pop();
                    }
                }
                break;   
        }
        array_pos++;
    }

    if(pos_r -pos_l > 0)
    {
        for(;pos_l<=pos_r;++pos_l)
        {
            printf("%c",array[pos_l]);
        }
    }



    fclose(stdin);
    fclose(stdout);

    return 0;
}

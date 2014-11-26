#include <algorithm>
#include <cstdio>
#include <stack>

using namespace std;

const int MAX_N = 3000001;

struct memory_el
{
    unsigned counter;
    unsigned prev;
    memory_el():counter(MAX_N)
    {}
};

memory_el memory[MAX_N];
stack<int> output;

int main() {
    unsigned n;
    scanf("%u",&n);
    if(n==1)
    {
        printf("0\n1");
        exit(0);
    }
    memory[1].counter=0;
    memory[1].prev=0;

    for(int i=1;i<n;++i)
    {
        if(memory[i+1].counter > memory[i].counter+1)
        {
            memory[i+1].counter = memory[i].counter+1;
            memory[i+1].prev = i;
        }
        if(memory[i*2].counter > memory[i].counter+1)
        {
            memory[i*2].counter = memory[i].counter+1;
            memory[i*2].prev = i;
            if(i*2==n)
            {
                break;
            }
        }
        if(memory[i*3].counter > memory[i].counter+1)
        {
            memory[i*3].counter = memory[i].counter+1;
            memory[i*3].prev = i;
            if(i*3==n)
            {
                break;
            }
        }
    }

    printf("%u\n",memory[n]);
    output.push(n);
    while(memory[n].prev!=1)
    {
        output.push(n=memory[n].prev);
    }
    printf("1 ");
    while(!output.empty())
    {
        printf("%u ",output.top());
        output.pop();
    }
    return 0;
}
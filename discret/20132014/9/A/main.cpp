#include <cstdio>
#include <cstdlib>
#include <cassert>

using namespace std;

class vectorStack {
private:
    int *stackArray, stackStart, stackEnd, stackLength;

    void resizeStackArray(int newLength)
    {
        assert (stackEnd-stackStart <= newLength);
        int *newStackArray = (int*) malloc(sizeof(int)*newLength);
        for(int i=stackStart;i<=stackEnd;i++){
            newStackArray[i-stackStart]=stackArray[i];
        }
        free(stackArray);
        stackArray=newStackArray;
        stackLength=newLength;
        return;
    }
public:
    vectorStack(){
        stackLength=64;
        stackStart=0;
        stackEnd=0;
        stackArray = (int*) malloc(sizeof(int)*stackLength);
    }
    void push(int item){
        if (stackEnd-stackStart+1>stackLength)
            resizeStackArray(stackLength*2);
        stackArray[stackEnd++]=item;
        return;
    };

    int pop(void){
        assert (stackEnd-stackStart>0);
        return stackArray[--stackEnd];
    }
};



int main(void)
{
    int n,b;
    char d;
    vectorStack stack1;
    freopen("stack1.in","r",stdin);
    freopen("stack1.out","w+",stdout);
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        scanf("%c",&d);
        if(d=='+'){
            scanf("%d\n",&b);
            stack1.push(b);
            continue;
        }else{
            scanf("\n");
            printf("%d\n",stack1.pop());
            continue;
        }
    }

    return 0;
}


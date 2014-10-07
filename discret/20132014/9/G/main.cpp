#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <string>
#include <iostream>

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
    ~vectorStack(){
        free(stackArray);
    }

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

    bool isEmpty(){
        return (stackEnd-stackStart==0);
    }
};



int main(void)
{
    vectorStack* stack1 = new vectorStack;
    freopen("postfix.in","r",stdin);
    freopen("postfix.out","w+",stdout);


        int b1,b2;

        char c;
        while (std::cin.get(c))
        {
            if((c>='0')&&(c<='9'))
                stack1->push(c-'0');
            if(c=='+'){
                b1=stack1->pop();
                b2=stack1->pop();
                stack1->push(b2+b1);
            }
            if(c=='-'){
                b1=stack1->pop();
                b2=stack1->pop();
                stack1->push(b2-b1);
            }
            if(c=='*'){
                b1=stack1->pop();
                b2=stack1->pop();
                stack1->push(b2*b1);
            }
        }
    printf("%d",stack1->pop());

    delete(stack1);

    return 0;
}


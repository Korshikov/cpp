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
    freopen("brackets.in","r",stdin);
    freopen("brackets.out","w+",stdout);
    std::string line;
    while (std::getline(std::cin, line))
    {
        int i,len = line.length();
        bool ret=false;
        for(i=0;i<len;i++)
        {
            if(line[i]=='(')
            {
                stack1->push(1);
                continue;
            }
            if(line[i]=='[')
            {
                stack1->push(2);
                continue;
            }
            if(line[i]==']')
            {
                if(stack1->isEmpty()){
                    printf("NO\n");
                    ret=true;
                    break;
                }
                if(stack1->pop()!=2){
                    printf("NO\n");
                    ret=true;
                    break;
                }
            }
            if(line[i]==')')
            {
                if(stack1->isEmpty()){
                    printf("NO\n");
                    ret=true;
                    break;
                }
                if(stack1->pop()!=1){
                    printf("NO\n");
                    ret=true;
                    break;
                }
            }
        }
        if(!ret){
            if((i==len)&&(stack1->isEmpty()))
                printf("YES\n");
            else
                printf("NO\n");
        }
        delete(stack1);
        stack1 = new vectorStack;
    }


    delete(stack1);
    return 0;
}


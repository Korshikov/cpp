#include <cstdio>
#include <cstdlib>
#include <cassert>

using namespace std;

class vectorQueue {
private:
    int *queueArray, queueStart, queueEnd, queueLength;

    void resizeQueueArray(int newLength)
    {
        assert (queueSize() <= newLength);
        int *newQueueArray = (int*) malloc(sizeof(int)*newLength);
        if (queueStart< queueEnd) {
            for (int i = queueStart; i < queueEnd; i++) {
                newQueueArray[i - queueStart] = queueArray[i];
                }
                queueEnd = queueEnd - queueStart;
                queueStart = 0;
        } else {
            for (int i = queueStart; i < queueLength; i++) {
                newQueueArray[i - queueStart] = queueArray[i];
                }
            for (int i = 0; i <= queueEnd; i++) {
                newQueueArray[i + queueLength - queueStart] = queueArray[i];
                }
            queueEnd = queueLength - 1;
            queueStart = 0;
            }
        free(queueArray);
        queueArray=newQueueArray;
        queueLength=newLength;
        return;
    }

    int queueSize(void){
     if (queueEnd >= queueStart) {
            return queueEnd - queueStart;
        } else {
            return (queueLength - queueStart) + queueEnd;
        }
    }
public:
    vectorQueue(){
        queueLength=64;
        queueStart=0;
        queueEnd=0;
        queueArray = (int*) malloc(sizeof(int)*queueLength);
    }
    void push(int item){
        if (queueSize()+1>=queueLength)
            resizeQueueArray(queueLength*2);
        queueArray[queueEnd++]=item;
        if(queueEnd==queueLength)
            queueEnd=0;
        return;
    };

    int pop(void){
        assert (queueSize()>0);
        int ret = queueArray[queueStart++];
        if(queueStart==queueLength)
            queueStart=0;
        return ret;
    }
};



int main(void)
{
    int n,b;
    char d;
    vectorQueue queue1;
    freopen("queue1.in","r",stdin);
    freopen("queue1.out","w+",stdout);
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        scanf("%c",&d);
        if(d=='+'){
            scanf("%d\n",&b);
            queue1.push(b);
            continue;
        }else{
            scanf("\n");
            printf("%d\n",queue1.pop());
            continue;
        }
    }


    return 0;
}


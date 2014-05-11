#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <climits>

using namespace std;

typedef struct{
    int key;
    int addOperationNumber;
} heapType;

class binary_heap {
public:
    heapType *heap;
    int  heapSize,heapLength;

    binary_heap(unsigned int n=64){
        heapSize = 0;
        heap = (heapType*) malloc( sizeof(heapType) * n);
        heapLength = n;
    }

    ~binary_heap(){
        if(heap) free(heap);
    }

    void add(int item,int operationNumber=0){
        if(heapSize+1 >= heapLength){
            reSize(heapLength*2);
        }
        heap[heapSize+1].key=item;
        heap[heapSize+1].addOperationNumber=operationNumber;
        checkup(++heapSize);
    }

    int extract_min(){
        if(heapSize ==0) return INT_MIN;
        int ret = heap[1].key;
        heap[1] = heap[heapSize--];
        if((heapSize*4 < heapLength)&&(heapLength>64)){
            reSize(heapLength/2);
        }
        checkdown(1);
        return ret;
    }

    void decreaseKey(int operationNumber,int newKey){
        int old_value=0, elemtntNumber=0;
        for(int i=1;i<=heapSize;++i){
            if(heap[i].addOperationNumber==operationNumber){
                old_value=heap[i].key;
                elemtntNumber=i;
                heap[i].key=newKey;
                break;
            }
        }
        if(old_value<newKey){
            checkdown(elemtntNumber);
        }else{
            checkup(elemtntNumber);
        }
        return;
    }

private:
    void reSize(int n){
        heapType *heapNew = (heapType*) malloc(sizeof(heapType)*n);
        for(int i=1;i<=heapSize;i++){
            heapNew[i]=heap[i];
        }
        free(heap);
        heapLength = n;
        heap = heapNew;
    }

    void checkup(int children){
        int parent= children / 2;
        if(parent == 0){
            return;
        }
        if(heap[parent].key> heap[children].key){
            swap(heap[parent],heap[children]);
            checkup(parent);
        }
    }

    void checkdown(int parent){
        int children = parent*2;
        if(children > heapSize){
            return;
        }
        if((children+1<=heapSize)&&(heap[children+1].key<heap[children].key)){
            ++children;
        }
        if(heap[children].key<heap[parent].key){
            swap(heap[children],heap[parent]);
            checkdown(children);
        }
    }
};


int main()
{
    //cout << INT_MIN;
    binary_heap heap;
    int n,b;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&b);
        heap.add(b);
    }
    for(int i=0;i<n;i++){
        printf("%d ",heap.extract_min());
    }



    return 0;
}

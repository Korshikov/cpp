#include <cstdio>
#include <cstdlib>
#include <cassert>

using namespace std;

class vectorQueue {
private:
    struct queueItem{
    int item;
    queueItem *next;
    };

    queueItem *head,*tail;

public:
    vectorQueue(){
        head=NULL;
        tail=NULL;
    }
    void push(int item){
        queueItem *newItem = (queueItem*) malloc(sizeof(queueItem));
        newItem->next=NULL;
        if(tail!=NULL)
            tail->next=newItem;
        newItem->item=item;
        if(head==NULL){
            head=newItem;
        }
        tail=newItem;
        return;
    };

    int pop(void){
        assert (head!=NULL);
        int res=head->item;
        queueItem *head_=head;
        head = head->next;
        if (head_==tail)
            tail=NULL;
        free(head_);
        return res;
    }
};



int main(void)
{
    int n,b;
    char d;
    vectorQueue queue1;
    freopen("queue2.in","r",stdin);
    freopen("queue2.out","w+",stdout);
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


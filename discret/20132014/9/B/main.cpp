#include <cstdio>
#include <cstdlib>
#include <cassert>

using namespace std;

class vectorStack {
private:
    struct stackItem{
    int item;
    stackItem *prev;
    };

    stackItem *head;

public:
    vectorStack(){
        head=NULL;
    }
    void push(int item){
        stackItem *newItem = (stackItem*) malloc(sizeof(stackItem));
        newItem->prev=head;
        newItem->item=item;
        head=newItem;
        return;
    };

    int pop(void){
        assert (head!=NULL);
        int res=head->item;
        stackItem *head_=head;
        head = head->prev;
        free(head_);
        return res;
    }
};



int main(void)
{
    int n,b;
    char d;
    vectorStack stack1;
    freopen("stack2.in","r",stdin);
    freopen("stack2.out","w+",stdout);
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


#include <cstdlib>
#include <cstdio>

using namespace std;



struct lis{
    int val;
    lis* prev;
    lis* next;

    lis(int val){
        prev=NULL;
        next=NULL;
        this->val=val;
    }

    lis(int val,lis* preve){
        prev=preve;
        if(preve!=NULL){
            preve->next=this;
        }
        next=NULL;
        this->val=val;
    }

    ~lis(){
        if(prev!=NULL){
            prev->next=next;
        }
        if(next!=NULL){
            next->prev=prev;
        }
    }
};

lis* a[3000000];

int hashFunction(int input){
    return abs(input%2999999);
}

lis* finde(int key){
    int index = hashFunction(key);
    lis* thi = a[index];
    if(thi == NULL){
        return NULL;
    }
    while((thi->next!=NULL)&&(thi->val!=key)){
        thi=thi->next;
    }
    return thi;
}



int main()
{
    freopen("set.in","r",stdin);
    freopen("set.out","w+",stdout);

    char c;
    int b;
    lis* buf;
    for(int i=0;i<3000000;i++){
        a[i]=NULL;
    }



    while((scanf("%c",&c)!=EOF)&&(c!=EOF)){
        switch(c){
        case 'i':
            scanf("nsert %d\n",&b);
            buf = finde(b);
            if((buf==NULL)||(buf->val!=b)){
                lis* inserted = new lis(b,buf);
                if(buf!=NULL){
                    buf->next = inserted;
                }else{
                    a[hashFunction(b)]=inserted;
                }
            }

            break;
        case 'e':
            scanf("xists %d\n",&b);
            buf = finde(b);
            if((buf!=NULL)&&(buf->val==b)){
                printf("true\n");
            }else{
                printf("false\n");
            }
            break;
        case 'd':
            scanf("elete %d\n",&b);
            buf = finde(b);
            if((buf!=NULL)&&(buf->val==b)){
                if(buf==a[hashFunction(b)]){
                    a[hashFunction(b)]=buf->next;
                }
                delete buf;
            }
            break;
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

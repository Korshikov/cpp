#include <cstdlib>
#include <cstdio>
#include <string>
#include <functional>
#include <iostream>

using namespace std;

std::hash<std::string> str_hash;


struct lis{
    string key;
    string value;
    lis* prev;
    lis* next;

    lis(string key,string val){
        prev=NULL;
        next=NULL;
        this->value=val;
        this->key=key;
    }

    lis(string key,string val,lis* preve){
        prev=preve;
        if(preve!=NULL){
            preve->next=this;
        }
        next=NULL;
        this->value=val;
        this->key=key;
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

int hashFunction(string input){
    return str_hash(input)%2999999;
}

lis* finde(string key){
    int index = hashFunction(key);
    lis* thi = a[index];
    if(thi == NULL){
        return NULL;
    }
    while((thi->next!=NULL)&&(thi->key!=key)){
        thi=thi->next;
    }
    return thi;
}



int main()
{
    freopen("map.in","r",stdin);
    freopen("map.out","w+",stdout);

    char c,c_key[25],c_value[25];
    string key,value;
    lis* buf;
    for(int i=0;i<3000000;i++){
        a[i]=NULL;
    }



    while((scanf("%c",&c)!=EOF)&&(c!=EOF)){
        switch(c){
        case 'p':
            scanf("ut %s %s\n",c_key,c_value);
            key= string(c_key);
            value= string(c_value);
            buf = finde(key);
            if((buf==NULL)||(buf->key!=key)){
                lis* inserted = new lis(key,value,buf);
                if(buf!=NULL){
                    buf->next = inserted;
                }else{
                    a[hashFunction(key)]=inserted;
                }
            }else if((buf!=NULL)&&(buf->key==key)){
                buf->value=value;
            }

            break;
        case 'g':
            scanf("et %s\n",c_key);
            key=string(c_key);
            buf = finde(key);
            if((buf!=NULL)&&(buf->key==key)){
                printf("%s\n",buf->value.c_str());
            }else{
                printf("none\n");
            }
            break;
        case 'd':
            scanf("elete %s\n",c_key);
            key=string(c_key);
            buf = finde(key);
            if((buf!=NULL)&&(buf->key==key)){
                if(buf==a[hashFunction(key)]){
                    a[hashFunction(key)]=buf->next;
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

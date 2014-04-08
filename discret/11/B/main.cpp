#include <cstdio>
#include <climits>
#include <cstdlib>

using namespace std;

typedef long int keyType;
#define MAX_keyType LONG_MAX
#define MIN_keyType LONG_MIN


class SplaySerchTree{
public:
    SplaySerchTree(){
        root=NULL;
        maxInPath=NULL;
        minInPath=NULL;
    }

    ~SplaySerchTree(){
        memFree(root);
    }
    bool isExist(keyType key){
        return isExist(root,key);
    }

    void ins(keyType key){
        if(isExist(key)){
            return;
        }
        Node* node = (Node*) malloc(sizeof(Node));
        node->left=NULL;
        node->right=NULL;
        node->parent=NULL;
        node->key=key;
        if(root!=NULL){
            ins(root,node);
            splay(node);
        }else{
            root=node;
        }
    }



    void del(keyType key){
        Node* removeoble = searchInTree(root,key);
        if(removeoble==NULL)
        {
            return;
        }
        del(removeoble);
    }

    keyType next(keyType key){
        Node* node = nextNode(key);
        return (node==NULL?MIN_keyType:node->key);
    }

    keyType prev(keyType key){
        Node* node = prevNode(key);
        return (node==NULL?MAX_keyType:node->key);
    }




private:
    struct Node{
        keyType key;
        Node* left;
        Node* right;
        Node* parent;
        Node(){
            right=NULL;
            left=NULL;
            parent=NULL;
        }
    };

    Node* root;
    Node* maxInPath;
    Node* minInPath;

    void del(Node* removeoble){
        Node* moved;
        if((removeoble->left!=NULL)&&(removeoble->right!=NULL)){
            //moved=nextNode(removeoble->key);
            if (removeoble->right!=NULL){
                moved = minim(removeoble->right);
            }else{
                moved = minInPath;
            }
            int mk=moved->key;
            del(moved);
            removeoble->key=mk;
        }else
        if((removeoble->left!=NULL)||(removeoble->right!=NULL)){
            moved = (removeoble->left==NULL?removeoble->right:removeoble->left);
            if(removeoble->parent==NULL){
                root = moved;
                moved->parent=NULL;
                free(removeoble);
                return;
            }
            if(removeoble->parent->left==removeoble){
                removeoble->parent->left=moved;
                moved->parent=removeoble->parent;
            }else{
                removeoble->parent->right=moved;
                moved->parent=removeoble->parent;
            }
            free(removeoble);
        }else{
            if((removeoble->left==NULL)&&(removeoble->left==NULL)){
                if(removeoble->parent==NULL){
                    root=NULL;
                    free(removeoble);
                    return;
                }
                if(removeoble->parent->left==removeoble){
                    removeoble->parent->left=NULL;
                }else{
                    removeoble->parent->right=NULL;
                }
                free(removeoble);
            }
        }
    }

    Node* nextNode(keyType key){
        Node* node = searchInTree(root,key);
        if ((node != NULL)&&(node->right!=NULL)){
                return minim(node->right);
        }
        if(minInPath!=NULL){
            splay(minInPath);
        }
        return (((minInPath==NULL)||(minInPath->key<=key))?NULL:minInPath);
    }

    Node* prevNode(keyType key){
        Node* node = searchInTree(root,key);
        if ((node != NULL)&&(node->left!=NULL)){
            return maxim(node->left);
        }
        if(maxInPath!=NULL){
            splay(maxInPath);
        }
        return (((maxInPath==NULL)||(maxInPath->key>=key))?NULL:maxInPath);
    }


    void ins(Node* tree1, Node* tree2){
        if(tree2->key>tree1->key){
            if(tree1->right!=NULL){
                ins(tree1->right,tree2);
                return;
            }else{
                tree1->right=tree2;
                tree2->parent=tree1;
                return;
            }
        }else{
            if(tree1->left!=NULL){
                ins(tree1->left,tree2);
                return;
            }else{
                tree1->left=tree2;
                tree2->parent=tree1;
                return;
            }
        }

    }

    void memFree(Node* item){
        if(item!=NULL)
        {
            memFree(item->left);
            memFree(item->right);
            free(item);
        }
    }

    Node* searchInTree(Node* item,keyType key){
        if(item==root){
            maxInPath=NULL;
            minInPath=NULL;
        }
        if((item==NULL)||(item->key==key)){
            return item;
        }
        if(item->key > key){
            if(((minInPath==NULL)||(minInPath->key>item->key))){
                minInPath=item;
            }
            return searchInTree(item->left,key);
        }else{
            if(((maxInPath==NULL)||(maxInPath->key<item->key))){
                maxInPath=item;
            }
            return searchInTree(item->right,key);
        }
    }

    bool isExist(Node* item,keyType key){
        if(item==NULL){
            return false;
        }
        if(item->key==key){
            splay(item);
            return true;
        }
        if(item->key > key){
            return isExist(item->left,key);
        }else{
            return isExist(item->right,key);
        }
    }

    Node* minim(Node* node){
        if(node->left==NULL){
            splay(node);
            return node;
        }
        return minim(node->left);
    }

    Node* maxim(Node* node){
        if(node->right==NULL){
            splay(node);
            return node;
        }
        return maxim(node->right);
    }

    void left_rotate(Node* parent){
        Node* node = parent->right;
        parent->right = node->left;
        if(node->left!=NULL){
            node->left->parent = parent;
        }
        node->parent=parent->parent;
        if(parent->parent==NULL){
            root=node;
        }else if(parent==parent->parent->left){
            parent->parent->left=node;
        }else{
            parent->parent->right=node;
        }
        node->left=parent;
        parent->parent=node;
    }

    void right_rotate(Node* parent){
        Node* node = parent->left;
        parent->left = node->right;
        if(node->right!=NULL){
            node->right->parent=parent;
        }
        node->parent = parent->parent;
        if(parent->parent==NULL){
            root=node;
        }else if(parent==parent->parent->left){
            parent->parent->left=node;
        }else{
            parent->parent->right=node;
        }
        node->right=parent;
        parent->parent=node;
    }

    void splay(Node* node){
        if(node==NULL){
            return;
        }
        while(node->parent!=NULL){
            if(node->parent->parent==NULL){ //zig
                if(node->parent->left==node){
                    right_rotate(node->parent);
                }else{
                    left_rotate(node->parent);
                }
            }else if((node->parent->left==node)&&(node->parent->parent->left==node->parent)){ //zig-zig 2 right
                right_rotate(node->parent->parent);
                right_rotate(node->parent);
            }else if((node->parent->right==node)&&(node->parent->parent->right==node->parent)){ //zig-zig 2 left
                left_rotate(node->parent->parent);
                left_rotate(node->parent);
            }else if((node->parent->left==node)&&(node->parent->parent->right==node->parent)){ //zig-zag right left
                right_rotate(node->parent);
                left_rotate(node->parent);
            }else{ //zig-zag left right
                left_rotate(node->parent);
                right_rotate(node->parent);
            }
        }
    }

} ;

int main()
{
    SplaySerchTree tree;
    freopen("bst.in","r",stdin);
    freopen("bst.out","w+",stdout);
    char c;
    long b;
    while ((scanf("%c", &c) != EOF)&&(c!=EOF)){
        switch(c){
        case 'i':
            scanf("nsert %ld\n",&b);
            tree.ins(b);
            break;
        case 'd':
            scanf("elete %ld\n",&b);
            tree.del(b);
            break;
        case 'e':
            scanf("xists %ld\n",&b);
            printf((tree.isExist(b)?"true\n":"false\n"));
            break;

        case 'n':
            scanf("ext %ld\n",&b);
            b = tree.next(b);
            if(b==MIN_keyType){
                printf("none\n");
            }else{
                printf("%ld\n",b);
            }
            break;
        case 'p':
            scanf("rev %ld\n",&b);
            b = tree.prev(b);
            if(b==MAX_keyType){
                printf("none\n");
            }else{
                printf("%ld\n",b);
            }
            break;
    }
    }



    fclose(stdin);
    fclose(stdout);
    return 0;
}

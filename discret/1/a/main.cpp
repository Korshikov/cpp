#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct para
{
    int a,b;
};

struct node
{
int frequency;
node* left;
node* right;
};


struct node_oth
{
    int levl;
    node el;
    node_oth *next,*prev;
};

node_oth *o_first, *o_end;

int n;
node* elements;

node root,*a,*b;

bool comp(node a,node b)
{
    return a.frequency<b.frequency;
}

long long unsigned see_next_elem()
{
node_oth *elem,*b;
elem = o_first;
if(elem->el.left!=NULL)
{
    b = new node_oth;
    b->levl = elem->levl+1;
    b->el = *elem->el.left;
    b->prev = o_end;
    b->next = NULL;
    o_end->next = b;
    o_end = b;
}
if(elem->el.right!=NULL)
{
    b = new node_oth;
    b->levl = elem->levl+1;
    b->el = *elem->el.right;
    b->prev = o_end;
    b->next = NULL;
    o_end->next = b;
    o_end = b;
}
o_first = elem->next;
if ((elem->el.right==NULL)||(elem->el.left==NULL))
    return elem->levl*elem->el.frequency;
else
    return 0;

}

long long unsigned sum=0;

int main()
{
    freopen("huffman.in","r",stdin);
    freopen("huffman.out","w+",stdout);
    scanf("%d",&n);
    elements=(node*) malloc(sizeof(node) * n);
    for(int i =0; i<n;i++)
    {
        scanf("%d",&elements[i].frequency);
    }
    if(n==1)
    {
        printf("%d",elements[0].frequency);
        return 0;
    }
    do
    {
        sort(elements,elements+n,comp);
        a = new node;
        *a= elements[0];
        b = new node;
        *b = elements[1];

        elements[0].left = a;
        elements[0].right = b;
        elements[0].frequency = a->frequency+b->frequency;
        elements[1]=elements[n-1];
        n--;
    }while(n>1);
    root = elements[0];
    o_first = new node_oth;
    o_first->levl = 0;
    o_first->el = elements[0];
    o_end=o_first;

    while(o_first != NULL){
        sum += see_next_elem();
        if(o_first!=NULL)
        {
        free(o_first->prev);
        o_first->prev = NULL;
        }
    }


    printf("%llu",sum);

    return 0;
}

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>


using namespace std;

struct node
{
unsigned long long  vst,elem_number;
node* left;
node* right;
};



bool comp(node *a,node *b)
{
    return a->vst>b->vst;
}

long long unsigned get_len(node *root,int levl = 0,vector<char> now)
{
    if((root->left==NULL)||(root->right==NULL))
    {
        return root->vst*levl;
    }
    else
    {
        long long unsigned sum =0;
        if(root->left!=NULL)
        {
            now.push_back(0);
            sum += get_len(root->left,levl+1);
            now.pop_back();
        }
        if(root->right!=NULL)
        {

            sum += get_len(root->right,levl+1);
        }
        return sum;
    }
}

int n,vst[3000],el,n_ob;
node **huffman;
vector<char> results_code[3000];

int main()
{
    freopen("huffman.in","r",stdin);
    freopen("huffman.out","w+",stdout);
    scanf("%d",&n);
    if(n==1)
    {
        scanf("%d",&n);
        printf("%d\n0",n);
        return 0;
    }
    huffman = (node**) malloc(sizeof(node*)*(n+(n-1)));
    for(int i=0;i<n;i++)
    {
        huffman[el]= (node*) malloc(sizeof(node));
        huffman[el]->left=NULL;
        huffman[el]->right=NULL;
        huffman[el]->elem_number=i;
        scanf("%llu",&(huffman[el++]->vst));
    }
    n_ob = n;

    while(n_ob>1)
    {
        sort(huffman,huffman+n_ob,comp);
        huffman[el++]= (node*) malloc(sizeof(node));
        swap(huffman[el-1],huffman[n_ob-2]);
        huffman[n_ob-2]->vst = huffman[n_ob-1]->vst + huffman[el-1]->vst;
        huffman[n_ob-2]->left = huffman[n_ob-1];
        huffman[n_ob-2]->right = huffman[el-1];
        n_ob--;
    }

    printf("%llu",get_len(huffman[0]));

    for(int i=0;i<el;i++)
        free(huffman[i]);
    free(huffman);
    return 0;
}

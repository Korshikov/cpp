#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef  int SegmentTreeNodeValueType;
const SegmentTreeNodeValueType netralElement = 0;


struct SegmentTreeNode {
    //long long left,right;
    SegmentTreeNodeValueType value;

    SegmentTreeNode() {
        value = netralElement;
    }
};

struct SegmentTree {
    SegmentTree(SegmentTreeNodeValueType *a, const long long &n) {
        treeN = 1 << (SegmentTreeNodeValueType) ceil(log2(n));
        treeLength = treeN << 1;
        tree = new SegmentTreeNode[treeLength];
        for (int i = treeN - 1; i < n + treeN - 1; i++) {
            tree[i].value = a[i - treeN + 1];
        }
        for (int i = treeN - 2; i >= 0; i--) {
            tree[i].value = functionInNode(tree[i * 2 + 1].value, tree[i * 2 + 2].value);
        }
    }

    ~SegmentTree() {
        delete  []tree;
    }

    SegmentTreeNodeValueType request(long long left, long long right) {
        return request(left, right, 0, 0, treeN - 1);
    }

    void modifideList(long long elementNumber, SegmentTreeNodeValueType newValue) {
        tree[treeN + elementNumber - 1].value = newValue;
        updateParentValue(treeN + elementNumber - 1);
    }

private:
    SegmentTreeNode *tree;
    long long int treeLength, treeN;

    SegmentTreeNodeValueType functionInNode(SegmentTreeNodeValueType left, SegmentTreeNodeValueType right) {
        return left+ right;
    }

    SegmentTreeNodeValueType request(long long left, long long right, long long nodeNumber, long long tLeft, long long tRight) {
        if (left > right) {
            return netralElement;
        }
        if ((left == tLeft) && (right == tRight)) {
            return tree[nodeNumber].value;
        }
        long long tMidle = tLeft + ((tRight - tLeft) / 2);
        return functionInNode(
                request(left, min(right, tMidle), nodeNumber * 2 + 1, tLeft, tMidle),
                request(max(left, tMidle + 1), right, nodeNumber * 2 + 2, tMidle + 1, tRight)
        );
    }

    void updateParentValue(long long nodeNumber) {
        if (nodeNumber == 0) {
            return;
        }
        long long parentNumber = (nodeNumber - 1) / 2;
        SegmentTreeNodeValueType newValue = functionInNode(tree[parentNumber * 2 + 1].value, tree[parentNumber * 2 + 2].value);
        if (tree[parentNumber].value != newValue) {
            tree[parentNumber].value = newValue;
            updateParentValue(parentNumber);
        }
    }

};

int main() {
    freopen("sum0.in","r",stdin);
    freopen("sum0.out","w+",stdout);
    long long int n;
    SegmentTreeNodeValueType *a;
    long long x,y,a0;
    scanf("%lld", &n);
    scanf("%lld%lld%lld",&x,&y,&a0);
    a = new SegmentTreeNodeValueType[n];
    a[0] = a0;
    for (int i = 1; i < n; i++)
    {
        a[i]=((x*a[i-1] + y) % 65536);
    }

    SegmentTree tree(a, n);
    delete[] a;


    long long m,z,t,b0,b1;
    scanf("%lld%lld%lld%lld",&m,&z,&t,&b0);
    //unsigned *b = new unsigned[2*m+2];
    //b[0]=b0;
    /*for(int i= 1;i<2*m+2;++i)
    {
        b[i]=(z*b[i-1] + t) % 65536;
    }
    delete[] b;*/

    b1 = (z*b0+t)% 65536;

    long long s= tree.request(min(b0 % n, b1 %n),max(b0 % n, b1 %n));
    for(int i=1;i<m;i++)
    {
        b0 = (z*b1+t)% 65536;
        b1 = (z*b0+t)% 65536;
        s+=tree.request(min(b0 % n, b1 %n),max(b0 % n, b1 %n));
    }

    printf("%lld\n",s );

    /*while ((scanf("%c",&c)!= EOF)&&(c!= EOF)){
        if(c=='\n'){
            continue;
        }
        switch(c){
            case 's':
                if((scanf("%c",&c)=='e')||(c=='e')){
                    scanf("t %lld %lld\n",&b1,&b2);
                    tree.modifideList(b1-1, b2);
                }else{
                    scanf("m %lld %lld\n",&b1,&b2);
                    printf("%lld\n", tree.request(b1-1,b2-1));
                }
                break;
        }
    }*/

    fclose(stdin);
    fclose(stdout);
    return 0;
}

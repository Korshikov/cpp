#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

typedef  int SegmentTreeNodeValueType;
const SegmentTreeNodeValueType netralElement = INT_MIN;


struct SegmentTreeNode {
    //long long left,right;
    SegmentTreeNodeValueType value;

    SegmentTreeNode() {
        value = netralElement;
    }
};

struct SegmentTree {
    SegmentTree(SegmentTreeNodeValueType *a, const unsigned &n) {
        treeN = 1 << (SegmentTreeNodeValueType) ceil(log2(n));
        treeLength = treeN << 1;
        tree = new SegmentTreeNode[treeLength];
        for (unsigned i = treeN - 1; i < n + treeN - 1; i++) {
            tree[i].value = a[i - treeN + 1];
        }
        for (unsigned i = treeN - 2; i > 0; i--) {
            tree[i].value = functionInNode(tree[i * 2 + 1].value, tree[i * 2 + 2].value);
        }
        tree[0].value = functionInNode(tree[1].value, tree[2].value);
    }

    ~SegmentTree() {
        delete  []tree;
    }

    SegmentTreeNodeValueType request(unsigned left, unsigned right) {
        return request(left, right, 0, 0, treeN - 1);
    }

    void modifideList(unsigned elementNumber, SegmentTreeNodeValueType newValue) {
        tree[treeN + elementNumber - 1].value = newValue;
        updateParentValue(treeN + elementNumber - 1);
    }

private:
    SegmentTreeNode *tree;
    unsigned treeLength, treeN;

    SegmentTreeNodeValueType functionInNode(SegmentTreeNodeValueType left, SegmentTreeNodeValueType right) {
        return max(left, right);
    }

    SegmentTreeNodeValueType request(unsigned left, unsigned right, unsigned nodeNumber, unsigned tLeft, unsigned tRight) {
        if (left > right) {
            return netralElement;
        }
        if ((left == tLeft) && (right == tRight)) {
            return tree[nodeNumber].value;
        }
        unsigned tMidle = tLeft + ((tRight - tLeft) / 2);
        return functionInNode(
                request(left, min(right, tMidle), nodeNumber * 2 + 1, tLeft, tMidle),
                request(max(left, tMidle + 1), right, nodeNumber * 2 + 2, tMidle + 1, tRight)
        );
    }

    void updateParentValue(unsigned nodeNumber) {
        if (nodeNumber == 0) {
            return;
        }
        unsigned parentNumber = (nodeNumber - 1) / 2;
        SegmentTreeNodeValueType newValue = functionInNode(tree[parentNumber * 2 + 1].value, tree[parentNumber * 2 + 2].value);
        if (tree[parentNumber].value != newValue) {
            tree[parentNumber].value = newValue;
            updateParentValue(parentNumber);
        }
    }

};

int main() {
    freopen("rmq.in","r",stdin);
    //freopen("rmq.out","w+",stdout);
    unsigned n;
    SegmentTreeNodeValueType *a;

    scanf("%u", &n);
    a = new SegmentTreeNodeValueType[n];
    for (unsigned i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    SegmentTree tree(a, n);

    char c;
    unsigned b1,b2;
    int b3;


    while ((scanf("%c",&c)!= EOF)&&(c!= EOF)){
        if(c=='\n'){
            continue;
        }
        switch(c){
            case 's':
                scanf("et %u %d\n",&b1,&b3);
                tree.modifideList(b1-1, b3);
                break;
            case 'm':
                scanf("ax %u %u\n",&b1,&b2);
                printf("%d\n", tree.request(b1-1,b2-1));
                break;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

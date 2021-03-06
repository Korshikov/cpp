#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

typedef long long int SegmentTreeNodeValueType;
const SegmentTreeNodeValueType netralElement = LLONG_MAX;


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
        return min(left, right);
    }

    SegmentTreeNodeValueType request(long long left, long long right, long long nodeNumber, SegmentTreeNodeValueType tLeft, SegmentTreeNodeValueType tRight) {
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
    freopen("rmq.in","r",stdin);
    freopen("rmq.out","w+",stdout);
    long long int n;
    SegmentTreeNodeValueType *a;

    scanf("%lld", &n);
    a = new SegmentTreeNodeValueType[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    SegmentTree tree(a, n);

    char c;
    long long b1,b2;

    while ((scanf("%c",&c)!= EOF)&&(c!= EOF)){
        if(c=='\n'){
            continue;
        }
        switch(c){
            case 's':
                scanf("et %lld %lld\n",&b1,&b2);
                tree.modifideList(b1-1, b2);
                break;
            case 'm':
                scanf("in %lld %lld\n",&b1,&b2);
                printf("%lld\n", tree.request(b1-1,b2-1));
                break;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

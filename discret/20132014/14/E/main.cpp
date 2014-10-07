#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

typedef unsigned SegmentTreeNodeValueType;



struct SegmentTreeNode {
    SegmentTreeNodeValueType value;
    long long indexOfValue;

    SegmentTreeNode() {
        value = INT_MAX;
        indexOfValue = INT_MAX;
    }

    bool operator!= (SegmentTreeNode const&data) {
        return ((this->value!= data.value)||
                (this->indexOfValue!= data.indexOfValue));
    }
};

const SegmentTreeNode netralElement;

struct SegmentTree {
    SegmentTree(const long long &n) {
        treeN = 1 << (long long) ceil(log2(n));
        treeLength = treeN << 1;
        tree = new SegmentTreeNode[treeLength];
        for (int i = treeN - 1; i < n + treeN - 1; i++) {
            tree[i].value = 0;
            tree[i].indexOfValue = i+2-treeN;
        }
        for (int i = treeN - 2; i >= 0; i--) {
            tree[i].value = tree[i * 2 + 1].value;
            tree[i].indexOfValue = tree[i * 2 + 1].indexOfValue;
        }
    }

    ~SegmentTree() {
        delete  []tree;
    }

    SegmentTreeNode request(long long left, long long right) {
        return request(left, right, 0, 0, treeN - 1);
    }

    void modifideList(long long elementNumber, SegmentTreeNodeValueType newValue) {
        tree[treeN + elementNumber - 1].value = newValue;
        updateParentValue(treeN + elementNumber - 1);
    }

private:
    SegmentTreeNode *tree;
    long long int treeLength, treeN;

    SegmentTreeNode functionInNode(SegmentTreeNode left, SegmentTreeNode right) {
        if(left.value<=right.value){
            return left;
        }else{
            return right;
        }
    }

    SegmentTreeNode request(long long left, long long right, long long nodeNumber, SegmentTreeNodeValueType tLeft, SegmentTreeNodeValueType tRight) {
        if (left > right) {
            return netralElement;
        }
        if ((left == tLeft) && (right == tRight)) {
            return tree[nodeNumber];
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
        SegmentTreeNode newValue = functionInNode(tree[parentNumber * 2 + 1], tree[parentNumber * 2 + 2]);
        if (tree[parentNumber] != newValue) {
            tree[parentNumber] = newValue;
            updateParentValue(parentNumber);
        }
    }

};

int main() {
    freopen("parking.in","r",stdin);
    freopen("parking.out","w+",stdout);
    long long int n,m;
    char c;
    long long b1;
    SegmentTreeNode b3;

    scanf("%lld %lld",&n,&m);

    SegmentTree tree(n);



    while ((scanf("%c",&c)!= EOF)&&(c!= EOF)){
        if(c=='\n'){
            continue;
        }
        if(c=='e'){
            scanf("%c",&c);
            switch(c){
            case 'x':
                scanf("it %lld\n",&b1);
                tree.modifideList(b1-1, 0);
                break;
            case 'n':
                scanf("ter %lld\n",&b1);
                b3 = tree.request(b1-1,n-1);
                if(b3.value==1){
                    b3 = tree.request(0,b1-1);
                }
                printf("%lld\n", b3.indexOfValue);
                tree.modifideList(b3.indexOfValue-1, 1);
                break;
        }
        }

    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

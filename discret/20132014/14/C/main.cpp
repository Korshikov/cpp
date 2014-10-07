#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

long long r;

struct SegmentTreeNodeValueType {
    long long matrix[2][2];


    SegmentTreeNodeValueType() {
    }
    //with out constructor;
    SegmentTreeNodeValueType(int){
        matrix[0][0]=1;
        matrix[0][1]=0;
        matrix[1][0]=0;
        matrix[1][1]=1;
    }

    const SegmentTreeNodeValueType operator*(SegmentTreeNodeValueType const& data);

    SegmentTreeNodeValueType operator= (SegmentTreeNodeValueType const& data);

    bool operator!= (SegmentTreeNodeValueType const&data) {
        return ((this->matrix[0][0]!= data.matrix[0][0])||
                (this->matrix[0][1]!= data.matrix[0][1])||
                (this->matrix[1][0]!= data.matrix[1][0])||
                (this->matrix[1][1]!= data.matrix[1][1]));
    }


};

SegmentTreeNodeValueType SegmentTreeNodeValueType::operator = (SegmentTreeNodeValueType const& data) {
    this->matrix[0][0] = data.matrix[0][0];
    this->matrix[0][1] = data.matrix[0][1];
    this->matrix[1][0] = data.matrix[1][0];
    this->matrix[1][1] = data.matrix[1][1];
    return *this;
}

const SegmentTreeNodeValueType SegmentTreeNodeValueType::operator *(SegmentTreeNodeValueType const &data) {
    SegmentTreeNodeValueType result;
    result.matrix[0][0] = (this->matrix[0][0] * data.matrix[0][0] + this->matrix[0][1] * data.matrix[1][0]) % r;
    result.matrix[0][1] = (this->matrix[0][0] * data.matrix[0][1] + this->matrix[0][1] * data.matrix[1][1]) % r;
    result.matrix[1][0] = (this->matrix[1][0] * data.matrix[0][0] + this->matrix[1][1] * data.matrix[1][0]) % r;
    result.matrix[1][1] = (this->matrix[1][0] * data.matrix[0][1] + this->matrix[1][1] * data.matrix[1][1]) % r;

    return result;
}




//typedef long long int SegmentTreeNodeValueType;
SegmentTreeNodeValueType const neutralElement(0);

struct SegmentTreeNode {
    //long long left,right;
    SegmentTreeNodeValueType value;
};

struct SegmentTree {
    SegmentTree(SegmentTreeNodeValueType *a, const long long &n) {
        treeN = n;
        treeLength = 4*n;
        tree = new SegmentTreeNode[treeLength];
        build(a, 0, 0, treeN-1);
    }

    void build(SegmentTreeNodeValueType *a, long long nodeNumber, long long tLeft, long long tRight){
        if(tLeft== tRight){
            tree[nodeNumber].value = a[tLeft];
            return;
        }else{
            long long tMidle = tLeft + ((tRight - tLeft) / 2);
            build(a, nodeNumber*2+1, tLeft, tMidle);
            build(a, nodeNumber*2+2, tMidle+1, tRight);
            tree[nodeNumber].value = functionInNode(tree[nodeNumber*2+1].value, tree[nodeNumber*2+2].value);
            return;
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

    SegmentTreeNodeValueType functionInNode(SegmentTreeNodeValueType left,const SegmentTreeNodeValueType right) {
        return left*right;
    }

    SegmentTreeNodeValueType request(long long left, long long right, long long nodeNumber, long long tLeft, long long tRight) {
        if (left > right) {
            return neutralElement;
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
    freopen("crypto.in","r",stdin);
    freopen("crypto.out","w+",stdout);
    long long int n,m;
    SegmentTreeNodeValueType *a;

    scanf("%lld %lld %lld\n",&r, &n,&m);
    a = new SegmentTreeNodeValueType[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld\n%lld %lld\n", &a[i].matrix[0][0],&a[i].matrix[0][1],&a[i].matrix[1][0],&a[i].matrix[1][1]);
    }

    SegmentTree tree(a, n);

    long long b1, b2;
    SegmentTreeNodeValueType result(0);

    for(int i=0;i<m;i++){
        scanf("%lld %lld\n",&b1,&b2);
        result = tree.request(b1-1, b2-1);
        printf("%lld %lld\n%lld %lld\n\n",result.matrix[0][0],result.matrix[0][1],result.matrix[1][0],result.matrix[1][1]);
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}
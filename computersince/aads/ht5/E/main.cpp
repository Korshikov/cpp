#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

typedef long long int SegmentTreeNodeValueType;

const SegmentTreeNodeValueType netralElement = 0;

struct SegmentTreeNodeModificator{
    long long* seted;
    long long added;
    unsigned long long setPriority;
    unsigned long long addPriority;


    SegmentTreeNodeModificator(){
        seted = NULL;
        added = 0;
        setPriority=0;
        addPriority=0;
    }

    void setNetral(){
        if(seted!=NULL){
            delete seted;
        }
        seted = NULL;
        added = 0;
        setPriority=0;
        addPriority=0;
    }
};

struct SegmentTreeNode {
    SegmentTreeNodeValueType value;
    SegmentTreeNodeModificator modifider;

    SegmentTreeNode():modifider(){
        value = netralElement;
    }
};

struct SegmentTree {
    SegmentTree(SegmentTreeNodeValueType const *a, const long long &n) {
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

    SegmentTreeNodeValueType request(long long const& left, const long long & right) {
        return request(left, right, 0, 0, treeN - 1);
    }


    void addForRange(long long const& l, long long const& r, long long const& value, unsigned long long const& priority){
        addForRange(l, r, value, priority, 0, 0, treeN - 1);
    }

    void setForRange(long long const& l, long long const& r, long long const& value, unsigned long long const& priority){
        setForRange(l, r, value, priority,0, 0, treeN - 1);
    }

private:
    SegmentTreeNode *tree;
    long long int treeLength, treeN;

    SegmentTreeNodeValueType functionInNode(SegmentTreeNodeValueType const& left, SegmentTreeNodeValueType const& right) {
        return left+right;
    }

    SegmentTreeNodeValueType request(long long const& left, long long const& right, long long const& nodeNumber, SegmentTreeNodeValueType const& tLeft, SegmentTreeNodeValueType const& tRight) {
        if (left > right) {
            return netralElement;
        }

        if ((left == tLeft) && (right == tRight)) {
            return tree[nodeNumber].value;
        }

        long long tMidle = tLeft + ((tRight - tLeft) / 2);

        putModifiderDown(nodeNumber);

        return functionInNode(
                request(left, min(right, tMidle), nodeNumber * 2 + 1, tLeft, tMidle),
                request(max(left, tMidle + 1), right, nodeNumber * 2 + 2, tMidle + 1, tRight)
        );
    }

    void updateParentValue(long long const& nodeNumber) {
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

    void addForRange(long long const& left, long long const& right, SegmentTreeNodeValueType const& added , unsigned long long const& priority,long long const& nodeNumber, long long const& tLeft, long long const& tRight){
        if ((left > right)||((added==0)&&(tree[nodeNumber].modifider.added==0))) {
            return;
        }
        if ((left == tLeft) && (right == tRight)) {
            if(left!=right){
                if(tree[nodeNumber].modifider.setPriority>tree[nodeNumber].modifider.addPriority){
                    tree[nodeNumber].modifider.added=added;
                }else{
                tree[nodeNumber].modifider.added += added;
                }
                tree[nodeNumber].modifider.addPriority = priority;
            }
            tree[nodeNumber].value += added;
            updateParentValue(nodeNumber);
            return;
        }
        long long tMidle = tLeft + ((tRight - tLeft) / 2);

        putModifiderDown(nodeNumber);

        addForRange(left, min(right, tMidle), added, priority,nodeNumber * 2 + 1, tLeft, tMidle);
        addForRange(max(left, tMidle + 1), right, added, priority,nodeNumber * 2 + 2, tMidle + 1, tRight);

    }
    void setForRange(long long const& left, long long const& right, SegmentTreeNodeValueType const& seted , unsigned long long const& priority,long long const& nodeNumber, long long const& tLeft, long long const& tRight){
        if (left > right) {
            return;
        }



        if ((left == tLeft) && (right == tRight)) {
            if(left!=right){
                tree[nodeNumber].modifider.seted = new SegmentTreeNodeValueType(seted);
                tree[nodeNumber].modifider.setPriority = priority;
            }
            tree[nodeNumber].value = seted;
            tree[nodeNumber].modifider.added = 0;

            updateParentValue(nodeNumber);
            return;
        }

        long long tMidle = tLeft + ((tRight - tLeft) / 2);

        putModifiderDown(nodeNumber);

        setForRange(left, min(right, tMidle), seted,priority,nodeNumber * 2 + 1, tLeft, tMidle);
        setForRange(max(left, tMidle + 1), right, seted, priority, nodeNumber * 2 + 2, tMidle + 1, tRight);

    }

    void putModifiderDown(long long const& nodeNumber){
        SegmentTreeNodeModificator* modifider = &tree[nodeNumber].modifider;
        if(modifider->setPriority>modifider->addPriority){
            modifider->added=0;
        }
        if((modifider->added!=0)||(modifider->seted!=NULL)){
            if(modifider->seted!=NULL){
                tree[nodeNumber*2+1].value= *modifider->seted;
                tree[nodeNumber*2+2].value= *modifider->seted;
                if(nodeNumber< treeN-1){
                    tree[nodeNumber*2+1].modifider.seted= new SegmentTreeNodeValueType(*modifider->seted);
                    tree[nodeNumber*2+2].modifider.seted= new SegmentTreeNodeValueType(*modifider->seted);
                    tree[nodeNumber*2+1].modifider.setPriority= modifider->setPriority;
                    tree[nodeNumber*2+2].modifider.setPriority= modifider->setPriority;
                }
            }
            if(modifider->added!= 0){
                tree[nodeNumber*2+1].value+= modifider->added;
                tree[nodeNumber*2+2].value+= modifider->added;
                if(nodeNumber< treeN-1){
                    tree[nodeNumber*2+1].modifider.added= modifider->added;
                    tree[nodeNumber*2+2].modifider.added= modifider->added;
                    tree[nodeNumber*2+1].modifider.addPriority= max(modifider->addPriority,tree[nodeNumber*2+1].modifider.addPriority);
                    tree[nodeNumber*2+2].modifider.addPriority= max(modifider->addPriority,tree[nodeNumber*2+2].modifider.addPriority);
                }
            }
            updateParentValue(nodeNumber*2+1);
            tree[nodeNumber].modifider.setNetral();
        }
    }

};

int main() {
    freopen("sum.in","r",stdin);
    //freopen("rmq2.out","w+",stdout);
    long long int n,k;
    SegmentTreeNodeValueType *a;

    scanf("%lld%lld\n", &n,&k);
    a = new SegmentTreeNodeValueType[n];
    for (int i = 0; i < n; i++) {
        a[i] = 0;
    }

    SegmentTree tree(a, n);

    delete a;

    char c;
    long long b1,b2,b3;
    unsigned long long priority = 0;

    while ((scanf("%c",&c)!= EOF)&&(c!= EOF)){
        if(c=='\n'){
            continue;
        }
        switch(c){
            case 's':
                scanf("et %lld %lld %lld\n",&b1,&b2, &b3);
                tree.setForRange(b1-1, b2-1,b3,priority++);
                break;
            case 'Q':
                scanf("%lld%lld\n",&b1,&b2);
                printf("%lld\n", tree.request(b1-1,b2-1));
                break;
            case 'A':
                scanf("%lld%lld%lld\n",&b1,&b2,&b3);
                tree.addForRange(b1-1,b2-1,b3,priority++);
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

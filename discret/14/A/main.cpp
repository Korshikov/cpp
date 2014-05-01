#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long int SegmentTreeNodeValueType;

struct SegmentTreeNode{
    long long left,right;
    SegmentTreeNodeValueType value;

};

struct SegmentTree{
    SegmentTree(SegmentTreeNodeValueType* a, long long n){

    }

private:
    SegmentTreeNode* tree;
};

int main()
{

    return 0;
}

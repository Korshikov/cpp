#include <cstdio>
#include <climits>


using namespace std;
typedef long long numberType;

numberType r = INT_MAX;

struct Matrix2_2{
    numberType matrix[2][2];
    Matrix2_2(){
        matrix[0][0]=1;
        matrix[0][1]=0;
        matrix[1][0]=0;
        matrix[1][1]=1;
    }

    Matrix2_2(numberType el11,numberType el12,numberType el21,numberType el22){
        matrix[0][0]=el11;
        matrix[0][1]=el12;
        matrix[1][0]=el21;
        matrix[1][1]=el22;
    }

    void initMatrix2_2(numberType el11,numberType el12,numberType el21,numberType el22){
        matrix[0][0]=el11;
        matrix[0][1]=el12;
        matrix[1][0]=el21;
        matrix[1][1]=el22;
    }



    const Matrix2_2 operator* (const Matrix2_2& thecondOperand){
        Matrix2_2 result;
        result.matrix[0][0] = (this->matrix[0][0]*thecondOperand.matrix[0][0] + this->matrix[0][1]*thecondOperand.matrix[1][0])%r;
        result.matrix[0][1] = (this->matrix[0][0]*thecondOperand.matrix[0][1] + this->matrix[0][1]*thecondOperand.matrix[1][1])%r;
        result.matrix[1][0] = (this->matrix[1][0]*thecondOperand.matrix[0][0] + this->matrix[1][1]*thecondOperand.matrix[1][0])%r;
        result.matrix[1][1] = (this->matrix[1][0]*thecondOperand.matrix[0][1] + this->matrix[1][1]*thecondOperand.matrix[1][1])%r;
        return result;
    }
};

typedef Matrix2_2 SegmentTreeNodeType;

class SegmentTree{
public:
    SegmentTree(SegmentTreeNodeType* a;const numberType& n){

    }

private:
    SegmentTreeNodeType* tree;
    numberType treeLength;
    numberType treeN;
};

int main()
{
    numberType n,m;
    scanf("%lld %lld %lld",&r,&n,&m);
    SegmentTreeNodeType* a = new SegmentTreeNodeType[n];
    numberType b1,b2,b3,b4;
    for(int i=0;i<n;i++){
        scanf("%lld %lld %lld %lld",&b1,&b2,&b3,&b4);
        a[i].initMatrix2_2(b1,b2,b3,b4);
    }
    for(int i=0;i<m;i++){
        scanf("%lld %lld",&b1,&b2);
    }

    return 0;
}

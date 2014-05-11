#include <cstdio>
#include <stack>

using namespace std;

int main (int argc, char * const argv[]) {
    int n;
    stack<int> h;
    scanf("%d",&n);
    int* a = new int[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if((h.empty())||(h.top()==a[i])){
            h.push(a[i]);
        } else{
            h.pop();
        }
    }
    if(h.empty()){
        printf("False");
        return 0;
    }
    int c=0,p=h.top();
    for(int i=0;i<n;i++){
        if(a[i]==p){
            ++c;
        }
    }
    if(c>n/2){
        printf("True");
    }                  else{
        printf("False");
    }



    return 0;
}

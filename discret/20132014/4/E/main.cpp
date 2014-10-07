#include <cstdio>
#include <cstdlib>

using namespace std;

int a[100];
  int m, i, j;

void razl(int n, int k, int i) {
  if ( n < 0 ) return;
  if ( n == 0 ) {

    int j;
    for (j = 0; j < i-1;) {
      printf("%d+", a[j++]);
    }
    printf("%d\n",a[j]);

  } else {
    if ( k - 1 > 0) {
      razl(n, k - 1, i);
    }

    if ( n - k >= 0) {
      a[i] = k;
      razl(n - k, k, i + 1);
    }


  }
  return;
}

int main() {
    freopen("partition.in","r",stdin);
    freopen("partition.out","w+",stdout);

    scanf("%d", &m);

    razl(m, m, 0);
    return 0;
}

#include <iostream>
#include "big_integer.h"

using namespace std;

int main() {
    big_integer a(10);
    a=a+big_integer(5);
    cout << a << endl;
    cout << "Hello, World!" << endl;
  return 0;
}
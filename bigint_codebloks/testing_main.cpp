#include <cstdio>
#include <iostream>

#include <big_integer.h>

using namespace std;

int main()
{
    //big_integer a( "43535368910323");
    //big_integer b("10");

        big_integer a =big_integer(1)<<129;
    big_integer b= big_integer(1)<<31;
    big_integer c("100000000000000000000000000000000000000000000000000000");
    big_integer e = a/b;
    cout << string(a) << endl;
    cout << string(b) << endl;
    cout << string(e) << endl;
    cout << string(c) << endl;
//    big_integer a((1<<30)),c,b(1<<30);


    c=b;
    c*=b;
    printf("2\n");
    c*=b;
    printf("3\n");
    c*=b;
    printf("4\n");
    c*=b;
    printf("5\n");
    c*=b;
    printf("6\n");
    c*=b;
    printf("7\n");
    c*=b;
    printf("8\n");


    a*=a;
    printf("2\n");
    a*=a;
    printf("4\n");
    a*=a;
    printf("8\n");



    for(int i=0;i<8;i++)
    {
        b*=b;
    }

    return 0;

}

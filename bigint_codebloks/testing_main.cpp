#include <cstdio>
#include <iostream>

#include <big_integer.h>

using namespace std;

int main()
{
    //big_integer a( "43535368910323");
    //big_integer b("10");

   /* big_integer a("-10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    big_integer b(                                                      "100000000000000000000000000000000000000");
    big_integer c("-100000000000000000000000000000000000000000000000000000");*/
        big_integer a =big_integer(1)<<129;
    big_integer b= big_integer(1)<<31;
    big_integer c("100000000000000000000000000000000000000000000000000000");
    big_integer e = a/b;
    cout << to_string(a) << endl;
    cout << to_string(b) << endl;
    cout << to_string(e) << endl;
    cout << to_string(c) << endl;

//    big_integer a((1<<30)),c,b(1<<30);

    for(DataType::iterator i = a.data->end()-1; i>= a.data->begin();i--)
    {
        printf("%08X",*(i));
    }
    printf("\n");

    for(DataType::iterator i = b.data->end()-1; i>= b.data->begin();i--)
    {
        printf("%08X",*(i));
    }
    printf("\n");

    for(DataType::iterator i = e.data->end()-1; i>= e.data->begin();i--)
    {
        printf("%08X",*(i));
    }
    printf("\n");

    for(DataType::iterator i = c.data->end()-1; i>= c.data->begin();i--)
    {
        printf("%08X",*(i));
    }
    printf("\n");
/*
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

    for(DataType::iterator i = c.data->end()-1; i>= c.data->begin();i--)
    {
        printf("%08X",*(i));
    }
    printf("\n");

    a*=a;
    printf("2\n");
    a*=a;
    printf("4\n");
    a*=a;
    printf("8\n");


    for(DataType::iterator i = a.data->end()-1; i>= a.data->begin();i--)
    {
        printf("%08X",*(i));
    }
    printf("\n");

*/

/*
    a += b;

    cout << to_string(a)<<endl;

    for(DataType::iterator i = a.data->end()-1; i>= a.data->begin();i--)
    {
        printf("%08X",*(i));
    }
*/

    //uint64_t d=0b11111100,q=0b111;

//    printf("%u",-1<<1024);

    return 0;

}

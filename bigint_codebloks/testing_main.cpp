#include <cstdio>
#include <iostream>

#include <big_integer.h>

using namespace std;

int main()
{
    big_integer a("-10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    big_integer b(                                                     "-100000000000000000000000000000000000000");
    big_integer c( "100000000000000000000000000000000000000000000000000000");
    cout << to_string(a) << endl;
    cout << to_string(b) << endl;
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
    cout << to_string(a/=b) << endl;
    cout << to_string(c) << endl;

    for(DataType::iterator i = a.data->end()-1; i>= a.data->begin();i--)
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

#include <cstring>
#include <iostream>
#include "matrices.h"

using namespace std;

int main(int argc, char ** argv)
{
    ios_base::sync_with_stdio(0);
    if(argc>1)
    {
        try{
        matrices a(argv[1]);
        for (int i = 2; i < argc; i+=2)
        {
            if(strstr(argv[i],"--add")==0)
            {
                matrices b(argv[++i]);
                a= a+b;
            }
        }
        }
        catch(int e)
        {
            cout << "error in input";
            return -1;
        }
    }


    return 0;
}

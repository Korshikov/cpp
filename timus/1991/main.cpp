/* 
 * File:   main.cpp
 * Author: delf
 *
 * Created on 16 Июнь 2014 г., 23:10
 */

#include <cstdio>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int n,k,b,live=0,not_use=0;
    scanf("%d %d\n",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b);
        if(b>k)
        {
            not_use+=b-k;
        }
        else
        {
            live += k-b;
        }
    }
    printf("%d %d",not_use,live);
    return 0;
}


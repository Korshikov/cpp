/* 
 * File:   main.cpp
 * Author: delf
 *
 * Created on 16 Июнь 2014 г., 22:58
 */

#include <cstdio>
#include <algorithm>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int a1,a2,a3,b1,b2,b3;
    scanf("%d %d %d %d %d %d",&a1,&b1,&a2,&b2,&a3,&b3);
    printf("%d %d",a1-min(a2,a3),b1-min(b2,b3));
    return 0;
}


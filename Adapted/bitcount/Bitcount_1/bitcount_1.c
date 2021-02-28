#include "bitops.h"

int total_errors = 0;
int n;
long x;

void init()
/*
 * Initializes all the necesary variables.
 */
{   
    n = 0; //counter
    x = 1804289396; //bit set

}

void test(){

        if (x) do{
            n++;
        }
        while (0 != (x = x&(x-1))) ;
}

void check(){

    if(n != 16){
        total_errors++;
    }

}
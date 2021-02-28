#include <string.h>
#include "bitops.h"

int total_errors = 0;
char s[] = "1010110011";
char *cptr = s;
unsigned int i;
unsigned int j;
unsigned int result = 691;

void init()
/*
 * Initializes all the necesary variables.
 */
{   

    i = 0;
    j = 0;

}

void test(){

      while (cptr && *cptr && strchr("01", *cptr))
      {
            i = *cptr++ - '0';
            j <<= 1;
            j |= (i & 0x01);
      }

}

void check(){

    if(result != j) total_errors++;

}
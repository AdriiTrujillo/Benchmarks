#include "bitops.h"

int total_errors = 0;
char s[17];
char *str = s;
long byze;
int biz;
int strwid;
char result_data[] = "          0 0011";

void init()
/*
 * Initializes all the necesary variables.
 */
{   

    byze = (long)3;
    biz = 5;
    strwid = 16;

}

void test(){

      int i, j;
      j = strwid - (biz + (biz >> 2)- (biz % 4 ? 0 : 1));
      for (i = 0; i < j; i++)
            *str++ = ' ';
      while (--biz >= 0)
      {
            *str++ = ((byze >> biz) & 1) + '0';
            if (!(biz % 4) && biz)
                  *str++ = ' ';
      }
      *str = '\0';
        

}

void check(){

    for(uint i = 0; i < 17; i++){
        if(s[i] != result_data[i]){
            total_errors++;
        }
    }

}
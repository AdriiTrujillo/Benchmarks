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

      x = ((x & 0xAAAAAAAAL) >>  1) + (x & 0x55555555L);
      x = ((x & 0xCCCCCCCCL) >>  2) + (x & 0x33333333L);
      x = ((x & 0xF0F0F0F0L) >>  4) + (x & 0x0F0F0F0FL);
      x = ((x & 0xFF00FF00L) >>  8) + (x & 0x00FF00FFL);
      x = ((x & 0xFFFF0000L) >> 16) + (x & 0x0000FFFFL);
      n = (int)x;

}

void check(){

    if(n != 16){
        total_errors++;
    }

}
#include <math.h>
#include <stdlib.h>
#include "snipmath.h"
#include <stdio.h>

int total_errors = 0;
double  a;
double  b;
double  c;
double  d;
int num_solutions;
double result_data[3];
const double expected_data[3] = {2, 6, 2.5};

void init()
/*
 * Initializes all the necesary variables.
 */
{   
    a = 1.0; 
    b = -10.5; 
    c = 32.0; 
    d = -30.0;
}

void test(){

    long double a1 = b/a, a2 = c/a, a3 = d/a;
    long double Q = (a1*a1 - 3.0*a2)/9.0;
    long double R = (2.0*a1*a1*a1 - 9.0*a1*a2 + 27.0*a3)/54.0;
    double R2_Q3 = R*R - Q*Q*Q;

    double    theta;

    if (R2_Q3 <= 0)
    {
        num_solutions = 3;
        theta = acos(R/sqrt(Q*Q*Q));
        result_data[0] = -2.0*sqrt(Q)*cos(theta/3.0) - a1/3.0;
        result_data[1] = -2.0*sqrt(Q)*cos((theta+2.0*PI)/3.0) - a1/3.0;
        result_data[2] = -2.0*sqrt(Q)*cos((theta+4.0*PI)/3.0) - a1/3.0;

        result_data[0] = floor((result_data[0] * 1024))/1024;
        result_data[1] = floor((result_data[1] * 1024))/1024;
        result_data[2] = floor((result_data[2] * 1024))/1024;
    }

    else
    {
        num_solutions = 1;
        result_data[0] = pow(sqrt(R2_Q3)+fabs(R), 1/3.0);
        result_data[0] += Q/result_data[0];
        result_data[0] *= (R < 0.0) ? 1 : -1;
        result_data[0] -= a1/3.0;
    }

}

void check() {

    if(num_solutions != 3){   
        total_errors += 1;
    }

    for(int i = 0; i < 3; i++){
        if(result_data[i] != expected_data[i]){
            total_errors += 1;
        }
    }

}
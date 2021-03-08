//*****************************************************************************
//
// AUTHOR:  Sergio Cuenca based on Heather Quinn mm_test.c
// CONTACT INFO:  
// LAST EDITED: 08/03/2021
//
//*****************************************************************************

// #include <stdio.h>
#define     side                12

const int first_matrix[side][side] = {{1,2,3,4,5,6,7,8,9,10,11,12}, {1,2,3,4,5,6,7,8,9,10,11,12}, {1,2,3,4,5,6,7,8,9,10,11,12}, {1,2,3,4,5,6,7,8,9,10,11,12}, {1,2,3,4,5,6,7,8,9,10,11,12}, {1,2,3,4,5,6,7,8,9,10,11,12}
                                     ,{1,2,3,4,5,6,7,8,9,10,11,12}, {1,2,3,4,5,6,7,8,9,10,11,12}, {1,2,3,4,5,6,7,8,9,10,11,12}, {1,2,3,4,5,6,7,8,9,10,11,12}, {1,2,3,4,5,6,7,8,9,10,11,12}, {1,2,3,4,5,6,7,8,9,10,11,12}};

const int second_matrix[side][side] = {{12,11,10,9,8,7,6,5,4,3,2,1}, {12,11,10,9,8,7,6,5,4,3,2,1}, {12,11,10,9,8,7,6,5,4,3,2,1}, {12,11,10,9,8,7,6,5,4,3,2,1}, {12,11,10,9,8,7,6,5,4,3,2,1}, {12,11,10,9,8,7,6,5,4,3,2,1}
                                      ,{12,11,10,9,8,7,6,5,4,3,2,1}, {12,11,10,9,8,7,6,5,4,3,2,1}, {12,11,10,9,8,7,6,5,4,3,2,1}, {12,11,10,9,8,7,6,5,4,3,2,1}, {12,11,10,9,8,7,6,5,4,3,2,1}, {12,11,10,9,8,7,6,5,4,3,2,1}};

const int long check_matrix[side][side] = {{936,858,780,702,624,546,468,390,312,234,156,78}, {936,858,780,702,624,546,468,390,312,234,156,78}, {936,858,780,702,624,546,468,390,312,234,156,78}, {936,858,780,702,624,546,468,390,312,234,156,78}, {936,858,780,702,624,546,468,390,312,234,156,78}, {936,858,780,702,624,546,468,390,312,234,156,78}
                                          ,{936,858,780,702,624,546,468,390,312,234,156,78}, {936,858,780,702,624,546,468,390,312,234,156,78}, {936,858,780,702,624,546,468,390,312,234,156,78}, {936,858,780,702,624,546,468,390,312,234,156,78}, {936,858,780,702,624,546,468,390,312,234,156,78}, {936,858,780,702,624,546,468,390,312,234,156,78}};

int long result_matrix[side][side];
unsigned int total_errors;


void init(){
    total_errors=0;
    for (int i = 0 ; i < side ; i++ ) {
        for (int j = 0 ; j < side ; j++ ) {
		result_matrix[i][j]=0;
	}
    }
}

void test() {
    int sum = 0;
    //MM
    for (int i = 0 ; i < side ; i++ ) {
        for (int j = 0 ; j < side ; j++ ) {
            for (int k = 0 ; k < side ; k++ ) {
                sum = sum + first_matrix[i][k]*second_matrix[k][j];
            }

            result_matrix[i][j] = sum;
            sum = 0;

        }
    }
}


void check(){

    for (int i = 0 ; i < side ; i++ ) {
        for (int j = 0 ; j < side ; j++ ) {
	    if ( result_matrix[i][j] != check_matrix[i][j])
            	total_errors ++; 
	}
    }

}
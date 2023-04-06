#include "matrix.h"


int main()
{
	int *p_arr_A = NULL; // Matrix A
	int *p_arr_B = NULL; // Matrix B
	
	
	int row_A , col_A ; // row and colums of matrix A
	int row_B , col_B ; // row and colums of matrix B
	
	
	/*Matrix A -- Input row and col*/
	printf("-----Input the information of Matrix A-----\n");
	printf("Row of matrix A : ");
	scanf("%d",&row_A );
	printf("Col of matrix A : ");
	scanf("%d",&col_A );
	
	/* dyamic allocation for matrix A */
	p_arr_A = (int*)malloc( row_A*col_A*sizeof(int) );
	
	
	matrixInput(p_arr_A , row_A , col_A );
	
	/*Matrix B -- Input row and col*/
	printf("-----Input the information of Matrix B-----\n");
	printf("Row of matrix B : ");
	scanf("%d",&row_B );
	printf("Col of matrix B : ");
	scanf("%d",&col_B );
	
	/* dyamic allocation for matrix B */
	p_arr_B = (int*)malloc( row_B*col_B*sizeof(int) );
	
	matrixInput(p_arr_B , row_B , col_B );
	 
	Output(p_arr_A , p_arr_B, row_A, col_A, row_B, col_B);
	
	/* Free Matrix A and Matrix B */
	free( p_arr_A );
	free( p_arr_B );
	
	return 0;
}

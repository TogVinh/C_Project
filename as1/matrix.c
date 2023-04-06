#include "matrix.h"

/*FUNCTION=================================================================
*  Funtion Name : Matrix_Input
*  Description  : Input the element of matrix
==========================================================================*/
void matrixInput(int *p_Arr, int row, int col)
{
	int row_index, col_index; // loop variable

	for (row_index = 0; row_index < row; row_index++)
	{
		for (col_index = 0; col_index < col; col_index++)
		{
			printf("a[%d][%d] =  ", row_index, col_index);
			scanf("%d", (p_Arr + row_index * row + col_index));
		}
	}
}

/*FUNCTION=================================================================
*  Funtion Name : Matrix_Print
*  Description  : Print the matrix to the terminal
==========================================================================*/
void matrixPrint(int *p_Arr, int row, int col)
{
	int row_index, col_index; // Loop variable

	for (row_index = 0; row_index < row; row_index++)
	{
		for (col_index = 0; col_index < col; col_index++)
		{
			printf("%d   ", *(p_Arr + row_index * row + col_index));
		}
		printf("\n");
	}
}

/*FUNCTION=================================================================
*  Funtion Name : Sum
*  Description  : Calculate the sumation/addition of two matrices
==========================================================================*/
void Sum(int *p_A, int *p_B, int row, int col, int *p_arr_Sum)
{

	/*loop variable */
	int row_index, col_index; // loop variable

	for (row_index = 0; row_index < row; row_index++)
	{
		for (col_index = 0; col_index < col; col_index++)
		{
			*(p_arr_Sum + row_index * row + col_index) = *(p_A + row_index * row + col_index) + *(p_B + row_index * row + col_index);
		}
	}
}

/*FUNCTION================================================================
*  Funtion Name : mul
*  Description  : Calculate the Multiple of two matrices
=========================================================================*/
void Multiply(int *p_A, int *p_B, int row, int col, int general, int *p_arr_Mul)
{

	int row_index = 0; // loop variable to count row of matrix
	int col_index = 0; // loop variable to count colums of matrix
	int index = 0;	   // loop variable to count index of Multiply matrix

	for (row_index = 0; row_index < row; row_index++)
	{
		for (col_index = 0; col_index < col; col_index++)
		{
			// value of one element in Multi matrix
			int matrix_element = 0;

			for (index = 0; index < general; index++)
			{
				matrix_element += *(p_A + row_index * row + index) * *(p_B + index * row + col_index);
			}

			// element in row i col j of arr_M
			*(p_arr_Mul + row_index * row + col_index) = matrix_element;
		}
	}
}

/*FUNCTION===============================================================
*  Funtion Name : check_Sum
*  Description  : check the addition condition of two matrices
*  return true/false
========================================================================*/
bool checkSum(int row_A, int col_A, int row_B, int col_B)
{
	if ((row_A == row_B) && (col_A == col_B))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*FUNCTION===============================================================
*  Funtion Name : check_AB
*  Description  : check the multiplication condition of Matrix A and B
*  return true/false
========================================================================*/
bool checkAmultiB(int col_A, int row_B)
{
	if (col_A == row_B)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

/*FUNCTION===============================================================
*  Funtion Name : check_AB
*  Description  : check the multiplication condition of Matrix B and A
*  return true/false
========================================================================*/
bool checkBmultiA(int row_A, int col_B)
{
	if (row_A == col_B)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*======================================================================
*  Funtion Name : show_Output
*  Description  : check and show output of program
========================================================================*/
void Output(int *p_arr_A, int *p_arr_B, int row_A, int col_A, int row_B, int col_B)
{
	bool A_sum_B, A_mul_B, B_mul_A;

	/*check each calculation condition*/
	A_sum_B = checkSum(row_A, col_A, row_B, col_B);
	A_mul_B = checkAmultiB(col_A, row_B);
	B_mul_A = checkBmultiA(row_A, col_B);

	int *p_arr_Sum = NULL; // Sum of matrices
	int row_Sum = 0;
	int col_Sum = 0;

	int *p_arr_Mul = NULL; // Multiply of matrices
	int row_Mul = 0;
	int col_Mul = 0;

	/*printf the result of conditions*/

	if (A_sum_B == 1) // the condition of matrices's Sum
	{
		printf("\nMatrix A and Matrix B can add together \n");
	}
	else
	{
		printf("\nMatrix A and Matrix B can not add together \n");
	}

	if (A_mul_B == 1)
	{
		printf("Matrix A and Matrix B can multi together \n");
	}
	else
	{
		printf("Matrix A and matriX B can not multi together \n");
	}

	if (B_mul_A == 1)
	{
		printf("Matrix B and Matrix A can multi together \n");
	}
	else
	{
		printf("Matrix B and Matrix A can not multi together \n ");
	}

	/*Print the matrix A and matrix B*/
	printf("\n----- Matrix A : -----\n");
	matrixPrint(p_arr_A, row_A, col_A);

	printf("\n----- Matrix B -----\n");
	matrixPrint(p_arr_B, row_B, col_B);

	printf("\nMatrix A + Matrix B:\n");

	/*print the result*/
	if (A_sum_B == 1)
	{
		p_arr_Sum = (int *)malloc(row_A * col_A * sizeof(int));
		Sum(p_arr_A, p_arr_B, row_A, col_B, p_arr_Sum);
		matrixPrint(p_arr_Sum, row_A, col_A);
		free(p_arr_Sum);
	}
	else
	{
		printf("N/A\n");
	}

	printf("\nMatrix A * Matrix B:\n");
	if (A_mul_B == 1)
	{
		p_arr_Mul = (int *)malloc(row_A * col_B * sizeof(int));
		Multiply(p_arr_A, p_arr_B, row_A, col_B, col_A, p_arr_Mul);
		matrixPrint(p_arr_Mul, row_A, col_B);
		free(p_arr_Mul);
	}
	else
	{
		printf("N/A\n");
	}

	printf("\nMatrix B * Matrix A:\n");
	if (B_mul_A == 1)
	{

		p_arr_Mul = (int *)malloc(row_B * col_A * sizeof(int));
		Multiply(p_arr_B, p_arr_A, row_B, col_A, col_B, p_arr_Mul);
		matrixPrint(p_arr_Mul, row_B, col_A);
		free(p_arr_Mul);
	}
	else
	{
		printf("N/A\n");
	}
}

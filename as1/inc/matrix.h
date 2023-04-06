#ifndef _matrix_H_
#define _matrix_H_


/*======================================================================
*  include the Library
========================================================================*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*!
* @brief <Create an input the element of matrix>
*
* @param *a[In/Out] <pointer  point to an array containing matrix's elements>
*
* @param row [In] <number of rows of the matrix>
*
* @param col [In] <number of cols of the matrix>
*
*return None
*/
void matrixInput (int *p_Arr, int row , int col);

/*!
* @brief <Print an ouput of the element of matrix>
*
* @param *p_A[In/Out] <pointer  point to an array containing matrix's elements>
*
* @param row [In] <number of rows of the matrix>
*
* @param col [In] <number of cols of the matrix>
*
*return None
*/
void matrixPrint ( int *p_Arr, int row , int col);

/*!
* @brief <Calculate the sumation/addition of two matrices>
*
* @param *p_A[In/Out] <pointer point to an array containing elements of Matrix A>
*
* @param *p_B[In/Our] <pointer point to an array containing elements of Matrix B>

* @param row [In] <number of rows of the matrix>
*
* @param col [In] <number of cols of the matrix>
*
*return None
*/
void Sum(int *p_A, int *p_B, int row, int col, int *p_arr_Sum);

/*!
* @brief <Calculate the Multiple of two matrices>
*
* @param *p_A[In/Out] <pointer point to an array containing elements of Matrix A>
*
* @param *p_B[In/Our] <pointer point to an array containing elements of Matrix B>
*
* @param row [In] <number of rows of the matrix>
*
* @param col [In] <number of cols of the matrix>
*
* @param general [In] <common parameter of two matrices to perform multiplication>
*
*return None
*/
void Multiply(int *p_A, int *p_B, int row, int col, int general, int *p_arr_Mul);

/*!
* @brief <check the addition condition of two matrices>
*
* @param row_A [In] <number of rows of the matrix A>
*
* @param col_B [In] <number of columns of the matrix B>
*
* @param row_B [In] <number of rows of the matrix B>
*
* @param col_B [In] <number of columns of the matrix B>
*
*return true/false
*/
bool checkSum( int row_A, int col_A, int row_B, int col_B );

/*!
* @brief <Check the multiplication condition of Matrix A and B>
*
* @param col_A [In] <number of columns of the matrix A>
*
* @param row_B [In] <number of rows of the matrix B>
*
*return true/false
*/
bool checkAmultiB (int col_A, int row_B );

/*!
* @brief <Check the multiplication condition of Matrix B and A>
*
* @param row_A [In] <number of rows of the matrix A>
*
* @param col_B [In] <number of columns of the matrix B>
*
*return true/false
*/
bool checkBmultiA (int row_A, int col_B);

/*!
* @brief <Calculate the sumation/addition of two matrices>
*
* @param *p_arr_A[In/Out] <pointer point to an array containing elements of Matrix A>
*
* @param *arr_B[In/Out] <pointer point to an array containing elements of Matrix B>

* @param row_A [In] <number of rows of the matrix A>
*
* @param col_A [In] <number of columns of the matrix A>
*
* @param row_B [In] <number of rows of the matrix B>
*
* @param col_B [In] <number of columns of the matrix B>
*return None
*/
void Output(int *p_arr_A , int *p_arr_B, int row_A, int col_A, int row_B, int col_B);


#endif

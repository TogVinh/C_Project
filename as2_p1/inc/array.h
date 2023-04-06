#ifndef _array_H_
#define _array_H_
/*======================================================================
*  include the Library
========================================================================*/
#include <stdio.h>
#include <stdlib.h>

/*!
* @brief <Create an input the element of array>
*
* @param  arr[In] <the parameter of the array>
*
* @param  num[In] <the numbers of elemnt of array>
*
*return None
*/
void Input(int arr[], int num);


/*!
* @brief <Print the Output of the element of array>
*
* @param  arr[Out] <the parameter of the array>
*
* @param num[In] <the numbers of elemnt of array>
*
*return None
*/
void outputArray(int arr[], int num);


/*!
* @brief <calculate the average all element of array>
*
* @param  arr[In] <the parameter of the array>
*
* @param num[In] <the numbers of elemnt of array>
*
* return <average variable>
*/
float calAverage(int arr[], int num);


/*!
* @brief <count the number of elemrnt lower than the average of array>
*
* @param  arr[In] <the parameter of the array>
*
* @param num[In] <the numbers of elemnt of array>
*
*<the numbers of element less than average>
*/
int lessAveg(int arr[], int num);

/*!
* @brief <find the value and position of number in array>
*
* @param  arr[In] <the parameter of the array>
*
* @param num[In] <the numbers of elemnt of array>
*
* @param num_search <the number want to find in array>
*
*return None
*/
void Search(int arr[], int num, int num_search);

/*!
* @brief <move all odd element to the left of array>
*
* @param  arr[In] <the parameter of the array>
*
* @param num[In] <the numbers of elemnt of array>
*
*return None
*/
void oddElement(int arr[], int num);

#endif
/*** end of file ***/
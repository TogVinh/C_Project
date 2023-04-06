#include "array.h"

/*Input the elements of array*/
/*FUNCTION=================================================================
*  Funtion Name : Input
*  Description  : Input the element of array
==========================================================================*/
void Input(int arr[], int num)
{
	int index;
	for (index = 0; index < num; index++)
	{
		printf("Input a[%d] = ", index);
		scanf("%d", &arr[index]);
	}
}

/*printf Array*/
/*FUNCTION=================================================================
*  Funtion Name : outputArray
*  Description  : Print the array
==========================================================================*/
void outputArray(int arr[], int num)
{
	int index;

	for (index = 0; index < num; index++)
	{
		printf("%d  ", arr[index]);
	}
}

/* Calculator the average of Array */
/*FUNCTION=================================================================
*  Funtion Name : calAverage
*  Description  : Calculator the average of array
==========================================================================*/
float calAverage(int arr[], int num)
{
	int sum = 0    ;  // the sum of array
	float avrg = 0 ;  // the average of array
	int index = 0  ;  // Loop variable
	for (index = 0; index < num; index++)
	{
		sum += arr[index];
	}
	avrg = sum / num;
	return avrg;
}

/* find the the numbers of element less than average */
/*FUNCTION=================================================================
*  Funtion Name : lessAveg
*  Description  : count the number of elemrnt lower than
*                 the average of array
==========================================================================*/
int lessAveg(int arr[], int num)
{
	int index = 0;
	int count = 0; // count the numbers are less than average
	for (index = 0; index < num; index++)
	{
		if (arr[index] < calAverage(arr,num) )
		{
			count++;
		}
	}
	
	return count;
}

/*Search the value in the Array*/
/*FUNCTION=================================================================
*  Funtion Name : Search
*  Description  : find the value and position of number in array
==========================================================================*/
void Search(int arr[], int num, int num_search)
{
	int index = 0; //loop variable
	int count = 0; // count the number of numbers want find
	for (index = 0; index < num; index++)
	{
		if (arr[index] == num_search)
		{
			printf("arr[%d] = %d  \n", index, arr[index]);
			count++;
		}
	} /* Calculator the average of Array */

	if (count == 0) /* Calculator the average of Array */
		printf("Don't have this element in Array \n");
}

/*FUNCTION=================================================================
*  Funtion Name : odd_Element
*  Description  : move all odd element to the left of array
==========================================================================*/
void oddElement(int arr[], int num)
{
	int index = 0; // loop variable in compare
	int inser = 0; // loop variable to insertion
	int temp = 0; //temporary variable
	for (index = 1; index < num; index++)
	{
		temp = arr[index];
		inser = index - 1;

		while ((inser >= 0) && (arr[inser] % 2 == 0) && (temp % 2 != 0))
		{
			arr[inser + 1] = arr[inser];
			inser = inser - 1;
		}
		arr[inser + 1] = temp;
	}

	outputArray(arr, num);
}

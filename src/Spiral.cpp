/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
#include<stddef.h>
#include<malloc.h>

void spiral_helper(int *elements, int **input_array, int top, int right, int bottom, int left)
{
	if (top == bottom && top == left && top == right){
		*elements = input_array[top][top];
		return;
	}
	if (bottom < top || left > right)
		return;

	int i;
	for (i = left; i < right; i++)
		*elements++ = input_array[top][i];
	for (i = top; i < bottom; i++)
		*elements++ = input_array[i][right];
	if (top != bottom)
		for (i = right; i > left; i--)
			*elements++ = input_array[bottom][i];
	else
		*elements++ = input_array[bottom][right];


	if (right != left)
		for (i = bottom; i > top; i--)
			*elements++ = input_array[i][left];
	else
		*elements++ = input_array[bottom][left];

	spiral_helper(elements, input_array, top + 1, right - 1, bottom - 1, left + 1);
}
int *spiral(int rows, int cols, int **array)
{
	if (array == NULL)	return NULL;
	if (rows <= 0 || cols <= 0)	return NULL;

	int *result_array = (int*)malloc(rows*cols*sizeof(int));
	spiral_helper(result_array, array, 0, cols - 1, rows - 1, 0);
	return result_array;
}

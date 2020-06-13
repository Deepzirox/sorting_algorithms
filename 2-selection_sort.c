#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * selection_sort - Implements the selection sort on an array
 * @array: The array that we wants to sort
 * @size: The size of the array
*/

void selection_sort(int *array, size_t size)
{

	size_t i = 0, j = 0, k = 0;
	int key = 0, temp = 0;

	for (i = 0; i < size; i++)
	{
		key = i;
		for (j = i; j < size; j++)
		{
			if (array[key] > array[j])
				key = j;
		}
		temp = array[key];
		array[key] = array[i];
		array[i] = temp;
		for (k = 0; k < size; k++)
		{
			if (k == size - 1)
				printf("%i", array[k]);
			else
				printf("%i, ", array[k]);
		}
		printf("\n");
	}
}

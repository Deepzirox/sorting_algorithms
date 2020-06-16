#include "sort.h"

/**
 * knuth- check interval and sort array
 * @array: The array that we wants to sort
 * @size: The size of the array
 * @interval: calculated interval of size
 * Return: None
*/

void knuth(int *array, size_t interval, size_t size)
{
	size_t i = 0, j = 0;
	int value;

	for (; interval > 0; interval = (interval - 1) / 3)
	{
		for (i = interval; i < size; i++)
		{
			value = array[i];
			j = i;
			while (j > interval - 1 && array[j - interval] > value)
			{
				array[j] = array[j - interval];
				j -= interval;
			}
			array[j] = value;
		}
		print_array(array, size);
	}
}

/**
 * shell_sort - sort array using shell sort
 * @array: The array that we wants to sort
 * @size: The size of the array
 * Return: None
*/

void shell_sort(int *array, size_t size)
{
	size_t iterator = 1;

	for (; iterator <= size / 3; iterator = iterator * 3 + 1)
		;
	knuth(array, iterator, size);
}

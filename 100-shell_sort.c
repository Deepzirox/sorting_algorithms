#include "sort.h"

/**
<<<<<<< HEAD
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
=======
* shell_sort - sholl sort algorithm implemented
* @array: the array
* @size: size of the array
*/

void shell_sort(int *array, size_t size)
{
	size_t i = 0, interval = 1, val_aux = 0;
	int va = 0;

	if (!array || size < 2)
		return;

	while (interval <= size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			val_aux = i;
			va = array[i];

			while (val_aux > interval - 1 && array[val_aux - interval] > va)
			{
				array[val_aux] = array[val_aux - interval];
				val_aux -= interval;
			}
			array[val_aux] = va;
		}
		print_array(array, size);
		interval = (interval - 1) / 3;
	}
}
>>>>>>> e2694305bc5d2e6cff88095a2f3160dfb7e57d68

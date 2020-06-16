#include "sort.h"

/**
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

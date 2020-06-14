#include "sort.h"

/**
 * swap - swap values
 * @a: value a
 * @b: value b
 */
void swap(int *a, int *b)
{
	int tmp = *b;

	*b = *a;
	*a = tmp;
}
/**
 * bubble_sort - sort array using bubble
 * @array: array to sort
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, x;

	if (size >= 2)
	{
		for (i = 0; i < size - 1; i++)
		{
			for (j = 0; j < size - 1 - i; j++)
			{
				if (array[j] > array[j + 1])
				{
					swap(&array[j], &array[j + 1]);
					for (x = 0; x < size; x++)
					{
					if ((array[x] / 10) != 0)
						putchar((array[x] / 10) + '0');
					putchar((array[x] % 10) + '0');
					if (x != size - 1)
					{
						putchar(',');
						putchar(' ');
					}
					}
					putchar('\n');
				}
			}
		}
	}
}

#include "sort.h"
/**
 * sort - recursive get middle
 * @array: array to sort
 * @sorted: array to store sorted values
 * @size: size of array
 * @mid: middle of subarray
 **/
void sort(int *array, int *sorted, size_t mid, size_t size)
{
	unsigned int i = 0, z = 0, x = 0;
	int *middle_pointer = (array + mid);
	int compare_values, check_iterator_size;

	while (i < size)
	{
		compare_values = (x < mid && array[x] < middle_pointer[z]);
		check_iterator_size = (z >= size - mid);

		if (check_iterator_size || compare_values)
		{
			sorted[i] = array[x];
			x++;
		}
		else
		{
			sorted[i] = middle_pointer[z];
			z++;
		}
		i++;
	}

	for (i = 0; i < size; i++)
		array[i] = sorted[i];
}
/**
 * merge - recursive get middle
 * @array: array to sort
 * @sorted: array to store sorted values
 * @size: size of array
 **/
void merge(int *array, int *sorted, size_t size)
{
	size_t mid;

	if (size <= 1)
		return;

	mid = size / 2;
	merge(array, sorted, mid);
	merge(mid + array, mid + sorted, size - mid);
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, mid);
	printf("[right]: ");
	print_array(array + mid, size - mid);
	sort(array, sorted, mid, size);
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - sort array with merge algorithm
 * @array: array to sort
 * @size: size of array
 **/
void merge_sort(int *array, size_t size)
{
	int *sorted;

	if (size >= 2)
	{
		sorted = malloc(sizeof(int) * size);

		if (sorted == NULL)
			return;
		merge(array, sorted, size);
		free(sorted);
	}
}

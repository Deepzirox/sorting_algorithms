#include "sort.h"
/**
 * max_number - returns the maximum value of the array
 * @array: pointer to array
 * @size: size of the array
 * Return: The maximun value of the array
 */

int max_number(int *array, size_t size)
{
	size_t i;
	int max = 0;

	for (i = 0; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	return (max);
}
/**
 * counting_sort - Implement of the counting sort algorithm
 * @array: The array
 * @size: Size of the array
 */

void counting_sort(int *array, size_t size)
{
	size_t i = 0, j, max_value;
	int *temp = NULL, *aux = NULL;

	if (!array || size < 2)
		return;
	max_value = max_number(array, size);
	max_value += 1;
	temp = malloc(max_value * sizeof(int));
	if (!temp)
		return;
	aux = malloc(sizeof(int) * size);
	if (!aux)
	{
		free(temp);
		return; }
	for (i = 0; i < size; i++)
		temp[array[i]]++;
	for (j = 1; j < max_value; j++)
		temp[j] += temp[j - 1];
	print_array(temp, max_value);
	for (i = 0; i < size; i++)
	{
		temp[array[i]]--;
		aux[temp[array[i]]] = array[i];
	}
	for (j = 0; j < size; j++)
		array[j] = aux[j];
	free(aux), free(temp);
}

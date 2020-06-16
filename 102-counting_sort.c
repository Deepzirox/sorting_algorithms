/**
 * max_number - returns the maximum value of the array
 * @array: pointer to array
 * @size: size of the array
 * Return: The maximun value of the array
 */

int max_number(int *array, size_t size)
{
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
	size_t i, j, max_value;
	int *temp = NULL, *aux = NULL;

	if (!array || size < 2)
		return;
	max_value = max_number(array, size);
	temp = malloc((max_value + 1) * sizeof(int));
	if (!temp)
		return;
	aux = malloc(sizeof(int) * size);
	if (!aux)
	{
		free(temp);
		return; }
	for (i = 0; i < size; i++)
		aux[array[i]]++;
	for (j = 1; j < max_value; j++)
		aux[j] += aux[j - 1];
	print_array(aux, max_value);
	for (i = 0; i < size; i++)
		array[aux[temp[i] - 1] = temp[i];
	free(aux), free(temp);
}

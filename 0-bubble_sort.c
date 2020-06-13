#include "sort.h"

void swap(int *a, int *b)
{
    int tmp = *b;

    *b = *a;
    *a = tmp;
}

void bubble_sort(int *array, size_t size)
{
    int i, j, x;

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
                        printf("%d", array[x]);
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
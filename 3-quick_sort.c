#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void quick_sort(int *array, size_t size)
{
    size_t i, j;
    int pivot, temp;

   if(first < last)
   {
    pivot = first;
    i = first;
    j = last;

      while(i < j || i < size)
        {
        while(array[i] <= array[pivot] && i < last)
            i++;
        while(array[j] > array[pivot])
            j--;
        if(i < j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
      }
      temp = array[pivot];
      array[pivot] = array[j];
      array[j] = temp;
   }
}
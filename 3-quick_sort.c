#include "sort.h"
/**
 * partition - The Partitionner
 * @array: Array to be partitionned
 * @start: starting point
 * @end: ending point
 * Description: Partitions a table
 * Return: The pivot
*/
int partition(int *array, int start, int end)
{
int pivot, swap, i, j;
pivot = array[end];
i = start - 1;
for (j = start; j < end; j++)
{
if (array[j] <= pivot)
{
i = i + 1;
swap = array[i];
array[i] = array[j];
array[j] = swap;
}
}
i = i + 1;
swap = array[i];
array[i] = array[end];
array[end] = swap;
return (i);
}

/**
 * requicksort - The sorter
 * @array: Array to be sorted
 * @size: Size of the array
 * @start: starting point
 * @end: ending point
 * Description: Sort a portion of a table,
*/
void requicksort(int *array, int size, int start, int end)
{
int p;
if (start >= end || start < 0)
{
return;
}
p = partition(array, start, end);
print_array(array, size);
requicksort(array, size, start, p - 1);
requicksort(array, size, p + 1, end);
}

/**
 * quick_sort - Quick Sort
 * @array: Array to be sorted
 * @size: Size of the array
 * Description: Sort the array using the quick sort.
*/
void quick_sort(int *array, size_t size)
{
requicksort(array, size, 0, size - 1);
}

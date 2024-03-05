#include "sort.h"
/**
 * selection_sort - Selection Sort
 * @array: Array to be sorted
 * @size: Size of the array
 * Description: Sort the array using the selection sort
*/
void selection_sort(int *array, size_t size)
{
size_t i, j, min, trans;
if (size <= 1)
{
return;
}
for (i = 0; i < size - 1; i++)
{
min = i;
for (j = i; j < size; j++)
{
if (array[j] < array[min])
{
min = j;
}
}
trans = array[i];
array[i] = array[min];
array[min] = trans;
print_array(array, size);
}
}

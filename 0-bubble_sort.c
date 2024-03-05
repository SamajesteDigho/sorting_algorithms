#include "sort.h"
/**
 * bubble_sort - Bubble Sort
 * @array: Here is the array to be sorted
 * @size: Here is the size of the array
 * Description: This function permits to sort an array using the bubble sort.
*/
void bubble_sort(int *array, size_t size)
{
int swapped, limit, i, c;
swapped = 1;
limit = size - 1;
if (size <= 1)
{
return;
}
while (swapped == 1)
{
swapped = 0;
for (i = 0; i < limit; i++)
{
if (array[i] > array[i + 1])
{
c = array[i];
array[i] = array[i + 1];
array[i + 1] = c;
swapped = 1;
print_array(array, size);
}
}
limit -= 1;
}
}

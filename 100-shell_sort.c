#include "sort.h"
/**
 * shell_sort - Shell Sort
 * @array: Array to sort
 * @size: Size of the array
 * Description: Sort array using the Shell sort algorithm.
 */
void shell_sort(int *array, size_t size)
{
int i, j, gap, temp, n;
if (array == NULL || size == 0 || size == 1)
return;
n = (int)size;
gap = 1;
for (i = 0; i < n; i++)
{
if (gap * 3 + 1 < n)
gap = gap * 3 + 1;
else
break;
}
while (gap >= 1)
{
for (i = gap; i < n; i++)
{
temp = array[i];
for (j = i; (j >= gap) &&(array[j - gap] > temp); j -= gap)
{
array[j] = array[j - gap];
}
array[j] = temp;
}
gap = (gap - 1) / 3;
print_array(array, size);
}
}

#include "sort.h"

/**
 * i_left_child - I Left Child
 * @i: index
 * Description: Sort array using the Heap sort algorithm.
 * Return: I Left
 */
int i_left_child(int i)
{
return (2 * i + 1);
}

/**
 * heap_sort - Heap Sort
 * @array: Array to sort
 * @size: Size of the array
 * Description: Sort array using the Heap sort algorithm.
 */
void heap_sort(int *array, size_t size)
{
int n, start, end, root, child, swap;
if (array == NULL || size == 0)
return;
n = (int)size;
start = n / 2;
end = n;
while (end > 1)
{
if (start > 0)
start = start - 1;
else
{
end = end - 1;
swap = array[end];
array[end] = array[0];
array[0] = swap;
print_array(array, size);
}
root = start;
while (i_left_child(root) < end)
{
child = i_left_child(root);
if (child + 1 < end && array[child] < array[child + 1])
child = child + 1;
if (array[root] < array[child])
{
swap = array[root];
array[root] = array[child];
array[child] = swap;
root = child;
print_array(array, size);
}
else
break;
}
}
}

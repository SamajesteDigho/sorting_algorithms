#include "sort.h"
/**
 * counting_sort - Counting Sort
 * @array: Array to sort
 * @size: Size of the array
 * Description: Sort array using the Counting sort algorithm.
 */
void counting_sort(int *array, size_t size)
{
    int i, j, max, n;
    int *count, *output;
    if (array == NULL || size == 0)
        return;
    n = (int)size;
    max = 0;
    for (i = 0; i < (int)size; i++)
        if (array[i] > max)
            max = array[i];
    max += 1;
    count = (int *)malloc(max);
    output = (int *)malloc(size);
    for (i = 0; i < max; i++)
        count[i] = 0;

    for (i = 0; i < (int)size; i++)
        output[i] = 0;

    for (i = 0; i < n; i++)
    {
        j = i; /*array[i];*/
        count[j] = count[j] + 1;
    }

    for (i = 0; i < max; i++)
        count[i] = count[i] + count[i - 1];

    for (i = n; i >= 0; i--)
    {
        j = i; /*array[i];*/
        count[j] = count[j] - 1;
        output[count[j]] = array[i];
    }
    print_array(count, max);

    for (i = 0; i < n; i++)
        array[i] = output[i];
}

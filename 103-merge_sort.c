#include "sort.h"
/**
 * print_array_partly - Merge Sort
 * @arr: Array to sort
 * @start: Start
 * @end: End
 * @side: Side
 * Description: Sort array using the Merge sort algorithm.
 */
void print_array_partly(int *arr, int start, int end, char *side)
{
int i;
printf("%s", side);
for (i = start; i < end; i++)
{
printf("%d", arr[i]);
if (i < end - 1)
printf(", ");
}
printf("\n");
}

/**
 * TopDownMerge - Merge Sort
 * @B: Array to sort
 * @begin: Start
 * @middle: Middle
 * @end: End
 * @A: Array to sort
 * Description: Sort array using the Merge sort algorithm.
 */
void TopDownMerge(int *B, int begin, int middle, int end, int *A)
{
int i, j, k;
i = begin;
j = middle;
for (k = begin; k < end; k++)
{
if (i < middle && (j >= end || A[i] <= A[j]))
{
B[k] = A[i];
i += 1;
}
else
{
B[k] = A[j];
j += 1;
}
}
printf("Merging...\n");
print_array_partly(A, begin, middle, "[left]: ");
print_array_partly(A, middle, end, "[right]: ");
print_array_partly(B, begin, end, "[Done]: ");
}

/**
 * TopDownSplitMerge - Merge Sort
 * @B: Array to sort
 * @begin: Start
 * @end: End
 * @A: Array to sort
 * Description: Sort array using the Merge sort algorithm.
 */
void TopDownSplitMerge(int *B, int begin, int end, int *A)
{
int middle;
if (end - begin <= 1)
return;
middle = (end + begin) / 2;
TopDownSplitMerge(A, begin, middle, B);
TopDownSplitMerge(A, middle, end, B);
TopDownMerge(B, begin, middle, end, A);
}

/**
 * merge_sort - Merge Sort
 * @array: Array to sort
 * @size: Size of the array
 * Description: Sort array using the Merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
int n, i;
int *duplicate;
if (array == NULL || size == 0)
return;
n = (int)size;
duplicate = (int *) malloc(size * sizeof(int));
for (i = 0; i < n; i++)
duplicate[i] = array[i];
TopDownSplitMerge(array, 0, n, duplicate);
free(duplicate);
}

#include "sort.h"
/**
 * swap - Swap
 * @list: List concerned
 * @curr: Current node
 * Description: Swap current node with next one
 */
void swap(listint_t **list, listint_t *curr)
{
listint_t *front;
front = curr->next;
curr->next = front->next;
if (front->next != NULL)
front->next->prev = curr;
front->prev = curr->prev;
if (curr->prev != NULL)
curr->prev->next = front;
else
(*list) = front;
curr->prev = front;
front->next = curr;
}

/**
 * cocktail_sort_list - Cocktail Sort List
 * @list: List to sort
 * Description: Sort List using the Coktail sort algorithm.
 */
void cocktail_sort_list(listint_t **list)
{
int swapped;
listint_t *curr;
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;
curr = (*list);
do {
swapped = 1;
while (curr->next != NULL)
{
if (curr->n > curr->next->n)
{
swap(list, curr);
swapped = 0;
print_list(*list);
}
else
curr = curr->next;
}
if (swapped == 1)
break;
swapped = 1;
if (curr->next == NULL)
curr = curr->prev;
while (curr->prev != NULL)
{
if (curr->n > curr->next->n)
{
swap(list, curr);
swapped = 0;
print_list(*list);
}
else
curr = curr->prev;
}
} while (swapped == 0);
}

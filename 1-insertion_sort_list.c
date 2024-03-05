#include "sort.h"
/**
 * insertion_sort_list - Insertion sort
 * @list: The list to be sorted
 * Description: Permits to do the insertion sort on a given list
 */
void insertion_sort_list(listint_t **list)
{
listint_t *curr, *front, *back;
curr = (*list);
while (curr->next != NULL)
{
if (curr->n > curr->next->n)
{
front = curr->next;
curr->next = front->next;
if (front->next != NULL)
front->next->prev = curr;
front->prev = curr->prev;
if (curr->prev != NULL)
curr->prev->next = front;
curr->prev = front;
front->next = curr;
print_list(*list);
while (front->prev != NULL)
{
back = front->prev;
if (front->n < back->n)
{
back->next = front->next;
if (front->next != NULL)
front->next->prev = back;
front->prev = back->prev;
if (back->prev != NULL)
back->prev->next = front;
front->next = back;
back->prev = front;
if (front->prev == NULL)
*list = front;
print_list(*list);
}
else
break;
}
}
else
curr = curr->next;
}
}

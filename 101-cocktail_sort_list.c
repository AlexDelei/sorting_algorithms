#include "sort.h"
/**
 * cocktail_sort_list - Sorts doubly linked list integers in ascending order
 * using the Cocktail Shaker sort algorithm.
 * @list: Pointer to the head of the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start = *list;
	listint_t *end = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	do {
		swapped = 0;
		while (start->next != end)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start, start->next);
				swapped = 1;
				print_list(*list);
			}
			else
			{
				start = start->next;
			}
		}
		if (swapped == 0)
			break;

		while (start->prev != NULL)
		{
			if (start->n < start->prev->n)
			{
				swap_nodes(list, start->prev, start);
				swapped = 1;
				print_list(*list);
				start = start->next;
			}
			else
				start = start->prev;
		}
	} while (swapped);
}
/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Pointer to the head of the doubly linked list.
 * @node1: First node to be swapped.
 * @node2: Second node to be swapped.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	if (node2->prev != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	if (node2->prev == NULL)
		*list = node2;
}

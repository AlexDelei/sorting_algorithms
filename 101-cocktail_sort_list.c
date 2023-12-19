#include "sort.h"
/**
 * cocktail_sort_list - Sorts doubly linked list integers in ascending order
 * using the Cocktail Shaker sort algorithm.
 * @list: Pointer to the head of the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	do {
		swapped = 0;
		for (temp = *list; temp->next != NULL; temp = temp->next)
		{
			if (temp->n > temp->next->n)
			{
				swap_nodes(temp, temp->next);
				swapped = 1;
				print_list(*list);
			}
		}
		if (swapped == 0)
			break;

		swapped = 0;

		for (; temp->prev != NULL; temp = temp->prev)
		{
			if (temp->n < temp->prev->n)
			{
				swap_nodes(temp->prev, temp);
				swapped = 1;
				print_list(*list);
			}
		}
	} while (swapped);
}
/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Pointer to the head of the doubly linked list.
 * @node1: First node to be swapped.
 * @node2: Second node to be swapped.
 */
void swap_nodes(listint_t *node1, listint_t *node2)
{
	int temp;

	temp = node1->n;
	node1->n = node2->n;
	node2->n = temp;
}

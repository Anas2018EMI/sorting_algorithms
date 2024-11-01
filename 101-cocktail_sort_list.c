#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: pointer to the head of the list
 * @node1: first node to swap
 * @node2: second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *temp;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		current = *list;

		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->next;
		}

		if (swapped == 0)
			break;

		swapped = 0;
		temp = current;

		while (temp->prev != NULL)
		{
			if (temp->n < temp->prev->n)
			{
				swap_nodes(list, temp->prev, temp);
				print_list(*list);
				swapped = 1;
			}
			else
				temp = temp->prev;
		}
	} while (swapped);
}

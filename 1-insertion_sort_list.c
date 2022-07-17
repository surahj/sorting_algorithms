#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - sorth the element of a linked list
 * @list: pointer to first node of the list
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *current_node, *previous_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (temp = (*list)->next; temp != NULL; temp = temp->next)
	{
		previous_node = temp->prev;
		current_node = temp;

		while ((previous_node != NULL) && previous_node->n > current_node->n)
		{
			swap_node(list, &previous_node, current_node);
			print_list((const listint_t *)*list);
		}
	}
}

/**
 * swap_node - swap two another
 * @h: pointer to first node of double linked list
 * @first_node: first node to swap
 * @second_node: second node to swap
 * Return: Nothing
 */

void swap_node(listint_t **h, listint_t **first_node, listint_t *second_node)
{
	(*first_node)->next = second_node->next;
	if (second_node->next != NULL)
		second_node->next->prev = *first_node;

	second_node->prev = (*first_node)->prev;
	if ((*first_node)->prev != NULL)
		(*first_node)->prev->next = second_node;

	else
		*h = second_node;

	(*first_node)->prev = second_node;
	second_node->next = *first_node;
	*first_node = second_node->prev;
}

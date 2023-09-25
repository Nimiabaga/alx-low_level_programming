#include "lists.h"
/**
 * delete_nodeint_at_index - a function that deletes the
 * node at index index of a listint_t linked list.
 * @head: pointer to the begining of list
 * @index: index of the node
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int k;
	listint_t *current;
	listint_t *prev;

	current = *head;
	if (head == NULL || *head == NULL)
		return (-1);
	for (k = 0; k < index - 1 && current != NULL && index != 0; k++)
		current = current->next;
	if (current == NULL)
		return (-1);
	if (index == 0)
	{	prev = current->next;
		free(current);
		*head = prev;
	}
	else
	{
		if (current->next == NULL)
			prev = current->next;
		else
			prev = current->next->next;
		free(current->next);
		current->next = prev;

	}
	return (1);


}


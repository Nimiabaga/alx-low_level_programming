#include "lists.h"
/**
 * free_listint_safe - a function that frees a listint_t list.
 * @head: head of a list
 * Return: the size of the list that was free’d
 */
size_t free_listint_safe(listint_t **head)
{
	size_t current = 0;
	int node_count;
	listint_t *prev;

	if (!head || !*head)

		return (0);

	while (*head)
	{
		node_count = *head - (*head)->next;
		if (node_count > 0)
		{
			prev = (*head)->next;
			free(*head);
			*head = prev;
			current++;
		}
		else
		{
			free(*head);
			*head = NULL;
			current++;
			break;
		}

	}
	*head = NULL;

	return (current);

}

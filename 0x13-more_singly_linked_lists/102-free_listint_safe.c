#include "lists.h"
/**
 * free_listint_safe - a function that frees a listint_t list.
 * @h: head of a list
 * Return: the size of the list that was free’d
 */
size_t free_listint_safe(listint_t **h)
{
	size_t current = 0;
	int node_count;
	listint_t *prev;

	if (!h || !*h)

		return (0);

	while (*h)
	{
		node_count = *h - (*h)->next;
		if (node_count > 0)
		{
			prev = (*h)->next;
			free(*h);
			*h = prev;
			current++;
		}
		else
		{
			free(*h);
			*h = NULL;
			current++;
			break;
		}

	}
	*h = NULL;

	return (current);

}

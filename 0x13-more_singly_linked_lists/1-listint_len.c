#include "lists.h"
/**
 * listint_len - counting the number of element in a list
 * @h: head pointer
 * Return: number of nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t count_node;

	if (h == NULL)
		return (0);
	for (count_node = 0; h != NULL; count_node++)
	{
		h = h->next;
	}
	return (count_node);
}

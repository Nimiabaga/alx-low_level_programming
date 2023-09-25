#include "lists.h"
/**
 * get_nodeint_at_index - a function that returns the nth
 * node of a listint_t linked list.
 * @head: pointer to the first node of a list
 * @index: node position to retrieve
 * Return: pointer to the node we are looking for, or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int new_index;

	for (new_index = 0; new_index < index; new_index++)
	{
		if (head == NULL)
			return (NULL);
		head = head->next;

	}
	return (head);

}

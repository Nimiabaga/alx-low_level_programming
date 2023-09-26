#include "lists.h"
/**
 * reverse_listint - a function that reverses a listint_t
 * linked list
 * @head: pointer to the head
 * Return: a pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *current;
	listint_t *old;

	if (head == NULL || *head == NULL)
		return (NULL);
	current = *head;
	*head = current->next;
	current->next = NULL;

	while (*head != NULL)
	{
		old = (*head)->next;
		(*head)->next = current;
		current = *head;
		if (old == NULL)
			return (*head);
		*head = old;
	}
	if (*head == NULL)
	{
		*head = current;
		return (*head);
	}
	return (NULL);

}

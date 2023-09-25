#include "lists.h"
/**
 * free_listint2 - function that frees a listint_t list
 * and set the head to null
 * @head: pointer to the first element
 */
void free_listint2(listint_t **head)
{
	listint_t *current;

	if (head == NULL || *head == NULL)
		return;
	while ((*head)->next != NULL)
	{
		current = (*head)->next;
		free(*head);
		*head = current;
	}
	free(*head);
	*head = NULL;
}

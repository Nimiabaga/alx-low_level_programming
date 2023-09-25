#include "lists.h"
/**
 * free_listint - function that frees a listint_t list.
 * @head: pointer to the first node of the list
 * Return: 0
 */
void free_listint(listint_t *head)
{
	listint_t *current;

	while ((current = head) != NULL)
	{
		head = head->next;
		free(current);
	}
}

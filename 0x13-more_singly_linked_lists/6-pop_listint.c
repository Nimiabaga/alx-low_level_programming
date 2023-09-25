#include "lists.h"
/**
 * pop_listint - a function that deletes the head node of
 * a listint_t linked list
 * and returns the head node’s data (n).
 * @head: the pointer to the list
 * Return: int
 */
int pop_listint(listint_t **head)
{
	int n;
	listint_t *current;

	if (head == NULL || *head == NULL)
		return (0);
	n = (*head)->n;
	current = *head;
	*head = (*head)->next;
	free(current);
	return (n);

}

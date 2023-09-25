#include "lists.h"
/**
 * add_nodeint - add a new node to the begining of a link list
 * @head: pointer to the head pointer
 * which the head points to the node
 * @n: new int. to be created
 * Return: new element
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	if (head == NULL)
		return (0);
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	if (*head == NULL)
		new->next = NULL;
	else
		new->next = *head;
	new->n = n;
	*head = new;

	return (new);
}

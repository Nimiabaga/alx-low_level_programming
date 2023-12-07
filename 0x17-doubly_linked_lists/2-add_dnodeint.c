#include "lists.h"
/**
 * add_dnodeint - Func adds a new node
 * @head: Head
 * @n: Elem. value
 *
 * Return: Elem. address
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *u, *v;

	u = malloc(sizeof(dlistint_t));
	if (!u)
		return (NULL);
	u->n = n;
	u->prev = NULL;
	v = *head;

	if (v != NULL)
	{
		while (v->prev != NULL)
			v = v->prev;
	}
	u->next = v;
	if (v != NULL)
		v->prev = u;
	*head = u;
	return (u);
}

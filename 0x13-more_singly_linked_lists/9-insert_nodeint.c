#include "lists.h"
/**
 * insert_new_node - a function that inserts a new node at a given position.
 * @n: the data of the new node
 * Return: pointer to the new node or NULL
 */
listint_t *insert_new_node(int n)
{
	listint_t *new_node;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;

	return (new_node);
}
/**
 * insert_nodeint_at_index - insert a node at an index in a list
 * @head: pointer to the first element
 * @idx: index to the poistion of the new node
 * @n: the data of the new node created
 * Return: the adress of the newly created node
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int j;
	listint_t *current;
	listint_t *prev;
	listint_t *new_node;

	current = *head;
	if (head == NULL)
		return (NULL);
	new_node = insert_new_node(n);
	if (new_node == NULL)
		return (NULL);
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	if (idx == 0)
	{
		*head = new_node;
	}
	for (j = 0; j < idx - 1 && current != NULL && idx != 0; j++)
		current = current->next;
	if (current == NULL)
		return (NULL);
	if (idx == 0)
		new_node->next = current;
	else
	{
		prev = current->next;
		current->next = new_node;
		new_node->next = prev;
	}
	return (new_node);

}

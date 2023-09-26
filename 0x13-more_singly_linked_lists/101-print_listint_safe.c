#include "lists.h"
/**
 * insert_listp - free linked list
 * @head: head of list
 * Return: 0
 */
void free_listp(listp_t **head)
{
	listp_t *new_ptr;
	listp_t *old_ptr;

	if (head != NULL)
	{
		old_ptr = *head;
		while ((new_ptr = old_ptr) != NULL)
		{
			old_ptr = old_ptr->next;
			free(new_ptr);
		}
		*head = NULL;

	}

}
/**
 * print_listint_safe -  a function that prints a listint_t linked list.
 * @head: head of a list
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes = 0;
	listp_t *tmp;
	listp_t *new;
	listp_t *old;

	tmp = NULL;
	while (head != NULL)
	{
		new = malloc(sizeof(listp_t));

		if (new == NULL)
			exit (98);

		new->p = (void *)head;
		new->next = tmp;
		tmp = new;

		old = tmp;

		while (old->next != NULL)
		{
			old = old->next;
			if (head == old->p)
			{

				printf("-> [%p] %d\n", (void * )head, head->n);
				free_listp(&tmp);
				return (nodes);
			}


		}
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		nodes++;
	}
	free_listp(&tmp);
	return (nodes);

}


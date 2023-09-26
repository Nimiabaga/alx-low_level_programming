#include "lists.h"
/**
 * looped_listint_len - counting number of nodes
 * @head: a pointer to the head
 * Return: if the list is not looped - 0
 * else - the numer of nnodes
 */
size_t looped_listint_len(const listint_t *head);
size_t print_list_safe(const listint_t *head);


size_t looped_listint_len(const listint_t *head)
{
	const listint_t *slow;
	const listint_t *quick;
	size_t nnodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	slow = head->next;
	quick = (head->next)->next;

	while (quick)
	{
		if (slow == quick)
		{
			slow = head;
			while (slow != quick)
			{
				nnodes++;
				slow = slow->next;
				quick = quick->next;
			}

			slow = slow->next;
			while (slow != quick)
			{
				nnodes++;
				slow = slow->next;

			}
			return (nnodes);

		}
		slow = slow->next;
		quick = (quick->next)->next;
	}

	return (0);

}
/**
 * print_listint_safe - prints a listint list
 * @head: pointer to head
 * Return: number of nnodes
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nnodes, ptr = 0;

	nnodes = looped_listint_len(head);

	if (nnodes == 0)
	{
		for (; head != NULL; nnodes++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}


	}

	else
	{
		for (ptr = 0; ptr < nnodes; ptr++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}
	return (nnodes);

}

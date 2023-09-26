#include "lists.h"
/**
 * find_listint_loop - a function that finds the loop in a linked list.
 * @head: head of a pointer
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *p2;
	listint_t *old_tmp;

	p2 = head;
	old_tmp = head;
	while (head && p2 && p2->next)
	{
		head = head->next;
		p2 = p2->next->next;

		if (head == p2)
		{
			head = old_tmp;
			old_tmp = p2;
			while (1)
			{
				p2 = old_tmp;
				while (p2 != head && p2->next != old_tmp)
				{
					p2 = p2->next;
				}
				if (p2->next == head)
					break;

				head = head->next;

			}
			return (p2->next);


		}
	}

	return (NULL);
}

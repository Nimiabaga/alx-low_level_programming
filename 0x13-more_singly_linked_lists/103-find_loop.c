#include "lists.h"
/**
 * find_listint_loop - a function that finds the loop in a linked list.
 * @head: head of a pointer
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *new;
	listint_t *old_tmp;

	new = head;
	old_tmp = head;
	while (head && new && new->next)
	{
		head = head->next;
		new = new->next->next;

		if (head == new)
		{
			head = old_tmp;
			old_tmp = new;
			while (1)
			{
				new = old_tmp;
				while (old_tmp != head && new->next != old_tmp)
				{
					new = new->next;
				}
				if (new->next == head)
					break;

				head = head->next;

			}
			return (new->next);


		}
	}

	return (NULL);
}

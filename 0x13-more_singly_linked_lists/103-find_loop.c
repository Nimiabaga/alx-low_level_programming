#include "lists.h"
/**
 * find_listint_loop - a function that finds the loop in a linked list.
 * @head: head of a pointer
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *new_tmp;
	listint_t *old_tmp;

	new_tmp = head;
	old_tmp = head;
	while (head && new_tmp && new_tmp->next)
	{
		head = head->next;
		new_tmp = new_tmp->next->next;

		if (head == new_tmp)
		{
			head = old_tmp;
			old_tmp = new_tmp;
			while (1)
			{
				new_tmp = old_tmp;
				while (old_tmp != head && new_tmp->next != old_tmp)
				{
					new_tmp = new_tmp->next;
				}
				if (new_tmp->next == head)
					break;

				head = head->next;

			}
			return (new_tmp->next);


		}
	}

	return (NULL);
}

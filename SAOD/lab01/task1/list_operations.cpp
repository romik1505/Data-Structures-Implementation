#include "list.h"
#include "node_operations.h"
#include "string.h"

void	list_cpy(t_list *dest, t_list *src)
{
	dest->bus_num = src->bus_num;
	dest->departure_date = src->departure_date;
	dest->price = src->price;
	dest->next = src->next;
}

void	list_push_back(t_list **begin_list, t_list *new_elem)
{
	t_list	*buff;

	if (begin_list && *begin_list)
	{
		buff = *begin_list;
		while (buff->next)
			buff = buff->next;
		buff->next = new_elem;
	}
	else
	{
		*begin_list = (t_list *)malloc(sizeof(t_list *));
		**begin_list = *new_elem;
	}
}

t_list	*list_search(t_list **head, int num, int (*f)(t_list, int))
{
	t_list *curr;

	if (head && *head)
	{
		curr = *head;
		while (curr)
		{
			if (f(*curr, num))
				return (curr);
			curr = curr->next;
		}
	}
	return (0);
}

int		list_insert(t_list **head, t_list *new_elem, int num_bus)
{
	t_list *buff;
	t_list *find;

	if (head && *head && new_elem)
	{
		buff = *head;
		while (buff)
		{
			if (buff->bus_num == num_bus)
				find = buff;
			buff = buff->next;
		}
		if (find)
		{
			new_elem->next = find->next;
			find->next = new_elem;
			return (1);
		}
	}
	return (0);
}

int		list_count(t_list **head, int mday, int month, int year, int num_bus, int (*f)(t_list, int, int, int, int))
{
	t_list 	*curr;
	int		count = 0;

	if (head && *head)
	{
		curr = *head;
		while (curr)
		{
			if (f(*curr, num_bus, mday, month, year))
				++count;
			curr = curr->next;
		}
	}
	return (count);
}

int		list_del_bus(t_list **head, int num_bus)
{
	t_list 	*curr;
	t_list	*prev;
	int		flag = 0;
	if (head && *head)
	{
		prev = 0;
		curr = *head;
		while (curr)
		{
			if (curr->bus_num == num_bus)
			{
				if (curr == *head)
				{
					*head = (*head)->next;
					free(curr);
				}	
				else
				{
					prev->next = curr->next;
					free(curr);
				 	curr = prev;
				}
				flag = 1;
			}
			prev = curr;
			curr = curr->next;
		}
	}
	return (flag);
}

int		list_print(t_list **head)
{
	if (!head || !*head)
		return (0);
	t_list *curr = *head;
	int i = 0;
	while (curr)
	{
		cout << "Узел [" << ++i << "]  ";
		print_list_node(curr);
		curr = curr->next;
	}
	return (1);
}

void	list_clear(t_list ***head)
{
	t_list *curr;

	if (head && *head)
		while ((curr = **head))
		{
			**head = (**head)->next;
			free(curr);
		}
}

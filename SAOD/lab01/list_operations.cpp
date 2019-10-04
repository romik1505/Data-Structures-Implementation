#include "list.h"
#include "node_operations.h"
#include "string.h"

void	list_cpy(t_list *dest, t_list *src)
{
	dest->bus_num = src->bus_num;
	dest->departure_date = src->departure_date;
	dest->departure_time = src->departure_time;
	dest->price = src->price;
	dest->next = src->next;
}

void	list_push_back(t_list **begin_list, t_list *new_elem)
{
	t_list	*list;

	if (begin_list && *begin_list)
	{
		list = *begin_list;
		while (list->next)
			list = list->next;
		list->next = new_elem;
	}
	else
	{
		*begin_list = (t_list *)malloc(sizeof(t_list *));
		**begin_list = *new_elem;
	}
}

t_list	*list_search(t_list **head, int num, int (*f)(t_list, int))
{
	t_list *buff;

	if (head && *head)
	{
		buff = *head;
		while (buff)
		{
			if (f(*buff, num))
				return (buff);
			buff = buff->next;
		}
	}
	return (0);
}

int		list_count(t_list **head, int day, int num_bus, int (*f)(t_list, int, int))
{
	t_list 	*buff;
	int		count = 0;

	if (head && *head)
	{
		buff = *head;
		while (buff)
		{
			if (f(*buff, num_bus, day))
				++count;
			buff = buff->next;
		}
	}
	return (count);
}

void	list_del_bus(t_list **head, int num_bus)
{
	t_list 	*buff;
	t_list	*prev;

	if (head && *head)
	{
		prev = 0;
		buff = *head;
		while (buff)
		{
			if (buff->bus_num == num_bus)
			{
				if (buff == *head)
					*head = (*head)->next;
				else
					prev->next = buff->next;
				free(buff);
				buff = 0;
			}
			prev = buff;
			buff = buff->next;
		}
	}
}

void	list_print(t_list **head)
{
	if (!head || !*head)
		return ;
	t_list *buff = *head;
	int i = 0;
	while (buff)
	{
		cout << "Узел [" << ++i << "]";
		print_list_node(*buff);
		buff = buff->next;
	}
}

void	list_clear(t_list ***head)
{
	t_list *buff;

	while ((buff = **head))
	{
		**head = (**head)->next;
		free(buff);
	}
	free(*head);
	*head = 0;
}

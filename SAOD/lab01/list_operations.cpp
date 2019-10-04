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
/*
t_list	*list_new(t_list *data)
{
	t_list	*list;

	list = NULL;
	list = (t_list *)malloc(sizeof(t_list));
	if (list)
	{
		//memcpy((void *)list, (void *)data, sizeof(t_list));
		list_cpy(list, data);
		list->next = NULL;
	}
	return (list);
}
*/
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

t_list *list_search(t_list **head, int (*f)(t_list elem))
{

}

void	list_print(t_list **head)
{
	if (head)
	while (*head)
	{
		print_list_node(**head);
		(*head) = (*head)->next;
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

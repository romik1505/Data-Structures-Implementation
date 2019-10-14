#include "list.h"
#include "stdlib.h"
#include "node_operations.h"
#include <iostream>

using namespace std;

list::list()
{
	head = 0;
}

list::~list()
{
	clear();
	if (head) free(head);
}

void	list::push_back(t_list *new_elem)
{
	t_list	*buff;

	if (head)
	{
		buff = head;
		while (buff->next)
			buff = buff->next;
		buff->next = new_elem;
	}
	else
		head = new_elem;
}

t_list*	list::search(int num, int (*f)(t_list, int))
{
	t_list *curr;

	if (head)
	{
		curr = head;
		while (curr)
		{
			if (f(*curr, num))
				return (curr);
			curr = curr->next;
		}
	}
	return (0);
}

int		list::insert(t_list *new_elem, int num_bus)
{
	t_list *buff;
	t_list *find;

	if (head && new_elem)
	{
		buff = head;
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

int		list::count(int mday, int month, int year, int num_bus, int (*f)(t_list, int, int, int, int))
{
	t_list 	*curr;
	int		count = 0;

	if (head)
	{
		curr = head;
		while (curr)
		{
			if (f(*curr, num_bus, mday, month, year))
				++count;
			curr = curr->next;
		}
	}
	return (count);
}

int		list::del_bus(int num_bus)
{
	t_list 	*curr;
	t_list	*prev;
	int		flag = 0;
	if (head)
	{
		prev = 0;
		curr = head;
		while (curr)
		{
			if (curr->bus_num == num_bus)
			{
				if (curr == head)
				{
					head = head->next;
					free(curr);
				}	
				else
				{
					prev->next = curr->next;
					free(curr);
				 	curr = prev;
				}
				++flag;
			}
			prev = curr;
			curr = curr->next;
		}
	}
	return (flag);
}

int		list::print()
{
	if (!head)
		return (0);
	t_list *curr = head;
	int i = 0;
	while (curr)
	{
		cout << "Узел [" << ++i << "]  ";
		print_list_node(curr);
		curr = curr->next;
	}
	return (1);
}

void	list::clear()
{
	t_list *curr;

	if (head)
		while ((curr = head))
		{
			head = head->next;
			free(curr);
		}
}

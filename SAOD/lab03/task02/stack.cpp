#include "stack.h"
#include "stdlib.h"
#include <iostream>

using namespace std;

stack::stack()
{
	top = 0;
}

stack::~stack()
{
	clear();
}

void	stack::push(int data)
{
	t_node	*buff = (t_node *)malloc(sizeof(t_node));

	buff->data = data;
	buff->next = top;
	top = buff;
}

int		stack::print()
{
	if (!top)
	{
		cout << "Стек пуст \n";
		return (0);
	}
	t_node *curr = top;
	int i = 0;
	while (curr)
	{
		cout << "Узел [" << ++i << "] = " << curr->data <<"\n";
		curr = curr->next;
	}
	return (i);
}

void	stack::clear_after(t_node *elem)
{
	if (elem)
	{
		if (elem->next)
			clear_after(elem->next);
		free(elem);
	}		
}

void	stack::clear()
{
	clear_after(top);
	top = 0;
}

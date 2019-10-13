#ifndef LIST_H
#define LIST_H

#include "stdlib.h"
#include <iostream>
using namespace std;

typedef struct 	s_list
{
	int			bus_num;			// Номер автобуса
	float		price;				// Цена билета
	int			departure_date;		// Дата и время отправки
	s_list		*next;				// Указатель на следующий узел
}				t_list;

t_list			*list_new(t_list *data);

void			print_list_node(t_list node);

void			list_push_back(t_list **head, t_list *new_elem);

t_list			*list_search(t_list **head, int num, int (*f)(t_list, int));

int				list_count(t_list **head, int mday, int month, int year, int num_bus, int (*f)(t_list, int, int, int, int));

int				list_del_bus(t_list **head, int num_bus);

int				list_insert(t_list **head, t_list *new_elem, int num_bus);

int				list_print(t_list **head);

void			list_clear(t_list ***head);

#endif
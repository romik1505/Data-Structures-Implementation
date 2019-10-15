#ifndef LIST_H
#define LIST_H

#include "stdlib.h"
#include <iostream>
using namespace std;

typedef struct 	s_list
{
	int			bus_num;			// Номер автобуса
	float		price;				// Цена билета
	int			departure_date;		// Дата и время отправки Unix-POSIX
	s_list		*next;				// Указатель на следующий узел
}				t_list;

// Добавить узел new_elem в конец списка 
void			list_push_back(t_list **head, t_list *new_elem);

// Поиск в списке автобуса с заданным номером
t_list			*list_search(t_list **head, int num, int (*f)(t_list, int));

// Подсчет количества маршрутов автобуса в заданный день
int				list_count(t_list **head, int mday, int month, int year, int num_bus, int (*f)(t_list, int, int, int, int));

// Удаление узлов из списка с заданным номером автобуса
int				list_del_bus(t_list **head, int num_bus);

// Добавление нового узла после последнего узла с заданным номером автобуса
int				list_insert(t_list **head, t_list *new_elem, int num_bus);

// Вывод списка 
int				list_print(t_list **head);

// Удаление всех элементов списка
void			list_clear(t_list ***head);

#endif
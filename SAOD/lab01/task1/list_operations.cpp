#include "list.h"
#include "node_operations.h"
#include "string.h"

// Добавить узел в конец списка
void	list_push_back(t_list **begin_list, t_list *new_elem)
{
	t_list	*buff;										// Буферная переменная

	if (begin_list && *begin_list)						// В случае существования списка
	{					
		buff = *begin_list;								// Начать с головы списка
		while (buff->next)								// Дойти до последнего узла
			buff = buff->next;							
		buff->next = new_elem;							// К последнему узлу привязать новый
	}
	else
	{
		*begin_list = (t_list *)malloc(sizeof(t_list *));	
		**begin_list = *new_elem;
	}
}

// Поиск автобуса в указанным номером
t_list	*list_search(t_list **head, int num, int (*f)(t_list, int))
{
	t_list *curr;										// Итерационная переменная

	if (head && *head)									// В случае существования списка
	{			
		curr = *head;			
		while (curr)									// Пока текущий узел существует
		{												// Указатель на функцию сравнения 
			if (f(*curr, num))							// номера автобуса и заданного номера
				return (curr);							// Вернуть указатель на узел
			curr = curr->next;							// Переход к следующему узлу
		}			
	}			
	return (0);											// Узел не найден
}

// Добавление нового узла после последнего узла с заданным номером автобуса
int		list_insert(t_list **head, t_list *new_elem, int num_bus)
{
	t_list *buff;										// Буфферная переменная
	t_list *find;										// Найденый узел

	if (head && *head && new_elem)						// В случае существования списка и нового узла
	{			
		buff = *head;									// Начать с головы списка
		while (buff)							
		{			
			if (buff->bus_num == num_bus)				// Если номер автобуса совпадает с текущим
				find = buff;							// Отмечаем его как найденый
			buff = buff->next;							// Переход к следующему узлу
		}			
		if (find)										// Если узел найден
		{			
			new_elem->next = find->next;				// Вставляем новый узел
			find->next = new_elem;			
			return (1);									// Узел найден, вставка произведена
		}			
	}			
	return (0);											// Узел не найден, вставка не произведена
}

// Подсчет количества маршрутов автобуса в заданный день
int		list_count(t_list **head, int mday, int month, int year, int num_bus, int (*f)(t_list, int, int, int, int))
{
	t_list 	*curr;										// Буферная переменная 
	int		count = 0;									// Переменная счетчик

	if (head && *head)									// В случае существования списка и нового узла
	{							
		curr = *head;									// Начать с головы списка
		while (curr)
		{
			if (f(*curr, num_bus, mday, month, year))	// Указатель на функцию сравнения 
				++count;								// Увеличение параметра счетчика
			curr = curr->next;							// Переход к следующему узлу
		}
	}
	return (count);										// Вернуть количество найденых маршрутов
}

// Удаление узлов из списка с заданным номером автобуса
int		list_del_bus(t_list **head, int num_bus)
{
	t_list 	*curr;										// Текущий узел
	t_list	*prev;										// Предыдущий узел
	int		flag = 0;									// Количество узлов с указанным номером автобуса
	if (head && *head)
	{
		prev = 0;
		curr = *head;
		while (curr)
		{
			if (curr->bus_num == num_bus)				// В случае нахождения узла
			{
				if (curr == *head)						// Если узел голова списка
				{
					*head = (*head)->next;
					free(curr);
				}	
				else									// Если узел не голова
				{
					prev->next = curr->next;
					free(curr);
				 	curr = prev;
				}
				++flag;									// Узел найден
			}
			prev = curr;
			curr = curr->next;
		}
	}
	return (flag);
}

// Вывод списка
int		list_print(t_list **head)
{
	if (!head || !*head)								// Если список не существует
		return (0);
	t_list *curr = *head;								// Переменная цикла (начинаем с головы)
	int i = 0;											// Переменная счетчик
	while (curr)
	{
		cout << "Узел [" << ++i << "]  ";	
		print_list_node(curr);							// Вывод узла списка
		curr = curr->next;								// Переход к следующему элементу
	}
	return (1);
}

// Удаление списка
void	list_clear(t_list ***head)
{
	t_list *curr;										// Переменная цикла

	if (head && *head)									// Если список существует
		while ((curr = **head))							// Начинаем удалять с головы
		{
			**head = (**head)->next;					// Следующий элемент становится головой
			free(curr);									// Предыдущий узел удаляется 
		}
}

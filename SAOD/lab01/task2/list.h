#ifndef LIST_H
#define LIST_H

typedef struct s_list
{
	int			bus_num;			// Номер автобуса
	float		price;				// Цена билета
	int			departure_date;		// Дата и время отправки
	s_list		*next;				// Указатель на следующий узел
}				t_list;

class list
{
private:
	t_list *head;
public:
	list();
	~list();
	void 	push_back(t_list *new_elem);
	t_list	*search(int num, int (*f)(t_list, int));
	int		count(int mday, int month, int year, int num_bus, int (*f)(t_list, int, int, int, int));
	int		del_bus(int num_bus);
	int		insert(t_list *new_elem, int num_bus);
	int		print();
	void	clear();
};

#endif
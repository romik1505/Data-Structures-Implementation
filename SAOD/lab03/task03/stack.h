#ifndef STACK_H
#define STACK_H

typedef struct s_node
{
	int			data;			// Данные
	s_node		*next;			// Указатель на следующий узел
}				t_node;

class stack
{
private:
	t_node *top;
public:
	stack();
	~stack();
	void 	push(int data);
	int		print();
	void	clear_after(t_node *elem);
	void	clear();
};

#endif
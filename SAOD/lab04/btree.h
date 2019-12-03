#ifndef BTREE_H
#define BTREE_H
#include "stdlib.h"

typedef struct 	s_node
{
	int 		data;
	s_node 		*left;
	s_node 		*right;
}				t_node;

// Сбалансированное дерево
class btree
{
private:
	t_node *root;

	void	balance();			// Балансировка
	void	copy_helper(t_node *&dest, t_node *src);	
	void	del_helper(t_node *&del_elem);
	void	add_helper(t_node *&root, int data);
	int		min_helper(t_node *root);
	void	absolut_helper(t_node *root);
	void	print_h_helper(t_node * p,int level);
	void	abs_helper(t_node *root, t_node *&new_tree);

public:
	btree();				// Конструктор по умолчанию
	btree(const btree &);	// Конструктор копирования
	~btree();

	void	add(int data);
	int		min();				// Вывод минимального значения
	void	print_horizontal();	// Вывод горизонтально
	void 	wide(int (*f)(t_node *));
	void	wide_print();
	void	clear();
	void	absolut();

	friend int print_tnode(t_node *el);
};

#endif
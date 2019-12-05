#ifndef BTREE_H
#define BTREE_H
#include "stdlib.h"

typedef struct 	s_node
{
	int 		data;
	int			height;
	s_node 		*left;
	s_node 		*right;
}				t_node;

// Сбалансированное дерево
class btree
{
private:

	t_node	*root;

	t_node* insert(int x, t_node *t);
	void 	copy(t_node *&dest, t_node *src);
	void	del(t_node *&del_elem);
	void	add(t_node *&root, int data);
	int		min(t_node *root);
	void	absolut(t_node *root);
	void	print_horizontal(t_node * p,int level);
	void	abs_helper(t_node *root, t_node *&new_tree);
	int		height(t_node *p);

	// Вращения 
	t_node* rotateWithLeftChild(t_node* k2);
	t_node* rotateWithRightChild(t_node *k1);
	t_node* doubleWithLeftChild(t_node *k3);
	t_node* doubleWithRightChild(t_node *k1);
	
public:
	btree();				// Конструктор по умолчанию
	btree(const btree &);	// Конструктор копирования
	~btree();

	void	copy(const btree &src);
	void	absolut(const btree &src);
	int		min();				// Вывод минимального значения
	void	print_horizontal();	// Вывод горизонтально
	void 	levelorder(int (*f)(t_node *));
	void	levelorder_print();
	void	clear();
	void	absolut();
 	void	insert(int data);


	friend int print_tnode(t_node *el);
};

#endif
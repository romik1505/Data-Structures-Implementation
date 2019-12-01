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
	int height;

	void balance();			// Балансировка
	void copy_helper(t_node *&dest, t_node *src);	
	void del_helper(t_node *&del_elem);
	void add_helper(t_node *&root, int data);
	int min_helper(t_node *root);
	void absolut_helper(t_node *root);
	void print_vhelper(t_node * p,int level);
	void get_height_helper(t_node * p,int level);
//	int btree::left_edge(t_node *p);
//	int btree::right_edge(t_node *p);
public:
	btree();				// Конструктор по умолчанию
	btree(const btree &);	// Конструктор копирования
	~btree();

	void add(int data);
	int min();				// Вывод минимального значения
	void absolut();			// Модуль всех узлов в дереве
	void print_vertical();	// Вывод вертикально
	void print_horizontal();// Вывод горизонтально
	int get_height();
	void clear();
};

#endif
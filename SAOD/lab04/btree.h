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

	void balance();			// Балансировка
	void copy_helper(t_node *dest, t_node *src);	
public:
	btree();				// Конструктор по умолчанию
	btree(const btree &);	// Конструктор копирования
	~btree();

	void add(int data);
	int min();				// Вывод минимального значения
	void absolut();			// Модуль всех узлов в дереве
	void print();			// Вывод разворачивая горизонтально
	void clear();

};

#endif
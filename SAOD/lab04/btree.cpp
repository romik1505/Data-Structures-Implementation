#include "btree.h"
#include "stdlib.h"


// Конструктор по умолчанию
btree::btree()				
{
	root = 0;
}

// Конструктор копирования
btree::btree(const btree &src)		
{
	this->root = (t_node *)malloc(sizeof(t_node));

	this->root->data = src.root->data;

}


void btree::copy_helper(t_node *dest, t_node *src)
{
	if(src == NULL)
		*dest = NULL;
	else
	{
		copy_helper(dest->left, src->left);
		copy_helper(dest->right, src->right);
	}
}

~btree()
{

}

void add(int data);
int min();				// Вывод минимального значения
void absolut();			// Модуль всех узлов в дереве
void print();			// Вывод разворачивая горизонтально
void clear();

void balance();			// Балансировка
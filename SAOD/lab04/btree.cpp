#include "btree.h"
#include "stdlib.h"
#include <iostream>
#include <iterator>
#include <list>
using namespace std;

// Конструктор по умолчанию
btree::btree()				
{
	root = 0;
}

// Конструктор копирования
btree::btree(const btree &src)		
{
	copy_helper(root, src.root);
}

// Деструктор
btree::~btree()
{
	clear();
}

void btree::copy_helper(t_node *&dest, t_node *src)
{
	if (src == NULL)
		dest = NULL;
	else
	{
		dest = (t_node *)malloc(sizeof(t_node));
		dest->data = src->data;
		copy_helper(dest->left, src->left);
		copy_helper(dest->right, src->right);
	}
}

void btree::del_helper(t_node *&del_elem)
{
	if (del_elem)
	{
		del_helper(del_elem->left);
		del_helper(del_elem->right);
		free(del_elem);
		del_elem = 0;
	}
}

void btree::clear()
{
	del_helper(root);
}

void btree::add_helper(t_node *&root, int data)
{
	if (!root)
	{
		root = (t_node *)malloc(sizeof(t_node));
		root->data = data;
		root->left = 0;
		root->right = 0;
	}
	else 
		if (data < root->data)	add_helper(root->left, data);
	else 
		if (data > root->data)	add_helper(root->right, data);
}

// Добавление узла в дерево
void btree::add(int data)
{
	add_helper(root, data);
}

int btree::min_helper(t_node *root)
{
	if (root->left)
		return(min_helper(root->left));
	else
		return (root->data);
}

// Вывод минимального значения
int btree::min()
{
	return (min_helper(root));
}

void btree::print_h_helper(t_node *p,int level)
{
	if(p)
    {
		print_h_helper(p->right,level + 1);
        for(int i = 0; i< level; i++) cout<<"   ";
        cout << p->data << endl;
		print_h_helper(p->left,level + 1);

    }
}

void btree::print_horizontal()
{
	print_h_helper(root, 0);
}

void btree::wide(int (*f)(t_node *))
{
	list <t_node*> q;
	list <t_node*>::iterator pos_begin;
	t_node *node;
	q.push_back(root);
	while (q.size() != 0)
	{
		pos_begin = q.begin();
		node = *pos_begin;
		(*f)(node);
		q.pop_front();
		if (node->left) q.push_back(node->left);
		if (node->right) q.push_back(node->right);
	}
}

int print_tnode(t_node *el)
{
	cout << el->data << " ";
}

void btree::wide_print()
{
	wide(print_tnode);
}

void btree::absolut()
{
	t_node *new_tree = 0;
	abs_helper(root, new_tree);
	clear();
	root = new_tree;
}

void btree::abs_helper(t_node *root, t_node *&new_tree)
{
	if (root)
	{
		add_helper(new_tree, abs(root->data));
		if (root->left) abs_helper(root->left, new_tree);
		if (root->right) abs_helper(root->right, new_tree);
	}
}

void balance();			// Балансировка

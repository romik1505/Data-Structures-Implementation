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
	copy(src);
}

void btree::absolut(const btree &src)
{
	clear();
	absolut(src.root);
}

void btree::absolut(t_node *p)
{
	if (p)
	{
		absolut(p->left);
		insert(abs(p->data));
		absolut(p->right);
	}
}

// Деструктор
btree::~btree()
{
	clear();
}

void btree::copy(const btree &src)
{
	clear();
	copy(this->root, src.root);
}

void btree::copy(t_node *&dest, t_node *src)
{
	if (src == NULL)
		dest = NULL;
	else
	{
		dest = (t_node *)malloc(sizeof(t_node));
		dest->data = src->data;
		dest->height = src->height;
		copy(dest->left, src->left);
		copy(dest->right, src->right);
	}
}

void btree::del(t_node *&del_elem)
{
	if (del_elem)
	{
		del(del_elem->left);
		del(del_elem->right);
		free(del_elem);
		del_elem = 0;
	}
}

void btree::clear()
{
	del(root);
}

void btree::insert(int data)
{
	root = insert(data, root);
}

t_node *btree::insert(int x, t_node *t)
{
	if (t == NULL)
	{
		t = (t_node *)malloc(sizeof(t_node));
		t->data = x;
		t->left = 0;
		t->right = 0;
	}
	else if (x < t->data)
	{
		t->left = insert(x, t->left);
		if (height(t->left) - height(t->right) == 2)
			if (x < t->left->data)
				t = rotateWithLeftChild(t);
		else
			t = doubleWithLeftChild(t);
	}
	else if (x > t->data)
	{
		t->right = insert(x, t->right);
		if (height(t->right) - height(t->left) == 2)
			if (x > t->right->data)
				t = rotateWithRightChild(t);
		else
			t = doubleWithRightChild(t);
			
	}
	t->height = max(height(t->left), height(t->right)) + 1;
	return t;
}

int btree::min(t_node *root)
{
	if (root->left)
		return(min(root->left));
	else
		return (root->data);
}

// Вывод минимального значения
int btree::min()
{
	return (min(root));
}

void btree::print_horizontal(t_node *p,int level)
{
	if(p)
    {
		print_horizontal(p->right,level + 1);
        for(int i = 0; i< level; i++) cout<<"   ";
        cout << p->data << endl;
		print_horizontal(p->left,level + 1);
    }
}

void btree::print_horizontal()
{
	print_horizontal(root, 0);
}

void btree::levelorder(int (*f)(t_node *))
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
	if (!el) return (0);
	cout << el->data << " ";
	return (1);
}

void btree::levelorder_print()
{
	levelorder(print_tnode);
}

int btree::height(t_node *t)
{
	return t == NULL ? -1 : t->height;
}

t_node* btree::rotateWithLeftChild(t_node* k2)
{
	t_node *k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = max(height(k2->left), height(k2->right)) + 1;
	k1->height = max(height(k1->left), k2->height) + 1;
	return k1;
}

t_node *btree::rotateWithRightChild(t_node *k1)
{
	t_node *k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;
	k1->height = max(height(k1->left), height(k1->right)) + 1;
	k2->height = max(height(k2->right), k1->height) + 1;
	return k2;
}

t_node *btree::doubleWithLeftChild(t_node *k3)
{
	k3->left = rotateWithRightChild(k3->left);
	return rotateWithLeftChild(k3);
}

t_node *btree::doubleWithRightChild(t_node *k1)
{
	k1->right = rotateWithLeftChild(k1->right);
	return rotateWithRightChild(k1);
}

#include "btree.h"
#include "stdlib.h"
#include <iostream>

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
	if(src == NULL)
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
	else if (data < root->data)
		add_helper(root->left, data);
	else if (data > root->data)
		add_helper(root->right, data);

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

// Модуль всех узлов в дереве
void btree::absolut()
{
	absolut_helper(root);
}

void btree::absolut_helper(t_node *p)
{
	if(p)
	{
		p->data = abs(p->data);
		absolut_helper(p->left);
		absolut_helper(p->right);
	}
}

void btree::print_vhelper(t_node *p,int level)
{
	if(p)
    {
		print_vhelper(p->right,level + 1);
        for(int i = 0; i< level; i++) cout<<"   ";
        cout << p->data << endl;
		print_vhelper(p->left,level + 1);

    }
	else 
	{
		for(int i = 0; i< level; i++) cout<<"   ";
		cout << "x\n";
	}
}

void btree::print_vertical()
{
	print_vhelper(root, 0);
}

void get_height_helper(t_node * p,int level)
{
	if(p)
    {
		get_height_helper(p->left,level + 1);
		
		get_height_helper(p->right,level + 1);

    }
}

void btree::print_horizontal()
{

}

//void balance();			// Балансировка

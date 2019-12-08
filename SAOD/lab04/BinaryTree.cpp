#include "BinaryTree.h"
#include "stdlib.h"
#include <iostream>
#include <iterator>
#include <list>
using namespace std;

// Конструктор по умолчанию
BinaryTree::BinaryTree()				
{
	root = 0;
}

// Конструктор копирования
BinaryTree::BinaryTree(const BTreeNode &src)		
{
	copy(src);
}

// Деструктор
BinaryTree::~BinaryTree()
{
	clear();
}

void BinaryTree::copy(const BinaryTree &src)
{
	clear();
	copy(this->root, src.root);
}

void BinaryTree::copy(BTreeNode *&dest, BTreeNode *src)
{
	if (src == NULL)
		dest = NULL;
	else
	{
		dest = (BTreeNode *)malloc(sizeof(BTreeNode));
		dest->data = src->data;
		dest->height = src->height;
		copy(dest->left, src->left);
		copy(dest->right, src->right);
	}
}

void BinaryTree::del(BTreeNode *&del_elem)
{
	if (del_elem)
	{
		del(del_elem->left);
		del(del_elem->right);
		free(del_elem);
		del_elem = 0;
	}
}

void BinaryTree::clear()
{
	del(root);
}

int BinaryTree::min(BTreeNode *root)
{
	if (root->left)
		return(min(root->left));
	else
		return (root->data);
}

// Вывод минимального значения
int BinaryTree::min()
{
	return (min(root));
}

void BinaryTree::print_horizontal(BTreeNode *p,int level)
{
	if(p)
    {
		print_horizontal(p->right,level + 1);
        for(int i = 0; i< level; i++) cout<<"   ";
        cout << p->data << endl;
		print_horizontal(p->left,level + 1);
    }
}

void BinaryTree::print_horizontal()
{
	print_horizontal(root, 0);
}

void BinaryTree::levelorder(int (*f)(BTreeNode *))
{
	list <BTreeNode*> q;
	list <BTreeNode*>::iterator pos_begin;
	BTreeNode *node;
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

int print_tnode(BTreeNode *el)
{
	if (!el) return (0);
	cout << el->data << " ";
	return (1);
}

void BinaryTree::levelorder_print()
{
	levelorder(print_tnode);
}

int BinaryTree::height(BTreeNode *t)
{
	return t == NULL ? -1 : t->height;
}

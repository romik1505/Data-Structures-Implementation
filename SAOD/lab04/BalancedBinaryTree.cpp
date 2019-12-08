#include "BalancedBinaryTree.h"
#include "stdlib.h"
#include <iostream>

using namespace std;

BalancedBinaryTree::BalancedBinaryTree(const BalancedBinaryTree &src)
{
	clear();
	copy(root, src.root);
}

void BalancedBinaryTree::insert(int data)
{
	root = insert(data, root);
}


void BalancedBinaryTree::absolut(const BalancedBinaryTree &src)
{
	clear();
	absolut(src.root);
}

void BalancedBinaryTree::absolut(BTreeNode *p)
{
	if (p)
	{
		absolut(p->left);
		insert(abs(p->data));
		absolut(p->right);
	}
}

BTreeNode* BalancedBinaryTree::insert(int x, BTreeNode *t)
{
	if (t == NULL)
	{
		t = (BTreeNode *)malloc(sizeof(BTreeNode));
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

BTreeNode* BalancedBinaryTree::rotateWithLeftChild(BTreeNode* k2)
{
	BTreeNode *k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = max(height(k2->left), height(k2->right)) + 1;
	k1->height = max(height(k1->left), k2->height) + 1;
	return k1;
}

BTreeNode *BalancedBinaryTree::rotateWithRightChild(BTreeNode *k1)
{
	BTreeNode *k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;
	k1->height = max(height(k1->left), height(k1->right)) + 1;
	k2->height = max(height(k2->right), k1->height) + 1;
	return k2;
}

BTreeNode *BalancedBinaryTree::doubleWithLeftChild(BTreeNode *k3)
{
	k3->left = rotateWithRightChild(k3->left);
	return rotateWithLeftChild(k3);
}

BTreeNode *BalancedBinaryTree::doubleWithRightChild(BTreeNode *k1)
{
	k1->right = rotateWithLeftChild(k1->right);
	return rotateWithRightChild(k1);
}

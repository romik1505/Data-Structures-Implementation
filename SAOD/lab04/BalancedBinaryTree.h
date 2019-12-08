#ifndef BINARYTREE_H
#include "BinaryTree.h"
#endif

#ifndef BALANCEDBINARYTREE_H
#define BALANCEDBINARYTREE_H

class BalancedBinaryTree :  public BinaryTree
{
private:
	BTreeNode * insert(int x, BTreeNode* t);
	void		absolut(BTreeNode *root);

	// Вращения 
	BTreeNode * rotateWithLeftChild(BTreeNode *k2);
	BTreeNode * rotateWithRightChild(BTreeNode *k1);
	BTreeNode * doubleWithLeftChild(BTreeNode *k3);
	BTreeNode * doubleWithRightChild(BTreeNode *k1);

public:
	BalancedBinaryTree(){};
	BalancedBinaryTree(const BalancedBinaryTree &src);
	~BalancedBinaryTree(){};
	
	void		absolut(const BalancedBinaryTree &src);
	void		insert(int data);
	
};

#endif
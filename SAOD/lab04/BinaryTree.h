#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "stdlib.h"

class BTreeNode
{
public:
    BTreeNode *left;
    BTreeNode *right;
    int height;
    int data;

    BTreeNode()
    {
        left = 0;
        right = 0;
        height = 0;
        data = 0;
    }
    BTreeNode(int data)
    {
        left = 0;
        right = 0;
        height = 0;
        this->data = data;
    }
    ~BTreeNode()
    {

    }
};

class BinaryTree
{
private:
 
    //BTreeNode*  insert(int x, BTreeNode* t);
	

protected:
    BTreeNode * root;
    int		    height(BTreeNode *p);
    void	    print_horizontal(BTreeNode *p,int level);
    void 	    copy(BTreeNode *&dest, BTreeNode* src);
	void	    del(BTreeNode *&del_elem);
	int		    min(BTreeNode *root);
	void	    abs_helper(BTreeNode* root, BTreeNode *&new_tree);
public:
    BinaryTree();
    BinaryTree(const BTreeNode &src);
    ~BinaryTree();

    void	    copy(const BinaryTree &src);

	int		    min();				           
	void	    print_horizontal();
	void 	    levelorder(int (*f)(BTreeNode *));
	void	    levelorder_print();
	void	    clear();
	void	    insert(int data); // 

};

#endif
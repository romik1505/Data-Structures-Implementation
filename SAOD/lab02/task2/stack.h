#ifndef STACK_H
#define STACK_H

#include "stdlib.h"

typedef struct 	snode
{
	char		*data;
	tnode		*next;
}				tnode;

// Стек на массиве
class stack
{
private:
	tnode *top;
	int size;
public:
	stack();
	~stack();
	void push(char *elem);
	char *pop();
};

#endif
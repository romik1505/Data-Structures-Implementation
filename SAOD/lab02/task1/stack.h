#ifndef STACK_H
#define STACK_H

#include <iostream>

// Стек на массиве
using namespace std; 

template <class Node> 
class stack
{ 
private:
	int size; 
	Node *data;
public:
	stack(); 
	stack(const stack &obj); 
	~stack(); 
	void push(Node data); 
	Node pop();
}; 

#endif
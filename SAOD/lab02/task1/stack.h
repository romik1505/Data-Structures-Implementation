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
	Node top();
	int get_size();
}; 

template <class Node> 
stack <Node>::stack() 
{ 
	size = 0;
	data = 0;
} 

// Конструктор копирования
template <class Node> 
stack<Node>::stack(const stack & obj) 
{ 
	this->size = obj.size; 
	Node *data = new Node[size]; 
	for (int i = 0; i < size; i++) this->data[i] = obj->data[i]; 
} 

template <class Node> 
stack<Node>::~stack() 
{ 
	delete[]data; 
} 

template <class Node> 
void stack<Node>::push(Node newdata) 
{ 
	Node *arr = new Node[++size]; 
	arr[0] = newdata; 
	for (int i = 1; i < size; i++)arr[i] = data[i-1]; 
	delete[] data; 
	data = arr; 
} 

template <class Node> 
Node stack<Node>::pop() 
{ 
	if (data && (size > 0)) 
	{ 
		Node tmp = data[0]; 
		Node *arr = new Node[--size]; 
		for (int i = 0; i < size; i++) 
			arr[i] = data[i + 1]; 
		delete[]data; 
		data = arr; 
		return tmp; 
	} 
	else return 0; 
} 

template <class Node> 
int stack<Node>::get_size() 
{ 
	return (size);
} 

template <class Node> 
Node stack<Node>::top() 
{ 
	if (data) return (*data);
} 

#endif
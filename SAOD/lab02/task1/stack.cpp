#include "stack.h"

#include <iostream>
using namespace std;


template <typename Node> 
stack <Node>::stack() 
{ 
	size = 0;
	data = 0;
} 

// Конструктор копирования
template <typename Node> 
stack<Node>::stack(const stack & obj) 
{ 
	this.size = obj.size; 
	Node *data = new Node[size]; 
	for (int i = 0; i < size; i++) this.data[i] = obj.data[i]; 
} 

template <typename Node> 
stack<Node>::~stack() 
{ 
	delete[]data; 
} 

template <typename Node> 
void stack<Node>::push(Node newdata) 
{ 
	Node *arr = new Node[++size]; 
	arr[0] = newdata; 
	for (int i = 1; i < size; i++)arr[i] = data[i-1]; 
	delete[] data; 
	data = arr; 
} 

template <typename Node> 
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

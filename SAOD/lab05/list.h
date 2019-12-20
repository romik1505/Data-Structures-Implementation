#include "stdlib.h"

template <class Data>
class Node
{
public:
	Data data;
	Node *next;

	Node()
	{
		data = 0;
		next = 0;
	};
	~Node();
};



template <class Data>
class list
{
private:
	Node<Data> *head;
	Node<Data> *tail;
	int size;
public:
	list();
	~list();

//	void	push_back(Data elem);
	void	push_front(Data elem);
	Data	pop_front();
//	Data	pop_back();
//	Data	get_begin();
//	Data	get_end();
//	void	del_one(int pos);
//	void	del_one(Data el);
	void	clear();
	int		get_size();
	//friend Data search(int field);
	template <class Data1> friend bool operator != (const list<Data1>& left, int right);

};

template <class Data>
list<Data>::list()
{
	head = 0;
	tail = 0;
	size = 0;
}

template <class Data>
list<Data>::~list()
{
	clear();
}

template <class Data>
void list<Data>::clear()
{
	Node<Data> *curr;

	if (head)
		while ((curr = head))
		{
			head = head->next;
			free(curr);
		}
	head = 0;
	tail = 0;
	size = 0;
}

template <class Data>
void list<Data>::push_front(Data elem)
{
	Node<Data> *buff = (Node<Data> *)malloc(sizeof(Node<Data>));

	buff->data = elem;
	buff->next = head;
	head = buff;
	++size;
}

template <class Data>
Data list<Data>::pop_front()
{
	if (!head) return (0);
	Data el = head->data;
	Node<Data> *buff = head;
	head = head->next;
	free(buff);
	--size;
	return (el);
}


template <class Data>
int list<Data>::get_size()
{
	return(size);
}

template <class Data>
bool operator != (const list<Data>& left, int right) {
    return (left.size != right);
}
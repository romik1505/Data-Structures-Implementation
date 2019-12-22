#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "stdlib.h"
#include "list.h"
#include "vector.h"
#include "list.h"
#include "product.h"

template <class Key, class Node>
class hash_table
{
protected:
	vector <list<Node> *> vect;
	
public:
	hash_table();
	~hash_table();

	int get_size();
	int get_capacity();
	//void insert(Node elem);
	int hash_function(Key key);
};

template <class Key, class Node>
int hash_table<Key,Node>::get_size()
{
	return (vect.get_size());
}

template <class Key, class Node>
int hash_table<Key, Node>::get_capacity()
{
	return (vect.get_capacity());
}

template <class Key, class Node>
int hash_table<Key, Node>::hash_function(Key k)
{
	int hash = toupper(k[0]) - 'A';
	return (hash % (vect<Node>.get_capacity()));
}

#endif
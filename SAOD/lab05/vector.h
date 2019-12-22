#ifndef VECTOR_H
#define VECTOR_H

#include "stdlib.h"
#include "string.h"

#define START_CAPACITY 4
#define RESERVE_SIZE 4

template <class Data>
class vector
{
private:
	Data	*arr;
	int		size;
	int		capacity;
public:
	vector();
	~vector();
	void	push_back(Data elem);
	void	insert(Data elem, int pos);
	void	resize(int size);
	int		get_size();
	int		get_capacity();

	Data& operator[] (const int index);
};

template <class Data>
vector<Data>::vector()
{
	arr = (Data *)malloc(sizeof(Data) * START_CAPACITY);
	size = 0;
	capacity = START_CAPACITY;
}

template <class Data>
vector<Data>::~vector()
{
	free(arr);
}

template <class Data>
void vector<Data>::push_back(Data elem)
{
	if (size + 1 > capacity)
		resize(capacity + RESERVE_SIZE);
	arr[size] = elem;
	++size;
}

template <class Data>
void vector<Data>::resize(int new_size)
{
	if (new_size < 0) return;
	Data *buff = (Data *)malloc(sizeof(Data) * new_size);
	int i = capacity - 1;

	if (new_size > capacity)
		memcpy(buff, arr, sizeof(Data)*capacity);
	else
	{
		memcpy(buff, arr, sizeof(Data)*new_size);

		// fix size
		size = 0; 
		while (i >= 0)
		{
			if (arr[i] != 0) 
			{
				size = i + 1;
				break;
			}
			--i;
		}
	}
	free(arr);
	arr = buff;
	capacity = new_size;
}

template <class Data>
void vector<Data>::insert(Data elem, int pos)
{
	if (pos >= capacity)
		resize(pos + RESERVE_SIZE + 1);	
	arr[pos] = elem;
	if (pos + 1 >= size)
		size = pos + 1;
}

template <class Data>
int vector<Data>::get_size()
{
	return (size);
}

template <class Data>
int vector<Data>::get_capacity()
{
	return (capacity);
}

template <class Data>
Data& vector<Data>::operator[] (const int index)
{
	return (arr[index]);
}

#endif

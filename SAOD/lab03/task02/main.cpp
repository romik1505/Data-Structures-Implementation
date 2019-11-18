#include "stack.h"
#include <iostream>

int main()
{
	stack A;
	int i = 0;
	while (i < 10)
		A.push(i++);
	A.print();
	A.clear();
	A.print();
	return (0);
}

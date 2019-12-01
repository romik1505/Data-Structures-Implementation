#include <iostream>
#include "btree.h"

int main()
{
	btree A;
	A.add(1);
	A.add(-3);
	A.add(5);
	A.add(4);
	A.add(2);
	A.add(-2);
	A.add(-4);
	A.add(0);
	A.add(3);

	A.print_vertical();

	std::cout << "\n\n\n";

	//std::cout << A.min();

	return (0);
}
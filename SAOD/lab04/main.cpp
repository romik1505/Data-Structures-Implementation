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

	A.print_horizontal();
	std::cout << "\n\n\n";
	A.wide_print();
	A.absolut();
	std::cout << "\n\n\n";
	A.print_horizontal();
//	std::cout <<"\n\n\n" << A.min() << "\n\n\n";
//	std::cout <<"\n\n\n" << A.absolut() << "\n\n\n";
//	A.absolut();
//	A.print_vertical();
//	std::cout <<"Height = "<< A.get_height() << "\n";
	A.wide_print();


	return (0);
}
#include "stdlib.h"
#include <iostream>
#include "square.h"

int main(int argc, char **argv)
{
	if (argc > 2)
		std::cout << square(atoi(argv[1]),atoi(argv[2]));
	return (0);
}

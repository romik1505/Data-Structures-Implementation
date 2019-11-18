#include "stack.h"

using namespace std;

int main(void)
{
	stack<int> A;

	// gov test1;
	// test1.data = 1;
	// gov test2;
	// test2.data = 2;
	// gov test3;
	// test3.data = 3;
	// gov test4;
	// test4.data = 4;
	// gov test5;
	// test5.data = 5;
	int test1 = 1, test2 = 2, test3 = 3, test4 = 4, test5 = 5;

	A.push(test1);
	A.push(test2);
	A.push(test3);
	A.push(test4);
	A.push(test5);

	A.pop();
	A.pop();
	A.pop();
	A.pop();
	A.pop();
	A.pop();
	
	return (0);
}

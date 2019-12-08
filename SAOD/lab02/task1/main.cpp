#include "stack.h"
#include <iostream>	
#include "stdio.h"
#include "evalexp.h"

using namespace std;

#define BUFF_SIZE 128



int main(void)
{
	stack<char *> A;

	char *eval = (char *)malloc(sizeof(char) * BUFF_SIZE);
	
	/*
	printf("Введите выражение: ");
	scanf("%s", eval);
	printf("\n%s\n", eval);
	free(eval);
	*/



	return (0);
}

int get_operation_priority(char ch)
{
	if (ch == '+' || ch == '-') return (1);
	if (ch == '*' || ch == '/')	return (2);
	if (ch == '(')	return (3);
}

int solve(char *eval)
{
	stack <char *> st_numbers;
	stack <> st_op;

}
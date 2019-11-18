#include "menu.h"
#include <iostream>
#include "stack.h"
#include "square.h"

using namespace std;


menu::menu(/* args */)
{
}

menu::~menu()
{
}

void	menu::show_text_menu()
{
	cout << "\n1. Введите стороны прямоугольника.\n";
	cout << "2. Добавить узел в стек.\n";
	cout << "3. Вывести стек.\n";
	cout << "4. Удалить стек.\n";
	cout << "0. Выход\n\n";
}

void	menu::show_menu()
{
	char 	ch = 0;
	stack 	A;
	unsigned int a = 0;
	unsigned int b = 0;
	int buff = 0;
	do
	{
		cout << "Нажмите чтобы продолжить\n";
		getchar();
		getchar();
		cin.clear();
		system("clear");
		show_text_menu();
		cin >> ch;
		switch (ch)
		{
		case '1':
			cout << "Введите стороны прямоугольника a и b\n";
			cin >> a >> b;
			cout << "Количество квадратов = " << square(a, b) << "\n";
		break;

		case '2':
			cout << "Введите элемент в стек: ";
			cin >> buff;
			A.push(buff);
		break;
		
		case '3':
			A.print();
		break;
		
		case '4':
			A.clear();
			cout << "Стек удален \n";
		break;
		case '0':
		break;
		}

	} while (ch != '0');
}
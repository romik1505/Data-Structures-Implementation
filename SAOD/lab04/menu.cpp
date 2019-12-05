#include "menu.h"
#include <iostream>
#include "btree.h"
using namespace std;

// Конструктор по умолчанию
menu::menu()				
{
}

// Деструктор
menu::~menu()
{
}

void	menu::show_text_menu()
{
	cout << "\n1. Вывести бинарное дерево\n";
	cout << "2. Добавить узел в бинарное дерево.\n";
	cout << "3. Вывод минимального значения в дереве\n";
	cout << "4. Обход в ширину\n";
    cout << "5. Замена отрицательных значений на его модули в дереве\n";
    cout << "6. Удаление бинарного дерева\n";
	cout << "0. Выход\n\n>";
}

void	menu::show_menu()
{
	char 	ch = 0;
	btree 	A;
    btree 	B;
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
            cout << "\nВывод дерева\n";
			A.print_horizontal();
		break;

		case '2':
			cout << "\nВведите элемент в бинарное дерево: ";
			cin >> buff;
			A.insert(buff);
		break;
		
		case '3':
			cout << "\nМинимальное значение дерева = " << A.min() << "\n";
		break;
		
        case '4':
            A.print_horizontal();
			cout << "\nОбход в ширину: ";
            A.levelorder_print();
            cout << "\n";
		break;

        case '5':
			B.absolut(A);
            A.copy(B);
            B.clear();
			A.print_horizontal();
		break;
		
        case '6':
			A.clear();
			cout << "\nДерево удалено \n";
		break;

		case '0':
		break;
		}

	} while (ch != '0');
}
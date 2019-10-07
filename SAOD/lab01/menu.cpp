#include "menu.h"

void	show_text_menu()
{
	cout << "1. Вывести список.\n";
	cout << "2. Добавить узел.\n";
	cout << "3. Вставить новый узел после последнего узла с заданным номером автобуса.\n";
	cout << "4. Удалить все узлы заданного автобуса.\n";
	cout << "5. Удалить все узлы.\n";
	cout << "6. Подсчитать, сколько раз автобус выходил на маршрут в течении заданного дня.\n";
	cout << "0. Выход\n";
}

void	filling_data(t_list *buff)
{
	cout << "Введите номер автобуса: ";
	cin >> buff->bus_num;
	cout << "\nВведите дату отправки: ";
	cin >> buff->departure_date;
	cout << "\nВведите время отправки: ";
	cin >> buff->departure_time;
	cout << "\nВведите цена билета: ";
	cin >> buff->price;
	cout << "\n";
	buff->next = 0;
}
void	show_menu()
{
	char ch = 0;
	t_list **head = (t_list **)malloc(sizeof(t_list **));
	t_list *buff = 0;
	int		num_bus = 0;
	int		day = 0;

	do
	{
		system("clear");
		show_text_menu();
		ch = getchar();
		system("sleep");
		switch (ch)
		{
		case '1':
			list_print(head);
		break;

		case '2':
			if ((buff = (t_list *)malloc(sizeof(t_list))))
			{
				filling_data(buff);
				list_push_back(head, buff);
				buff = 0;
				cout << "Узел успешно добавлен\n";
			}
			else
				cout << "Ошибка создания узла\n";
		break;
		
		case '3':
			if ((buff = (t_list *)malloc(sizeof(t_list))))
			{
				filling_data(buff);
				cout << "Введите номер автобуса за которым будет вставлен следующий";
				cin >> num_bus;
				if (list_insert(head, buff, num_bus))
					cout << "Узел успешно добавлен\n";
				else
					{
						
						cout << "Автобус не найден\nУзел удален\n";
						free(buff);
					}
				buff = 0;
			}
			else
				cout << "Ошибка создания узла\n";
			
		break;
		
		case '4':
			cout << "Задайте номер автобуса для удаления из списка\n";
			cin >> num_bus;
			if (list_del_bus(head, num_bus))
				cout << "Автобус с заданным номером был удален из списка\n";
			else
				cout << "Автобус с заданным номером не найден\n";
		break;
		
		case '5':
			list_clear(&head);
		break;
		
		case '6':
			cout << "Введите номер автобуса\n";
			cin >> num_bus;
			cout << "Введите день\n";
			cin >> day;
			cout << list_count(head, day, num_bus, is_bus_day);
		break;

		case '0':
		break;
		system("sleep");
		}
	} while (ch != '0');
	
	list_clear(&head);

}
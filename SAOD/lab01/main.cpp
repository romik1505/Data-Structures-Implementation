#include "list.h"
#include "node_operations.h"

int main()
{

	t_list *buff = (t_list *)malloc(sizeof(t_list));
	t_list **head = (t_list **)malloc(sizeof(t_list **));
	
	buff->bus_num = 1;
	buff->departure_date = 2;
	buff->departure_time = 3;
	buff->price = 4;
	buff->next = 0;

	list_push_back(head, buff);
	buff = (t_list *)malloc(sizeof(t_list));
	buff->bus_num = 2;
	buff->departure_date = 6;
	buff->departure_time = 7;
	buff->price = 8;
	buff->next = 0;
	list_push_back(head, buff);

	buff = (t_list *)malloc(sizeof(t_list));
	buff->bus_num = 1;
	buff->departure_date = 6;
	buff->departure_time = 12;
	buff->price = 999;
	buff->next = 0;
//	list_push_back(head, buff);

	list_print(head);
	//t_list *buff2 = list_search(head, 5, bus_num);
	//print_list_node(buff2);

//	cout << "--" << list_count(head, 6, 5, is_bus_day);

//	list_del_bus(head, 1);
//	list_print(head);
	list_insert(head, buff, 2);
	list_print(head);
	list_clear(&head);
	list_print(head);
	return (0);
}

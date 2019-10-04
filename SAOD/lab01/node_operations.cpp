#include "list.h"
#include "node_operations.h"

void	print_list_node(t_list node)
{
	cout << node.bus_num << "\n";
	cout << node.departure_date << "\n";
	cout << node.departure_time << "\n";
	cout << node.price << "\n";
}
#include "list.h"
#include "node_operations.h"

void	print_list_node(t_list *node)
{
	if (node)
	{
		cout << node->bus_num << " ";
		cout << node->departure_date << " ";
		cout << node->departure_time << " ";
		cout << node->price << "\n";
	}
}

int		bus_num(t_list node, int num)
{
	if (node.bus_num == num)
		return (1);
	return (0);
}

int 	is_bus_day(t_list node, int num_bus, int day)
{
	if (node.bus_num == num_bus && node.departure_date == day)
		return (1);
	return (0);
}
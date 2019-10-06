#ifndef NODE_OPERATIONS_H
#define NODE_OPERATIONS_H

#include "list.h"

void	print_list_node(t_list *node);

int		bus_num(t_list node, int num);

int 	is_bus_day(t_list node, int num_bus, int day);

#endif
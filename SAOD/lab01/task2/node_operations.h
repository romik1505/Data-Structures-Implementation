#ifndef NODE_OPERATIONS_H
#define NODE_OPERATIONS_H

#include "list.h"

#define SEC_IN_MIN		60
#define SEC_IN_HOUR		3600
#define SEC_IN_DAY		86400
#define SEC_IN_WEEK		604800
#define SEC_IN_MONTH	2629743
#define SEC_IN_YEAR		31556926

void	print_date(int date);

int		date_to_int(int hour, int min, int sec, int mday, int month, int year);

int		get_date(int date, int *hour, int *min, int *sec, int *mday, int *month, int *year);

void	print_list_node(t_list *node);

int		bus_num(t_list node, int num);

int 	is_bus_day(t_list node, int num_bus, int f_mday, int f_month, int f_year);

#endif

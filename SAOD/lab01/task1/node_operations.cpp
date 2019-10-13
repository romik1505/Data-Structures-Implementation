#include "list.h"
#include "node_operations.h"
#include "string.h"

void	print_date(int date)
{
	int year = date/SEC_IN_YEAR + 1970; 
	date -= SEC_IN_YEAR * (year - 1970);
	int month = date/SEC_IN_MONTH + 1;
	date -= SEC_IN_MONTH * (month - 1);
	int mday = date/SEC_IN_DAY + 1;
	date -= SEC_IN_DAY * (mday - 1);
	int hour = date/SEC_IN_HOUR;
	date -= SEC_IN_HOUR * hour;
	int min = date/SEC_IN_MIN;
	date -= SEC_IN_MIN * min;
	int sec = date;

	if (hour < 10) cout << "0";
	cout << hour << ":" ;
	if (min < 10) cout << "0";
	cout << min << ":";
	if (sec < 10) cout << "0";
	cout << sec << "  ";
	cout.width(2);
	cout << mday << "-";
	if (month < 10) cout << "0";
	cout << month << "-" << year;
}

int		date_to_int(int hour, int min, int sec, int mday, int month, int year)
{
	int result = 0;

	result += sec;
	result += min * SEC_IN_MIN;
	result += hour * SEC_IN_HOUR;
	result += (mday - 1) * SEC_IN_DAY;
	result += (month - 1) * SEC_IN_MONTH;
	result += (year - 1970) * SEC_IN_YEAR;
	return (result);
}

int		get_date(int date, int *hour, int *min, int *sec, int *mday, int *month, int *year)
{
	int buff_year = date/SEC_IN_YEAR + 1970; 
	date -= SEC_IN_YEAR * (buff_year - 1970);
	int buff_month = date/SEC_IN_MONTH + 1;
	date -= SEC_IN_MONTH * (buff_month - 1);
	int buff_mday = date/SEC_IN_DAY + 1;
	date -= SEC_IN_DAY * (buff_mday - 1);
	int buff_hour = date/SEC_IN_HOUR;
	date -= SEC_IN_HOUR * buff_hour;
	int buff_min = date/SEC_IN_MIN;
	date -= SEC_IN_MIN * buff_min;
	int buff_sec = date;

	if (hour) *hour = buff_hour;
	if (min) *min = buff_min;
	if (sec) *sec = buff_sec;
	if (mday) *mday = buff_mday;
	if (month) *month = buff_month;
	if (year) *year = buff_year;

	return (1);
}



void	print_list_node(t_list *node)
{
	if (node)
	{
		cout.width(10);
		cout << node->bus_num << "    ";
		print_date(node->departure_date);
		cout.width(10);
		cout << "    " << node->price << "\n";
	}
}

int		bus_num(t_list node, int num)
{
	if (node.bus_num == num)
		return (1);
	return (0);
}

int 	is_bus_day(t_list node, int num_bus, int f_mday, int f_month, int f_year)
{
	int mday = 0;
	int month = 0;
	int year = 0;

	get_date(node.departure_date, 0, 0, 0, &mday, &month, &year);
	if (node.bus_num == num_bus && mday == f_mday && month == f_month && year == f_year)
		return (1);
	return (0);
}
#ifndef PRODUCT_H
#define PRODUCT_H

#include "stdlib.h"
#include "string.h"

class product
{
private:
	char *name;
	int  code;
public:
	product();
	~product();

	void set_name(char *name);
	void set_code(int code);
	char *get_name();
	int get_code();
};

product::product()
{
	name = 0;
	code = 0;
}

product::~product()
{
	if (name)
		free(name);
}

void product::set_name(char *name)
{
	if (name) free(this->name);
	this->name = strdup(name);
}

void product::set_code(int code)
{
	this->code = code;
}

char * product::get_name()
{
	return strdup(name);
}

int product::get_code()
{
	return (code);
}



#endif
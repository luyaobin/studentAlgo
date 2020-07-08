#pragma once
#include <stdlib.h>
#include <string>
class Stock
{
public:
	Stock();
	void buy();
	void sell();
private:
	std::string name;
	int quantity;
};

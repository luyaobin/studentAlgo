#include "stock.h"
#include <iostream>

Stock::Stock()
{
}

void Stock::buy()
{
	printf("Stock [ Name: %s, Quantity: %d ] bought\n", name.c_str(), quantity);
}

void Stock::sell()
{
	printf("Stock [ Name: %s, Quantity: %d ] sold\n", name.c_str(), quantity);
}

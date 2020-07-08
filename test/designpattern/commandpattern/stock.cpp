#include "stock.h"
#include <iostream>

Stock::Stock()
{
}

void Stock::buy()
{
	printf("Stock [ Name: %s, Quantity: %d ] bought", name.c_str(), quantity);
}

void Stock::sell()
{
	printf("Stock [ Name: %s, Quantity: %d ] sold", name.c_str(), quantity);
}

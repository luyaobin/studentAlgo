#include "sellstock.h"
SellStock::SellStock(Stock *abcStock)
{
	this->abcStock = abcStock;
}

void SellStock::execute()
{
    abcStock->sell();
}

#include "buystock.h"

BuyStock::BuyStock(Stock *abcStock)
{
	this->abcStock = abcStock;
}

void BuyStock::execute()
{
    abcStock->buy();
}

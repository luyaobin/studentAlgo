#pragma once
#include "order.h"
#include "stock.h"

class BuyStock : public Order
{
public:
    BuyStock(Stock *abcStock);
	void execute();
private:
    Stock *abcStock;
};

#pragma once
#include "order.h"
#include "stock.h"

class SellStock : public Order
{
public:
    SellStock(Stock *abcStock);
	void execute();
private:
    Stock *abcStock;
};

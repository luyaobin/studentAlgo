#pragma once
#include <stdlib.h>
#include <list>
#include "order.h"
class Broker
{
public:
	Broker();
    void takeOrder(Order *order);
	void placeOrders();
private:
    std::list<Order*> orderList;
};

#include "broker.h"

Broker::Broker()
{
    orderList = std::list<Order*>();
}

void Broker::takeOrder(Order *order)
{
	orderList.push_back(order);
}

void Broker::placeOrders()
{
    for (auto it = orderList.begin(); it != orderList.end(); ++it)
	{
        (*it)->execute();
	}
	orderList.clear();
}

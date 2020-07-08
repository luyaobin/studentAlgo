#include <iostream>
#include "broker.h"
#include "order.h"
#include "stock.h"
#include "buystock.h"
#include "sellstock.h"

using namespace std;
int main(int argc, char ** argv)
{
	cout << "hello world" << endl;
    Stock *abcStock = new  Stock();
    BuyStock *buyStockOrder = new BuyStock(abcStock);
    SellStock *sellStockOrder = new SellStock(abcStock);

    Broker *broker = new Broker();
    broker->takeOrder(buyStockOrder);
    broker->takeOrder(sellStockOrder);

    broker->placeOrders();
	return 0;
}

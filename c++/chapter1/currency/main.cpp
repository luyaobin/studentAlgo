#include <iostream>
#include "currency.h"

using namespace std;
int main(int argc, char ** argv)
{
	cout << "hello world";
	currency g, h(signType::plus, 3, 50), i, j;
	g.setValue(signType::minus, 2, 25);
	i.setValue(-6.45);
	j = h.add(g);

	h.output();
	cout << " + ";
	g.output();
	cout << " = ";
	j.output();
	cout << endl;
	j = i.add(g).add(h);
	j = i.increment(g).add(h);
	cout << "Attempting to initialize with cents = 152" << endl;
	try
	{
		i.setValue(signType::plus, 3, 152);
	}
	catch (illegalParameterValue e)
	{
		cout << "Caught thrown exception" << endl;
		e.outputMessage();
	}
	return 0;
}

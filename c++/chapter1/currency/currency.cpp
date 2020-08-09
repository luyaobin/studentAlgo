#include "currency.h"

currency::currency(signType theSign, unsigned long theDollars, unsigned int theCents)
{
	setValue(theSign, theDollars, theCents);
}

currency::~currency()
{
}

void currency::setValue(signType theSign, unsigned long theDollars, unsigned int theCents)
{
	if (theCents > 99)
		throw illegalParameterValue("Cents should be < 100");

	sign = theSign;
	dollars = theDollars;
	cents = theCents;
}

void currency::setValue(double theAmount)
{
	if (theAmount < 0)
	{
		sign = signType::minus;
		theAmount = -theAmount;
	}
	else
		sign = signType::plus;

	dollars = (unsigned long) theAmount;
	cents = (unsigned int) ((theAmount + 0.001 - dollars) * 100);
}

currency currency::add(const currency &x) const
{
	long a1, a2, a3;
	currency result;
	a1 = dollars * 100 + cents;
	if (sign == signType::minus)
		a1 = -a1;
	a2 = x.dollars * 100 + x.cents;
	if (x.sign == signType::minus) a2 = -a2;
	a3 = a1 + a2;
	if (a3 < 0)
	{
		result.sign = signType::minus;
		a3 = -a3;
	}
	else
		result.sign = signType::plus;
	result.dollars = a3 / 100;
	result.cents = a3 - result.dollars * 100;

	return result;
}

currency &currency::increment(const currency &x)
{
	*this = add(x);
	return *this;
}

void currency::output() const
{
	if (sign == signType::minus) std::cout << '-';
	std::cout << '$' << dollars << '.';
	if (cents < 10) std::cout << '0';
	std::cout << cents;
}


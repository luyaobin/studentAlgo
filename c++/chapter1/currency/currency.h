#pragma once
#include "illegalparametervalue.h"
enum signType { plus, minus };

class currency
{
public:
	currency(signType theSign = signType::plus,
		unsigned long theDollars = 0,
		unsigned int theCents =0);
	~currency();
	void setValue(signType, unsigned long, unsigned int);
	void setValue(double);
	signType getSign() const { return sign; }
	unsigned long getDollars() const { return dollars; }
	unsigned int getCents() const { return cents; }
	currency add(const currency &) const;
	currency &increment(const currency&);
	void output() const;
private:
	signType sign;
	unsigned long dollars;
	unsigned int cents;
};

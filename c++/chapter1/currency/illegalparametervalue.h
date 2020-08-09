#pragma once
#include <iostream>
using namespace std;
class illegalParameterValue
{
public:
	illegalParameterValue()
		: message("illegal parameter value"){}
	illegalParameterValue(char *theMessage)
		: message(theMessage){}
	void outputMessage() { cout << message << endl; }
private:
	string message;
};


#include <iostream>
using namespace std;
int abc(int a, int b, int c)
{
	return a + b * c;
}

float abc(float a, float b, float c)
{
	return a + b * c;
}

int main(int argc, char ** argv)
{
	cout << "hello world" << endl;
	cout << abc(1, 2, 3) << endl;
	cout << abc(1.0F, 2.0F, 3.0F) << endl;
	cout << abc(1, 2, 3.0F) << endl;
	cout << abc(1.0, 2.0, 3.0) << endl;

	return 0;
}

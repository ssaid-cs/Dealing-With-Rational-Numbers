#include "Rational.hpp"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	// testing the default constructor
	Rational num;
	cout << num << endl;
	// testing the two parameter constructor
	Rational num2(1, 5);
	cout << num2 << endl;
	// testing operations
	Rational num3(1, 2);
	cout << num2 + num3 << endl;
	cout << num2 - num3 << endl;
	cout << num2 * num3 << endl;
	cout << num2 / num3 << endl;
	return 0;
}
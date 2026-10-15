#include "Rational.hpp"
#include <iostream>
using namespace std;

int Rational::getNum() const
{
	return numerator;
}
int Rational::getDenom() const
{
	return denominator;
}

void Rational::set_num(int num)
{
	numerator = num;
	simplify();
}

void Rational::set_den(int num)
{
	denominator = num;
	simplify();
}

bool Rational::operator==(const Rational& num2) const
{
	int numerator1, numerator2, denominator1, denominator2;
	numerator1 = getNum();
	denominator1 = getDenom();
	numerator2 = num2.getNum();
	denominator2 = num2.getDenom();

	if ((numerator1 * denominator2) == (numerator2 * denominator1))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Rational::operator!=(const Rational& num2) const
{
	int numerator1, numerator2, denominator1, denominator2;
	numerator1 = getNum();
	denominator1 = getDenom();
	numerator2 = num2.getNum();
	denominator2 = num2.getDenom();

	if ((numerator1 * denominator2) == (numerator2 * denominator1))
		return false;
	else
		return true;
}

bool Rational::operator<(const Rational& num2) const
{
	int numerator1, numerator2, denominator1, denominator2;
	numerator1 = getNum();
	denominator1 = getDenom();
	numerator2 = num2.getNum();
	denominator2 = num2.getDenom();

	if ((numerator1 * denominator2) < (denominator1 * numerator2))
		return true;
	else
		return false;
}

bool Rational::operator>(const Rational& num2) const
{
	int numerator1, numerator2, denominator1, denominator2;
	numerator1 = getNum();
	denominator1 = getDenom();
	numerator2 = num2.getNum();
	denominator2 = num2.getDenom();

	if ((numerator1 * denominator2) > (denominator1 * numerator2))
		return true;
	else
		return false;
}

bool Rational::operator<=(const Rational& num2) const
{
	int nume1, nume2, deno1, deno2;
	nume1 = getNum();
	deno1 = getDenom();
	nume2 = num2.getNum();
	deno2 = num2.getDenom();

	if ((nume1 * deno2) < (deno1 * nume2) || (nume1 * deno2) == (deno1 * nume2))
		return true;
	else
		return false;
}

bool Rational::operator>=(const Rational& num2) const
{
	int nume1, nume2, deno1, deno2;
	nume1 = getNum();
	deno1 = getDenom();
	nume2 = num2.getNum();
	deno2 = num2.getDenom();

	if ((nume1 * deno2) > (deno1 * nume2) || (nume1 * deno2) == (deno1 * nume2))
		return true;
	else
		return false;
}

Rational Rational::operator+(const Rational& num2)
{
	int numerator1, numerator2, denominator1, denominator2, new_num, new_den;
	numerator1 = getNum();
	denominator1 = getDenom();
	numerator2 = num2.getNum();
	denominator2 = num2.getDenom();

	if (denominator1 == denominator2)
	{
		new_num = numerator1 + numerator2;
		new_den = denominator1;
		Rational result(new_num, new_den);
		return result;
	}

	new_num = (numerator1 * denominator2) + (denominator1 * numerator2);
	new_den = denominator1 * denominator2;
	Rational result(new_num, new_den);
	result.simplify();
	return result;
}

Rational Rational::operator-(const Rational& num2)
{
	int numerator1, numerator2, denominator1, denominator2, new_num, new_den;
	numerator1 = getNum();
	denominator1 = getDenom();
	numerator2 = num2.getNum();
	denominator2 = num2.getDenom();

	if (denominator1 == denominator2)
	{
		new_num = numerator1 - numerator2;
		new_den = denominator1;
		Rational result(new_num, new_den);
		return result;
	}

	new_num = (numerator1 * denominator2) - (denominator1 * numerator2);
	new_den = denominator1 * denominator2;
	Rational result(new_num, new_den);
	result.simplify();
	return result;
}

Rational Rational::operator*(const Rational& num2)
{
	int numerator1, numerator2, denominator1, denominator2, new_num, new_den;
	numerator1 = getNum();
	denominator1 = getDenom();
	numerator2 = num2.getNum();
	denominator2 = num2.getDenom();

	new_num = numerator1 * numerator2;
	new_den = denominator1 * denominator2;
	Rational result(new_num, new_den);
	result.simplify();
	return result;
}

Rational Rational::operator/(const Rational& num2)
{
	int numerator1, numerator2, denominator1, denominator2, new_num, new_den;
	numerator1 = getNum();
	denominator1 = getDenom();
	numerator2 = num2.getNum();
	denominator2 = num2.getDenom();

	new_num = numerator1 * denominator2;
	new_den = denominator1 * numerator2;
	Rational result(new_num, new_den);
	result.simplify();
	return result;
}

ostream& operator<<(ostream& outstream, const Rational& num)
{
	outstream << num.getNum() << "/" << num.getDenom();
	return outstream;
}

istream& operator>>(istream& instream, Rational& num)
{
	int numerator, denominator;
	char a;
	instream >> numerator;
	instream >> a;
	if (a != '/')
	{
		cout << "Number must be entered as a fraction." << endl;
		exit(1);
	}
	instream >> denominator;
	num.set_num(numerator);
	num.set_den(denominator);

	return instream;
}

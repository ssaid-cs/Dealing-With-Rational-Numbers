#pragma once
#include <iostream>
#include <cmath>

class Rational {
private:
	int numerator;
	int denominator;
	int gcd(int a, int b)
	{
		a = std::abs(a);
		b = std::abs(b);
		while (b != 0)
		{
			int temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	}
	void simplify()
	{
		int gcf;
		if (denominator == 0)
			return;
		gcf = gcd(numerator, denominator);
		numerator /= gcf;
		denominator /= gcf;
		// handles numbers with a negative denominator
		if (denominator < 0)
		{
			numerator = -numerator;
			denominator = -denominator;
		}
	}

public:
	// constructors
	Rational() { numerator = 0, denominator = 1, simplify(); }
	Rational(int n) { numerator = n, denominator = 1; }
	Rational(int n, int d) { numerator = n, denominator = d, simplify(); }
	// getters
	int getNum() const;
	int getDenom() const;
	// setters
	void set_num(int num);
	void set_den(int num);
	// operator overloading
	bool operator==(const Rational& num2) const;
	bool operator!=(const Rational& num2) const;
	bool operator<(const Rational& num2) const;
	bool operator>(const Rational& num2) const;
	bool operator<=(const Rational& num2) const;
	bool operator>=(const Rational& num2) const;
	Rational operator+(const Rational& num2);
	Rational operator-(const Rational& num2);
	Rational operator*(const Rational& num2);
	Rational operator/(const Rational& num2);
	friend std::ostream& operator<<(std::ostream& outstream, const Rational& num);
	friend std::istream& operator>>(std::istream& instream, Rational& num);
};

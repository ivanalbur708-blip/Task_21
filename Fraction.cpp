#include "Fraction.h"
#include <iostream>
#include <cmath>

namespace {
	int getGCD(int a, int b) {
		a = std::abs(a);
		b = std::abs(b);
		while (b != 0) {
			int temp = b;
			b = a % b;
			a = temp;
		}
		return (a == 0) ? 1 : a;
	}
	void simplifyFranction(int& num, int& denom) {
		if (denom == 0) return;

		int gcd = getGCD(num, denom);
		num /= gcd;
		denom /= gcd;

		if (denom < 0) {
			num -= num;
			denom -= denom;
		}
	}
}


Fraction::Fraction(int num, int denom) :
	numerator(num),
	denominator(denom == 0 ? 1 : denom) {
	if (denom == 0) {
		std::cout << "Denominator cannot be zero. Setting to 1." << '\n';
	}
	simplifyFranction(numerator, denominator);
}

Fraction Fraction::add(const Fraction& f1, const Fraction& f2) {
	int num = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
	int denom = f1.denominator * f2.denominator;

	return Fraction(num, denom);
}

Fraction Fraction::operator+(const Fraction& right) const {
	int num = this->numerator * right.denominator + right.numerator * this->denominator;
	int denom = this->denominator * right.denominator;

	return Fraction(num, denom);
}

Fraction& Fraction::operator++() {
	numerator += denominator;
	return *this;
}

Fraction Fraction::operator++(int) {
	Fraction temp = *this;
	++(*this);
	return temp;
}


Fraction& Fraction::operator--()
{
	numerator -= denominator;
	return *this;
}

Fraction Fraction::operator--(int)
{
	Fraction temp = *this;
	--(*this);
	return temp;
}

Fraction Fraction::operator-(const Fraction& right) const {
	int num = this->numerator * right.denominator - right.numerator * this->denominator;
	int denom = this->denominator * right.denominator;

	return Fraction(num, denom);
}

Fraction  Fraction::operator-(int right) const
{
	int num = numerator - right * denominator;
	int denom = denominator;
	return Fraction(num, denom);
}


Fraction operator-(int left, const Fraction& right)
{
	int num = left * right.denominator - right.numerator;
	int denom = right.denominator;

	return  Fraction(num, denom);
}

std::istream& operator>>(std::istream& in, Fraction& obj) {
	
	char slesh;
	in >> obj.numerator >> slesh >> obj.denominator;

	if (obj.denominator == 0) {
		std::cout << "Denominator cannot be zero. Setting to 1." << '\n';
		obj.denominator = 1;
	}

	simplifyFranction(obj.numerator, obj.denominator);

	return in;
}

std::ostream& operator<<(std::ostream& out, const Fraction& obj) {
	out << obj.numerator << '/' << obj.denominator;
	return out;
}
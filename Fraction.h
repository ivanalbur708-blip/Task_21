#pragma once
#include <iostream>
class Fraction
{
private:
	int numerator;
	int denominator;
public:
	Fraction(int num, int denom);

	static Fraction add(const Fraction& f1, const Fraction& f2);

	Fraction operator+(const Fraction& right) const;

	Fraction& operator++();

	Fraction operator++(int);

	Fraction& operator--();

	Fraction operator--(int);

	Fraction operator-(int right) const;


	Fraction operator-(const Fraction& right) const;

	friend Fraction operator-(int left, const Fraction& right);

	friend std::ostream& operator<<(std::ostream& out, const Fraction& obj);
	friend std::istream& operator>>(std::istream& in, Fraction& obj);
};


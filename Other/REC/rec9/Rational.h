// Andrea M. Stojanovski

#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

namespace CS2124 {
	class Rational {
		friend std::istream& operator>>(std::istream& is, Rational& rhs);
		friend std::ostream& operator<<(std::ostream& os, const Rational& rhs);
		friend bool operator<(const Rational& lhs, const Rational& rhs);
		friend bool operator==(const Rational& lhs, const Rational& rhs);
	public:
		Rational(int numerator = 0, int denominator = 1);
		Rational(const Rational& otherR);
		Rational& operator+=(const Rational& otherR);
		Rational& operator++();
		Rational operator++(int dummy);
		explicit operator bool() const;
	private:
		void normalize();
		int numerator;
		int denominator;
	};

	Rational operator+(const Rational& lhs, const Rational& rhs);
	Rational& operator--(Rational& rhs);
	Rational operator--(Rational& lhs, int dummy);
	bool operator!=(const Rational& lhs, const Rational& rhs);
	bool operator>(const Rational& lhs, const Rational& rhs);
	bool operator<=(const Rational& lhs, const Rational& rhs);
	int greatestCommonDivisor(int x, int y);

}
#endif RATIONAL_H
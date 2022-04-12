// Andrea M. Stojanovski
#include "Rational.h"
using namespace std;

namespace CS2124 {
	ostream& operator<<(ostream& os, const Rational& rhs) {
		os << rhs.numerator << '/' << rhs.denominator << endl;
		return os;
	}

	istream& operator>>(istream& is, Rational& rhs) {
		char slash;
		is >> rhs.numerator >> slash >> rhs.denominator;
		rhs.normalize();
		return is;		
	}

	bool operator==(const Rational& lhs, const Rational& rhs) {
		return lhs.numerator == rhs.numerator
			&& lhs.denominator == rhs.denominator;
	}

	bool operator<(const Rational& lhs, const Rational& rhs) {
		return lhs.numerator*rhs.denominator
			< lhs.denominator*rhs.numerator;
	}

	Rational::Rational(int numerator /*=0*/, int denominator /*=1*/) : numerator(numerator), denominator(denominator) { normalize(); }
	Rational::Rational(const Rational& otherR) : numerator(otherR.numerator), denominator(otherR.denominator) {}
	Rational& Rational::operator+=(const Rational& otherR) {
		int oldDenominator = denominator;
		denominator *= otherR.denominator;
		numerator *= otherR.denominator;
		numerator += (otherR.numerator*oldDenominator);
		normalize();
		return *this;
	}

	Rational& Rational::operator++() {
		numerator += denominator;
		normalize();
		return *this;
	}

	Rational Rational::operator++(int dummy) {
		Rational result(*this);
		numerator += denominator;
		normalize();
		return result;
	}

	Rational::operator bool() const { return numerator;}

	void Rational::normalize() {
		int gcd = greatestCommonDivisor(numerator, denominator);
		numerator /= gcd;
		denominator /= gcd;
		if (denominator < 0) {
			numerator *= -1;
			denominator *= -1;
		}
	}

	Rational operator+(const Rational& lhs, const Rational& rhs) {
		Rational result(lhs);
		result += rhs;
		return result;
	}

	Rational& operator--(Rational& rhs) {
		rhs += -1;
		return rhs;
	}

	Rational operator--(Rational& lhs, int dummy) {
		Rational result(lhs);
		--lhs;
		return result;
	}

	bool operator!=(const Rational& lhs, const Rational& rhs) {
		return !(lhs == rhs);
	}

	bool operator>(const Rational& lhs, const Rational& rhs) {
		return !(lhs < rhs) and (lhs != rhs) ;
	}

	bool operator>=(const Rational& lhs, const Rational& rhs) {
		return !(lhs < rhs);
	}


	bool operator<=(const Rational& lhs, const Rational& rhs) {
		return (lhs == rhs) or (lhs < rhs);
	}

	int greatestCommonDivisor(int x, int y) {
		while (y != 0) {
			int temp = x % y;
			x = y;
			y = temp;
		}
		return x;
	}
}	

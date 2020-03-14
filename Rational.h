//
// Created by Osip on 2020-03-05.
//

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <exception>

// GreatestCommonDivisor algorithm
int GreatestCommonDivisor(int a, int b);

class Rational {
private:
    int numerator;
    int denominator;

    // utility methods
    void ReduceFraction();

public:
    // constructors
    Rational();
    Rational(int p, int q);
    Rational(const Rational& other);

    // get methods
    int getNumerator() const;
    int getDenominator() const;

    Rational operator-();
    Rational& operator=(const Rational& other);
};

std::istream& operator>>(std::istream& stream, Rational& rational);
std::ostream& operator<<(std::ostream& stream, const Rational& rational);

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);

bool operator==(const Rational& lhs, const Rational& rhs);
bool operator!=(const Rational& lhs, const Rational& rhs);

#endif //RATIONAL_H

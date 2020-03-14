//
// Created by Osip on 2020-03-05.
//

#include "Rational.h"

int GreatestCommonDivisor(int a, int b) {
    if (b == 0)
        return a;

    else
        return GreatestCommonDivisor(b, a % b);
}

// class Rational

void Rational::ReduceFraction() {
    if (GreatestCommonDivisor(numerator, denominator) != 1) {
        const int tmp = GreatestCommonDivisor(numerator, denominator);

        numerator /= tmp;
        denominator /= tmp;
    }
}

// constructors
Rational::Rational() {
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int p, int q) {
    if (q == 0)
        throw std::invalid_argument("0 denominator!");

    if (p == 0) {
        numerator = 0;
        denominator = 1;

    } else {
        numerator = abs(p);
        denominator = abs(q);

        ReduceFraction();

        if (p * q < 0)
            numerator *= -1;
    }
}

Rational::Rational(const Rational& other) {
    int p = other.getNumerator();
    int q = other.getDenominator();

    if (q == 0)
        throw std::invalid_argument("0 denominator!");

    if (p == 0) {
        numerator = 0;
        denominator = 1;

    } else {
        numerator = abs(p);
        denominator = abs(q);

        ReduceFraction();

        if (p * q < 0)
            numerator *= -1;
    }

    //std::cerr << "Copy constructor worked here! (RATIONAL)" << std::endl;
}

// "get" methods
int Rational::getNumerator() const {
    return numerator;
}

int Rational::getDenominator() const {
    return denominator;
}

Rational Rational::operator-() {
    return Rational(-numerator, denominator);
}

Rational& Rational::operator=(const Rational &other) {
    numerator = other.getNumerator();
    denominator = other.getDenominator();


    return *this;
}

// operators
std::istream& operator>>(std::istream& stream, Rational& rational) {
    if (stream) {
        int num, den;
        char divisor;

        stream >> num >> divisor >> den;
        if (stream && divisor == '/')
            rational = Rational(num, den);
    }

    return stream;
}

std::ostream& operator<<(std::ostream& stream, const Rational& rational) {
    if (stream) {
        stream << "(" << rational.getNumerator() << "/" << rational.getDenominator() << ")";
    }

    return stream;
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    int new_num = lhs.getNumerator() * rhs.getDenominator() + lhs.getDenominator() * rhs.getNumerator();
    int new_den = lhs.getDenominator() * rhs.getDenominator();

    return Rational(new_num, new_den);
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    int new_num = lhs.getNumerator() * rhs.getDenominator() - lhs.getDenominator() * rhs.getNumerator();
    int new_den = lhs.getDenominator() * rhs.getDenominator();

    return Rational(new_num, new_den);
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    int new_num = lhs.getNumerator() * rhs.getNumerator();
    int new_den = lhs.getDenominator() * rhs.getDenominator();

    return Rational(new_num, new_den);
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    if (rhs.getNumerator() == 0)
        throw std::domain_error("Division by zero");

    int new_num = lhs.getNumerator() * rhs.getDenominator();
    int new_den = lhs.getDenominator() * rhs.getNumerator();

    return Rational(new_num, new_den);
}

bool operator==(const Rational& lhs, const Rational& rhs) {
    return (lhs.getNumerator() == lhs.getNumerator() && lhs.getDenominator() == rhs.getDenominator());
}

bool operator!=(const Rational& lhs, const Rational& rhs) {
    return (lhs.getNumerator() != lhs.getNumerator() || lhs.getDenominator() != rhs.getDenominator());
}
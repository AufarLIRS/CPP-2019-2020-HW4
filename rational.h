#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

using namespace std;

class Rational
{
private:
  int numerator_;
  int denominator_;

public:
  Rational(int numerator_, int denominator_);
  int GetNumerator() const;
  int GetDenominator() const;
  Rational& operator++();
  Rational operator++(int);
  Rational& operator--();
  Rational operator--(int);
  operator double();
};
Rational operator+(Rational a, Rational b);
Rational operator-(Rational a, Rational b);
Rational operator*(Rational a, Rational b);
Rational operator/(Rational a, Rational b);
bool operator>(Rational a, Rational b);
bool operator<(Rational a, Rational b);
bool operator==(Rational a, Rational b);
bool operator!=(Rational a, Rational b);
bool operator<=(Rational a, Rational b);
bool operator>=(Rational a, Rational b);

#endif  // RATIONAL_H

#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational
{
  int numerator_;
  int denominator_;

public:
  operator double() const;
  Rational(int numerator, int denominator);

  int get_numerator() const;
  int get_denominator() const;

  Rational& operator++(int);
  Rational& operator--(int);

  Rational& operator++();
  Rational& operator--();

  static int get_gcd(int x, int y);

  static void print(Rational r);
};

Rational operator+(Rational const& r1, Rational const& r2);
Rational operator-(Rational const& r1, Rational const& r2);
Rational operator*(Rational const& r1, Rational const& r2);
Rational operator/(Rational const& r1, Rational const& r2);

bool operator>(Rational const& r1, Rational const& r2);
bool operator<(Rational const& r1, Rational const& r2);
bool operator==(Rational const& r1, Rational const& r2);
bool operator!=(Rational const& r1, Rational const& r2);
bool operator<=(Rational const& r1, Rational const& r2);
bool operator>=(Rational const& r1, Rational const& r2);

#endif  // RATIONAL_H

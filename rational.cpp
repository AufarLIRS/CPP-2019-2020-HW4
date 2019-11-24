#include "Rational.h"

Rational::Rational(int numerator, int denominator)
{
  auto gcd = GCD(numerator, denominator);

  this->numerator_ = numerator / gcd;
  this->denominator_ = denominator / gcd;
}

int Rational::GCD(int first, int second)
{
  int temp;
  while (second != 0)
  {
    temp = second;
    second = first % second;
    first = temp;
  }
  return first;
}

int Rational::get_numerator() const
{
  return numerator_;
}

int Rational::get_denominator() const
{
  return denominator_;
}

Rational operator+(Rational const& r1, Rational const& r2)
{
  return Rational(r1.get_numerator() * r2.get_denominator() + r2.get_numerator() * r1.get_denominator(),
                  r1.get_denominator() * r2.get_denominator());
}

Rational operator-(Rational const& r1, Rational const& r2)
{
  return Rational(r1.get_numerator() * r2.get_denominator() - r2.get_numerator() * r1.get_denominator(),
                  r1.get_denominator() * r2.get_denominator());
}

Rational operator*(Rational const& r1, Rational const& r2)
{
  return Rational(r1.get_numerator() * r2.get_numerator(), r1.get_denominator() * r2.get_denominator());
}

Rational operator/(Rational const& r1, Rational const& r2)
{
  return Rational(r1.get_numerator() * r2.get_denominator(), r1.get_denominator() * r2.get_numerator());
}

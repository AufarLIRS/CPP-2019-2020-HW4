#include "Rational.h"

Rational::Rational(int numerator, int denominator)
{
  int gcd = GCD(numerator, denominator);
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

int Rational::getNumerator() const
{
  return numerator_;
}

int Rational::getDenominator() const
{
  return denominator_;
}

bool operator>(Rational const& first, Rational const& second)
{
  return first.getNumerator() * second.getDenominator() > first.getDenominator() * second.getNumerator();
}

bool operator<(Rational const& first, Rational const& second)
{
  return !(first > second);
}

Rational& Rational::operator++()
{
  numerator_ += denominator_;
  return *this;
}

Rational& Rational::operator--()
{
  numerator_ -= denominator_;
  return *this;
}

Rational operator+(Rational const& first, Rational const& second)
{
  return Rational(first.getNumerator() * second.getDenominator() + second.getNumerator() * first.getDenominator(),
                  first.getDenominator() * second.getDenominator());
}

Rational operator-(Rational const& first, Rational const& second)
{
  return Rational(first.getNumerator() * second.getDenominator() - second.getNumerator() * first.getDenominator(),
                  first.getDenominator() * second.getDenominator());
}

Rational operator*(Rational const& first, Rational const& second)
{
  return Rational(first.getNumerator() * second.getNumerator(), first.getDenominator() * second.getDenominator());
}

Rational operator/(Rational const& first, Rational const& second)
{
  return Rational(first.getNumerator() * second.getDenominator(), first.getDenominator() * second.getNumerator());
}

bool operator==(Rational const& first, Rational const& second)
{
  return (first.getNumerator() == second.getNumerator() && first.getDenominator() == second.getDenominator());
}

bool operator!=(Rational const& first, Rational const& second)
{
  return !(first == second);
}

bool operator<=(Rational const& first, Rational const& second)
{
  return first == second || first < second;
}
bool operator>=(Rational const& first, Rational const& second)
{
  return first == second || first > second;
}

Rational::operator double() const
{
  return double(numerator_) / denominator_;
}

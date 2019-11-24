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

int Rational::get_numerator() const
{
  return numerator_;
}

int Rational::get_denominator() const
{
  return denominator_;
}

bool operator>(Rational first, Rational second)
{
  return first.get_numerator() * second.get_denominator() > first.get_denominator() * second.get_numerator();
}

bool operator<(Rational first, Rational second)
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

Rational operator+(Rational first, Rational second)
{
  return Rational(first.get_numerator() * second.get_denominator() + second.get_numerator() * first.get_denominator(),
                  first.get_denominator() * second.get_denominator());
}

Rational operator-(Rational first, Rational second)
{
  return Rational(first.get_numerator() * second.get_denominator() - second.get_numerator() * first.get_denominator(),
                  first.get_denominator() * second.get_denominator());
}

Rational operator*(Rational first, Rational second)
{
  return Rational(first.get_numerator() * second.get_numerator(), first.get_denominator() * second.get_denominator());
}

Rational operator/(Rational first, Rational second)
{
  return Rational(first.get_numerator() * second.get_denominator(), first.get_denominator() * second.get_numerator());
}

bool operator==(Rational first, Rational second)
{
  return (first.get_numerator() == second.get_numerator() && first.get_denominator() == second.get_denominator());
}

bool operator!=(Rational first, Rational second)
{
  return !(first == second);
}

bool operator<=(Rational first, Rational second)
{
  return first == second || first < second;
}
bool operator>=(Rational first, Rational second)
{
  return first == second || first > second;
}

Rational::operator double() const
{
  return double(numerator_) / denominator_;
}

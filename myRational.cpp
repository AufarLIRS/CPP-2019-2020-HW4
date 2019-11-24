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

int Rational::getNum() const
{
  return numerator_;
}

int Rational::getDen() const
{
  return denominator_;
}

bool operator>(Rational const& first, Rational const& second)
{
  return first.getNum() * second.getDen() > first.getDen() * second.getNum();
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
  return Rational(first.getNum() * second.getDen() + second.getNum() * first.getDen(),
                  first.getDen() * second.getDen());
}

Rational operator-(Rational const& first, Rational const& second)
{
  return Rational(first.getNum() * second.getDen() - second.getNum() * first.getDen(),
                  first.getDen() * second.getDen());
}

Rational operator*(Rational const& first, Rational const& second)
{
  return Rational(first.getNum() * second.getNum(), first.getDen() * second.getDen());
}

Rational operator/(Rational const& first, Rational const& second)
{
  return Rational(first.getNum() * second.getDen(), first.getDen() * second.getNum());
}

bool operator==(Rational const& first, Rational const& second)
{
  return (first.getNum() == second.getNum() && first.getDen() == second.getDen());
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

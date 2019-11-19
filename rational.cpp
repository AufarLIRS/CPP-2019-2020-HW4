#include "rational.h"
#include <iostream>
#include <cmath>

Rational::operator double() const
{
  return double(numerator_) / denominator_;
}

Rational::Rational(int numerator, int denominator)
{
  if (denominator == 0)
    throw std::invalid_argument("Nan is unavaliable");

  if (denominator != 0 && numerator != 0)
  {
    auto devisor = FindGCD(numerator, denominator);

    while (numerator % devisor == 0 && denominator % devisor == 0 && (devisor != 1 && devisor != -1))
    {
      denominator /= devisor;
      numerator /= devisor;
    }
  }

  if (denominator < 0)
  {
    numerator = -numerator;
    denominator = -denominator;
  }

  numerator_ = numerator;
  denominator_ = denominator;
}

int Rational::getNumerator() const
{
  return numerator_;
}

int Rational::getDenominator() const
{
  return denominator_;
}

int Rational::FindGCD(int a, int b)
{
  int temp;
  while (b != 0)
  {
    temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

Rational& Rational::operator++()
{
  numerator_ += denominator_;
  return *this;
}

Rational Rational::operator++(int)
{
  Rational tmp(*this);
  ++(*this);
  return tmp;
}

Rational& Rational::operator--()
{
  numerator_ -= denominator_;
  return *this;
}

Rational Rational::operator--(int)
{
  Rational tmp(*this);
  --(*this);
  return tmp;
}

Rational operator+(Rational const& p1, Rational const& p2)
{
  return Rational(p1.getNumerator() * p2.getDenominator() + p2.getNumerator() * p1.getDenominator(),
                  p1.getDenominator() * p2.getDenominator());
}

Rational operator-(Rational const& p1, Rational const& p2)
{
  return Rational(p1.getNumerator() * p2.getDenominator() - p2.getNumerator() * p1.getDenominator(),
                  p1.getDenominator() * p2.getDenominator());
}

Rational operator*(Rational const& p1, Rational const& p2)
{
  return Rational(p1.getNumerator() * p2.getNumerator(), p1.getDenominator() * p2.getDenominator());
}

Rational operator/(Rational const& p1, Rational const& p2)
{
  return Rational(p1.getNumerator() * p2.getDenominator(), p1.getDenominator() * p2.getNumerator());
}

bool operator>(Rational const& p1, Rational const& p2)
{
  return p1.getNumerator() * p2.getDenominator() > p2.getNumerator() * p1.getDenominator();
}

bool operator<(Rational const& p1, Rational const& p2)
{
  return p2 > p1;
}

bool operator<=(Rational const& p1, Rational const& p2)
{
  return !(p2 < p1);
}

bool operator>=(Rational const& p1, Rational const& p2)
{
  return !(p1 < p2);
}

bool operator==(Rational const& p1, Rational const& p2)
{
  return p1.getNumerator() == p2.getNumerator() && p1.getDenominator() == p2.getDenominator();
}

bool operator!=(Rational const& p1, Rational const& p2)
{
  return !(p1 == p2);
}

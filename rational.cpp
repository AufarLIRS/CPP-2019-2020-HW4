#include "rational.h"
#include <iostream>
#include <cmath>

Rational::operator double() const
{
  if (isnan_)
    return double(NAN);
  return double(numerator_) / denominator_;
}

Rational::Rational(int numerator, int denominator)
{
  isnan_ = false;
  if (denominator == 0)
    isnan_ = true;

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

bool Rational::IsNan() const
{
  return isnan_;
}

int Rational::Numerator() const
{
  return numerator_;
}

int Rational::Denominator() const
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
  if (p1.IsNan() || p2.IsNan())
    return Rational(0, 0);
  return Rational(p1.Numerator() + p2.Numerator(), p1.Denominator());
}

Rational operator-(Rational const& p1, Rational const& p2)
{
  if (p1.IsNan() || p2.IsNan())
    return Rational(0, 0);

  int mul1 = 1;
  int mul2 = 1;

  if (p1.Denominator() > p2.Denominator())
  {
    mul2 = p1.Denominator() / p2.Denominator();
  }

  if (p1.Denominator() < p2.Denominator())
  {
    mul1 = p2.Denominator() / p1.Denominator();
  }
  return Rational(p1.Numerator() * mul1 - p2.Numerator() * mul2, p1.Denominator() * mul1);
}

Rational operator*(Rational const& p1, Rational const& p2)
{
  if (p1.IsNan() || p2.IsNan())
    return Rational(0, 0);
  return Rational(p1.Numerator() * p2.Numerator(), p1.Denominator() * p2.Denominator());
}

Rational operator/(Rational const& p1, Rational const& p2)
{
  if (p1.IsNan() || p2.IsNan())
    return Rational(0, 0);
  return Rational(p1.Numerator() * p2.Denominator(), p1.Denominator() * p2.Numerator());
}

bool operator>(Rational const& p1, Rational const& p2)
{
  if (p1.IsNan() || p2.IsNan())
    throw std::invalid_argument("Cannot compare with Nan");
  return p1.Numerator() * p2.Denominator() > p2.Numerator() * p1.Denominator();
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
  if (p1.IsNan() || p2.IsNan())
    throw std::invalid_argument("Cannot compare with Nan");
  return p1.Numerator() == p2.Numerator() && p1.Denominator() == p2.Denominator();
}

bool operator!=(Rational const& p1, Rational const& p2)
{
  return !(p1 == p2);
}

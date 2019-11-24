#include "rational.h"

Rational::Rational(int numerator, int denominator = 1)
{
  auto gcd = getGCD(numerator, denominator);

  this->numerator_ = numerator / gcd;
  this->denominator_ = denominator / gcd;
}

Rational::operator double() const
{
  return double(numerator_) / denominator_;
}

int Rational::getNumerator() const
{
  return numerator_;
}

int Rational::getDenominator() const
{
  return denominator_;
}

int Rational::getGCD(int x, int y)
{
  int t;
  while (y != 0)
  {
    t = y;
    y = x % y;
    x = t;
  }
  return x;
}

void Rational::print(Rational r)
{
  std::cout << r.getNumerator() << "/" << r.getDenominator();
}

Rational operator+(Rational const& r1, Rational const& r2)
{
  return Rational(r1.getNumerator() * r2.getDenominator() + r2.getNumerator() * r1.getDenominator(),
                  r1.getDenominator() * r2.getDenominator());
}

Rational operator-(Rational const& r1, Rational const& r2)
{
  return Rational(r1.getNumerator() * r2.getDenominator() - r2.getNumerator() * r1.getDenominator(),
                  r1.getDenominator() * r2.getDenominator());
}

Rational operator*(Rational const& r1, Rational const& r2)
{
  return Rational(r1.getNumerator() * r2.getNumerator(), r1.getDenominator() * r2.getDenominator());
}

Rational operator/(Rational const& r1, Rational const& r2)
{
  return Rational(r1.getNumerator() * r2.getDenominator(), r1.getDenominator() * r2.getNumerator());
}

Rational& Rational::operator++(int)
{
  numerator_ += denominator_;
  return *this;
}

Rational& Rational::operator++()
{
  numerator_ += denominator_;
  return *this;
}

Rational& Rational::operator--(int)
{
  numerator_ -= denominator_;
  return *this;
}

Rational& Rational::operator--()
{
  numerator_ -= denominator_;
  return *this;
}

bool operator>(Rational const& r1, Rational const& r2)
{
  return r1.getNumerator() * r2.getDenominator() > r1.getDenominator() * r2.getNumerator();
}

bool operator<(Rational const& r1, Rational const& r2)
{
  return !(r1 > r2);
}

bool operator==(Rational const& r1, Rational const& r2)
{
  return (r1.getNumerator() == r2.getNumerator() && r1.getDenominator() == r2.getDenominator());
}

bool operator!=(Rational const& r1, Rational const& r2)
{
  return !(r1 == r2);
}

bool operator<=(Rational const& r1, Rational const& r2)
{
  return r1 == r2 || r1 < r2;
}
bool operator>=(Rational const& r1, Rational const& r2)
{
  return r1 == r2 || r1 > r2;
}

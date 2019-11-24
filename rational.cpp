#include "rational.h"

Rational::Rational(int numerator, int denominator = 1)
{
  auto gcd = get_gcd(numerator, denominator);

  this->numerator_ = numerator / gcd;
  this->denominator_ = denominator / gcd;
}

Rational::operator double() const
{
  return double(numerator_) / denominator_;
}

int Rational::get_numerator() const
{
  return numerator_;
}

int Rational::get_denominator() const
{
  return denominator_;
}

int Rational::get_gcd(int x, int y)
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
  std::cout << r.get_numerator() << "/" << r.get_denominator();
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
  return r1.get_numerator() * r2.get_denominator() > r1.get_denominator() * r2.get_numerator();
}

bool operator<(Rational const& r1, Rational const& r2)
{
  return !(r1 > r2);
}

bool operator==(Rational const& r1, Rational const& r2)
{
  return (r1.get_numerator() == r2.get_numerator() && r1.get_denominator() == r2.get_denominator());
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

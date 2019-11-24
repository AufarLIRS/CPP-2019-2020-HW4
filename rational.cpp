#include "rational.h"

rational::rational(int numerator, int denominator = 1)
{
  auto gcd = get_gcd(numerator, denominator);

  this->numerator_ = numerator / gcd;
  this->denominator_ = denominator / gcd;
}

int rational::get_numerator() const
{
  return numerator_;
}

int rational::get_denominator() const
{
  return denominator_;
}

int rational::get_gcd(int x, int y)
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

void rational::print(rational r)
{
  std::cout << r.get_numerator() << "/" << r.get_denominator();
}

rational operator+(rational const& r1, rational const& r2)
{
  return rational(r1.get_numerator() * r2.get_denominator() + r2.get_numerator() * r1.get_denominator(),
                  r1.get_denominator() * r2.get_denominator());
}

rational operator-(rational const& r1, rational const& r2)
{
  return rational(r1.get_numerator() * r2.get_denominator() - r2.get_numerator() * r1.get_denominator(),
                  r1.get_denominator() * r2.get_denominator());
}

rational operator*(rational const& r1, rational const& r2)
{
  return rational(r1.get_numerator() * r2.get_numerator(), r1.get_denominator() * r2.get_denominator());
}

rational operator/(rational const& r1, rational const& r2)
{
  return rational(r1.get_numerator() * r2.get_denominator(), r1.get_denominator() * r2.get_numerator());
}

rational& rational::operator++(int)
{
  numerator_ += denominator_;
  return *this;
}

rational& rational::operator++()
{
  numerator_ += denominator_;
  return *this;
}

rational& rational::operator--(int)
{
  numerator_ -= denominator_;
  return *this;
}

rational& rational::operator--()
{
  numerator_ -= denominator_;
  return *this;
}

bool operator>(rational const& r1, rational const& r2)
{
  return r1.get_numerator() * r2.get_denominator() > r1.get_denominator() * r2.get_numerator();
}

bool operator<(rational const& r1, rational const& r2)
{
  return !(r1 > r2);
}

bool operator==(rational const& r1, rational const& r2)
{
  return (r1.get_numerator() == r2.get_numerator() && r1.get_denominator() == r2.get_denominator());
}

bool operator!=(rational const& r1, rational const& r2)
{
  return !(r1 == r2);
}

bool operator<=(rational const& r1, rational const& r2)
{
  return r1 == r2 || r1 < r2;
}
bool operator>=(rational const& r1, rational const& r2)
{
  return r1 == r2 || r1 > r2;
}

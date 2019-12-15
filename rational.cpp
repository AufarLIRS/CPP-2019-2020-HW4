#include "rational.h"

Rational::Rational(int numerator_, int denominator_)
{
  // cout << "The entered rational number is : " << numerator_ << "/" << denominator_;
  // cout << endl;

  if (denominator_ < 0)
  {
    numerator_ = numerator_ * (-1);
    denominator_ = denominator_ * (-1);
  }  // сокращение двух минусов и перевод минуса в числитель

  int gcd_ = gcd(numerator_, denominator_);
  if (gcd_ != 1)
  {
    numerator_ = numerator_ / gcd_;
    denominator_ = denominator_ / gcd_;
  }  // сокращение дроби

  this->numerator_ = numerator_;
  this->denominator_ = denominator_;
}

int Rational::getNumerator() const
{
  return numerator_;
}

int Rational::getDenominator() const
{
  return denominator_;
}

int Rational::gcd(int num, int den)
{
  while (den != 0)
  {
    num = num % den;
    swap(num, den);
  }
  return num;
}

Rational operator+(Rational a, Rational b)
{
  if (a.getDenominator() == b.getDenominator())
    return Rational(a.getNumerator() + b.getNumerator(), a.getDenominator());
  else
    return Rational(a.getNumerator() * b.getDenominator() + b.getNumerator() * a.getDenominator(),
                    a.getDenominator() * b.getDenominator());
}

Rational operator-(Rational a, Rational b)
{
  if (a.getDenominator() == b.getDenominator())
    return Rational(a.getNumerator() - b.getNumerator(), a.getDenominator());
  else
    return Rational(a.getNumerator() * b.getDenominator() - b.getNumerator() * a.getDenominator(),
                    a.getDenominator() * b.getDenominator());
}

Rational operator*(Rational a, Rational b)
{
  return Rational(a.getNumerator() * b.getNumerator(), a.getDenominator() * b.getDenominator());
}

Rational operator/(Rational a, Rational b)
{
  return Rational(a.getNumerator() * b.getDenominator(), a.getDenominator() * b.getNumerator());
}

Rational& Rational::operator++()
{
  numerator_ = numerator_ + denominator_;
  return *this;
}

Rational Rational::operator++(int)
{
  Rational temp(*this);
  ++(*this);
  return temp;
}

Rational& Rational::operator--()
{
  numerator_ = numerator_ - denominator_;
  return *this;
}

Rational Rational::operator--(int)
{
  Rational temp(*this);
  --(*this);
  return temp;
}

bool operator>(Rational a, Rational b)
{
  if (a.getDenominator() == b.getDenominator())
    return (a.getNumerator() > b.getNumerator());
  else
    return (a.getNumerator() * b.getDenominator() > a.getDenominator() * b.getNumerator());
}

bool operator<(Rational a, Rational b)
{
  return b > a;
}

bool operator==(Rational a, Rational b)
{
  return ((a.getNumerator() == b.getNumerator()) && (a.getDenominator() == b.getDenominator()));
}

bool operator!=(Rational a, Rational b)
{
  return !(a == b);
}

bool operator<=(Rational a, Rational b)
{
  return !(a > b);
}

bool operator>=(Rational a, Rational b)
{
  return !(a < b);
}

Rational::operator double()
{
  return double(numerator_) / denominator_;
}

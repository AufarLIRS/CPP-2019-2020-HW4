#include "rational.h"

Rational::Rational(int numerator_, int denominator_)
{
  // cout << "The entered rational number is : " << numerator_ << "/" << denominator_;
  // cout << endl;

  if (((numerator_ < 0) && (denominator_ < 0)) || ((numerator_ > 0) && (denominator_ < 0)))
  {
    numerator_ = numerator_ * (-1);
    denominator_ = denominator_ * (-1);
  }  // сокращение двух минусов и перевод минуса в числитель

  int nod = 1;
  for (int i = abs(numerator_); i > 0; i--)
  {
    if ((abs(numerator_) % i == 0) && (abs(denominator_) % i == 0))
    {
      nod = i;
      break;
    }
  }
  if (nod != 1)
  {
    numerator_ = numerator_ / nod;
    denominator_ = denominator_ / nod;
  }  // сокращение дроби

  this->numerator_ = numerator_;
  this->denominator_ = denominator_;
}

int Rational::GetNumerator() const
{
  return numerator_;
}

int Rational::GetDenominator() const
{
  return denominator_;
}

Rational operator+(Rational a, Rational b)
{
  if (a.GetDenominator() == b.GetDenominator())
    return Rational(a.GetNumerator() + b.GetNumerator(), a.GetDenominator());
  else
    return Rational(a.GetNumerator() * b.GetDenominator() + b.GetNumerator() * a.GetDenominator(),
                    a.GetDenominator() * b.GetDenominator());
}

Rational operator-(Rational a, Rational b)
{
  if (a.GetDenominator() == b.GetDenominator())
    return Rational(a.GetNumerator() - b.GetNumerator(), a.GetDenominator());
  else
    return Rational(a.GetNumerator() * b.GetDenominator() - b.GetNumerator() * a.GetDenominator(),
                    a.GetDenominator() * b.GetDenominator());
}

Rational operator*(Rational a, Rational b)
{
  return Rational(a.GetNumerator() * b.GetNumerator(), a.GetDenominator() * b.GetDenominator());
}

Rational operator/(Rational a, Rational b)
{
  return Rational(a.GetNumerator() * b.GetDenominator(), a.GetDenominator() * b.GetNumerator());
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
  if (a.GetDenominator() == b.GetDenominator())
    return (a.GetNumerator() > b.GetNumerator());
  else
    return (a.GetNumerator() * b.GetDenominator() > a.GetDenominator() * b.GetNumerator());
}

bool operator<(Rational a, Rational b)
{
  if (a.GetDenominator() == b.GetDenominator())
    return (a.GetNumerator() < b.GetNumerator());
  else
    return (a.GetNumerator() * b.GetDenominator() < a.GetDenominator() * b.GetNumerator());
}

bool operator==(Rational a, Rational b)
{
  return ((a.GetNumerator() == b.GetNumerator()) && (a.GetDenominator() == b.GetDenominator()));
}

bool operator!=(Rational a, Rational b)
{
  return !((a.GetNumerator() == b.GetNumerator()) && (a.GetDenominator() == b.GetDenominator()));
}

bool operator<=(Rational a, Rational b)
{
  if (a.GetDenominator() == b.GetDenominator())
    return ((a.GetNumerator() < b.GetNumerator()) || (a.GetNumerator() == b.GetNumerator()));
  else
    return (a.GetNumerator() * b.GetDenominator() < a.GetDenominator() * b.GetNumerator()) ||
           ((a.GetNumerator() == b.GetNumerator()) && (a.GetDenominator() == b.GetDenominator()));
}

bool operator>=(Rational a, Rational b)
{
  if (a.GetDenominator() == b.GetDenominator())
    return ((a.GetNumerator() > b.GetNumerator()) || (a.GetNumerator() == b.GetNumerator()));
  else
    return ((a.GetNumerator() * b.GetDenominator() > a.GetDenominator() * b.GetNumerator()) ||
            ((a.GetNumerator() == b.GetNumerator()) && (a.GetDenominator() == b.GetDenominator())));
}

Rational::operator double()
{
  return double(numerator_) / denominator_;
}

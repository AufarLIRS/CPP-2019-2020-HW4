#include "Rational.h"

Rational::Rational(int nomin, int denomin)
{
  this->nomin = nomin;
  this->denomin = denomin;
  normalize();
}
Rational::Rational(int a)
{
  this->nomin = a;
  this->denomin = 1;
}

Rational::Rational(const double rational_)
{
  double rational = rational_;
  int nom1 = (int)rational;
  rational = rational - nom1;
  int nom2 = 0, denomin = 1;
  while (rational)
  {
    nom2 = nom2 * 10 + (rational * 10 - rational);
    rational *= 10;
    denomin *= 10;
  }

  Rational a(nom2, denomin);
  this->nomin = nom1 * a.getDenominator() + nom2;
  this->denomin = a.getDenominator();
}

int getGCF(int a, int b)
{
  if (a < 0)
    a *= -1;
  if (b < 0)
    b *= -1;

  while (a != b)
  {
    if (a < b)
      a = b - a;
    else
      b = a - b;
  }
  return a;
}

void Rational::normalize()
{
  int tmpGCF;
  while ((tmpGCF = getGCF(nomin, denomin)) != 1)
  {
    nomin /= tmpGCF;
    denomin /= tmpGCF;
  }
}

int Rational::getNominator() const
{
  return nomin;
}

int Rational::getDenominator() const
{
  return denomin;
}

Rational Rational::operator+(const Rational& b)
{
  return Rational(this->getNominator() * b.getDenominator() + b.getNominator() * this->getDenominator(),
                  this->getDenominator() * b.getDenominator());
}

Rational Rational::operator-(const Rational& b)
{
  return Rational(this->getNominator() * b.getDenominator() - b.getNominator() * this->getDenominator(),
                  this->getDenominator() * b.getDenominator());
}

Rational Rational::operator*(const Rational& b)
{
  return Rational(this->getNominator() * b.getNominator(), this->getDenominator() * b.getDenominator());
}

Rational Rational::operator/(const Rational& b)
{
  return Rational(this->getNominator() * b.getDenominator(), this->getDenominator() * b.getNominator());
}

Rational& Rational::operator++()
{
  this->nomin += this->denomin;
  return *this;
}
Rational Rational::operator++(int)
{
  this->nomin += this->denomin;
  return *this;
}

/*Rational Rational::operator+(double b)
{
  Rational d(b);
  return Rational(this->getNominator() * d.getDenominator() + d.getNominator() * this->getDenominator(),
                  this->getDenominator() * d.getDenominator());
}

Rational Rational::operator-(double b)
{
  Rational d(b);
  return Rational(this->getNominator() * d.getDenominator() - d.getNominator() * this->getDenominator(),
                  this->getDenominator() * d.getDenominator());
}

Rational Rational::operator*(double b)
{
  Rational d(b);
  return Rational(this->getNominator() * d.getNominator(), this->getDenominator() * d.getDenominator());
}

Rational Rational::operator/(double b)
{
  Rational d(b);
  return Rational(this->getNominator() * d.getDenominator(), this->getDenominator() * d.getNominator());
}*/

bool Rational::operator<(const Rational a)
{
  return *this - a < 0;
}
bool Rational::operator>(const Rational a)
{
  return *this - a > 0;
}
bool Rational::operator<=(const Rational a)
{
  return *this - a <= 0;
}
bool Rational::operator>=(const Rational a)
{
  return *this - a >= 0;
}
bool Rational::operator!=(const Rational a)
{
  return *this - a != 0;
}
bool Rational::operator==(const Rational a)
{
  return *this - a == 0;
}

bool Rational::operator<(int a)
{
  return this->nomin / this->denomin < a;
}
bool Rational::operator>(int a)
{
  return this->nomin / this->denomin > a;
}
bool Rational::operator<=(int a)
{
  return this->nomin / this->denomin <= a;
}
bool Rational::operator>=(int a)
{
  return this->nomin / this->denomin >= a;
}
bool Rational::operator!=(int a)
{
  return this->nomin / this->denomin != a;
}
bool Rational::operator==(int a)
{
  return this->nomin / this->denomin == a;
}

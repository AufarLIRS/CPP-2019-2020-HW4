#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{
  int nomin, denomin;
  void normalize();

public:
  Rational(const int a);
  Rational(const double a);
  Rational(int nomin, int denomin);

  int getNominator() const;
  int getDenominator() const;
  Rational operator+(const Rational& b);
  Rational operator-(const Rational& b);
  Rational operator*(const Rational& b);
  Rational operator/(const Rational& b);

  Rational& operator++();
  Rational operator++(int);

  /*Rational operator+(double b);
  Rational operator-(double b);
  Rational operator*(double b);
  Rational operator/(double b);*/

  bool operator<(const Rational a);
  bool operator>(const Rational a);
  bool operator<=(const Rational a);
  bool operator>=(const Rational a);
  bool operator!=(const Rational a);
  bool operator==(const Rational a);

  bool operator<(const int a);
  bool operator>(const int a);
  bool operator<=(const int a);
  bool operator>=(const int a);
  bool operator!=(const int a);
  bool operator==(const int a);
};

#endif  // RATIONAL_H

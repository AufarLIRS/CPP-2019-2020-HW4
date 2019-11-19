#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{
  int numerator_;
  int denominator_;
  bool isnan_;

public:
  operator double() const;
  // to reduce amount of override operations explicit constructor is used
  explicit Rational(int numerator, int denominator = 1);
  bool IsNan() const;

  int Numerator() const;

  int Denominator() const;

  static int FindGCD(int a, int b);

  Rational& operator++();

  Rational operator++(int);

  Rational& operator--();

  Rational operator--(int);
};

Rational operator+(Rational const& p1, Rational const& p2);

Rational operator-(Rational const& p1, Rational const& p2);

Rational operator*(Rational const& p1, Rational const& p2);

Rational operator/(Rational const& p1, Rational const& p2);

bool operator>(Rational const& p1, Rational const& p2);
bool operator<(Rational const& p1, Rational const& p2);
bool operator<=(Rational const& p1, Rational const& p2);
bool operator>=(Rational const& p1, Rational const& p2);
bool operator==(Rational const& p1, Rational const& p2);
bool operator!=(Rational const& p1, Rational const& p2);

#endif  // RATIONAL_H

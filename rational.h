#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class rational
{
  int numerator_;
  int denominator_;

public:
  rational(int numerator, int denominator);

  int get_numerator() const;
  int get_denominator() const;

  rational& operator++(int);
  rational& operator--(int);

  rational& operator++();
  rational& operator--();

  static int get_gcd(int x, int y);

  static void print(rational r);
};

rational operator+(rational const& r1, rational const& r2);
rational operator-(rational const& r1, rational const& r2);
rational operator*(rational const& r1, rational const& r2);
rational operator/(rational const& r1, rational const& r2);

bool operator>(rational const& r1, rational const& r2);
bool operator<(rational const& r1, rational const& r2);
bool operator==(rational const& r1, rational const& r2);
bool operator!=(rational const& r1, rational const& r2);
bool operator<=(rational const& r1, rational const& r2);
bool operator>=(rational const& r1, rational const& r2);

#endif  // RATIONAL_H

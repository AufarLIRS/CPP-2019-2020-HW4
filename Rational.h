#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{
  int numerator_;
  int denominator_;

public:
  Rational(int numerator, int denominator);
  int get_numerator() const;
  int get_denominator() const;
  int GCD(int first, int second);
  Rational& operator--();
  Rational& operator++();
  operator double() const;
};

#endif  // RATIONAL_H

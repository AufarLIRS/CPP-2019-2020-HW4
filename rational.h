#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{
public:
  int numerator_;
  int denominator_;
  Rational(int numerator, int denominator);
  int get_numerator() const;
  int get_denominator() const;
  int GCD(int first, int second);
};

#endif  // RATIONAL_H

#ifndef RATIONAL_H
#define RATIONAL_H


class Rational
{
    int nomin, denomin;
    void normalize();

public:
    Rational (int a);
    Rational (double a);
    Rational(int nomin, int denomin);

    int  getNominator();
    int  getDenominator();
    Rational operator+(Rational &b);
    Rational operator-(Rational &b);
    Rational operator*(Rational &b);
    Rational operator/(Rational &b);

    Rational & operator++();
    Rational operator++(int);

    Rational operator+(double b);
    Rational operator-(double b);
    Rational operator*(double b);
    Rational operator/(double b);

    bool operator<(Rational a);
    bool operator>(Rational a);
    bool operator<=(Rational a);
    bool operator>=(Rational a);
    bool operator!=(Rational a);
    bool operator==(Rational a);

    bool operator<(int a);
    bool operator>(int a);
    bool operator<=(int a);
    bool operator>=(int a);
    bool operator!=(int a);
    bool operator==(int a);
};

#endif // RATIONAL_H

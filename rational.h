#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational {
public:
  Rational();         // Конструктор без параметров
  Rational(int, int); // Конструктор с двумя параметрами

  friend double operator+(const double, Rational &); // Оператор +
  friend double operator+(Rational &, const double); // Оператор +
  friend double operator+(Rational &, Rational &);   // Оператор +
  friend double operator-(const double, Rational &); // Оператор -
  friend double operator-(Rational &, const double); // Оператор -
  friend double operator-(Rational &, Rational &);   // Оператор -
  friend double operator*(const double, Rational &); // Оператор *
  friend double operator*(Rational &, const double); // Оператор *
  friend double operator*(Rational &, Rational &);   // Оператор *
  friend double operator/(const double, Rational &); // Оператор /
  friend double operator/(Rational &, const double); // Оператор /
  friend double operator/(Rational &, Rational &);   // Оператор /

  Rational operator++();          // Префиксный ++
  Rational operator++(const int); // Постпрефиксный ++
  Rational operator--();          // Префиксный --
  Rational operator--(const int); // Постпрефиксный --

  friend bool operator==(const int, Rational &rat); // Оператор сравнения ==
  friend bool operator==(Rational &rat, const int); // Оператор сравнения ==
  friend bool operator!=(const int, Rational &rat); // Оператор сравнения !=
  friend bool operator!=(Rational &rat, const int); // Оператор сравнения !=
  friend bool operator>(const int, Rational &rat); // Оператор сравнения >
  friend bool operator>(Rational &rat, const int); // Оператор сравнения >
  friend bool operator<(const int, Rational &rat); // Оператор сравнения <
  friend bool operator<(Rational &rat, const int); // Оператор сравнения <
  friend bool operator>=(const int, Rational &rat); // Оператор сравнения >=
  friend bool operator>=(Rational &rat, const int); // Оператор сравнения >=
  friend bool operator<=(const int, Rational &rat); // Оператор сравнения <=
  friend bool operator<=(Rational &rat, const int); // Оператор сравнения <=

  int get_n();     // Геттер для numeration_
  int get_d();     // Геттер для denumerator_
  double get_db(); // Геттер для db

  int gcd(int, int); // НОД

private:
  int numerator_;
  int denumerator_;
  double db;
};

#endif // RATIONAL_H

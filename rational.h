#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational
{
public:
  Rational();          // Конструктор без параметров
  Rational(int, int);  // Конструктор с двумя параметрами

  // friend double operator+(const double, Rational &); // Оператор +
  // friend double operator+(Rational &, const double); // Оператор +
  // friend double operator+(Rational &, Rational &);   // Оператор +

  // Оператор + для Task 3*
  template <typename R, typename D>
  friend double operator+(R rr, D dd)
  {
    if (std::is_same<R, Rational>::value && std::is_same<D, double>::value)
    {
      auto* r2 = &rr;
      Rational* r1 = reinterpret_cast<Rational*>(r2);
      auto* d2 = &dd;
      double* d1 = reinterpret_cast<double*>(d2);
      return static_cast<double>(r1->get_n()) / static_cast<double>(r1->get_d()) + *d1;
    }
    else if (std::is_same<R, double>::value && std::is_same<D, Rational>::value)
    {
      auto* d2 = &dd;
      Rational* r1 = reinterpret_cast<Rational*>(d2);
      auto* r2 = &rr;
      double* d1 = reinterpret_cast<double*>(r2);
      return *d1 + static_cast<double>(r1->get_n()) / static_cast<double>(r1->get_d());
    }
    else if (std::is_same<R, Rational>::value && std::is_same<D, Rational>::value)
    {
      auto* r2 = &rr;
      Rational* r1 = reinterpret_cast<Rational*>(r2);
      auto* d2 = &dd;
      Rational* d1 = reinterpret_cast<Rational*>(d2);
      return static_cast<double>(r1->get_n()) / static_cast<double>(r1->get_d()) +
             static_cast<double>(d1->get_n()) / static_cast<double>(d1->get_d());
    }
    return 0.0;
  }

  // friend double operator-(const double, Rational &); // Оператор -
  // friend double operator-(Rational &, const double); // Оператор -
  // friend double operator-(Rational &, Rational &);   // Оператор -

  // Оператор - для Task 3*
  template <typename R, typename D>
  friend double operator-(R rr, D dd)
  {
    if (std::is_same<R, Rational>::value && std::is_same<D, double>::value)
    {
      auto* r2 = &rr;
      Rational* r1 = reinterpret_cast<Rational*>(r2);
      auto* d2 = &dd;
      double* d1 = reinterpret_cast<double*>(d2);
      return static_cast<double>(r1->get_n()) / static_cast<double>(r1->get_d()) - *d1;
    }
    else if (std::is_same<R, double>::value && std::is_same<D, Rational>::value)
    {
      auto* d2 = &dd;
      Rational* r1 = reinterpret_cast<Rational*>(d2);
      auto* r2 = &rr;
      double* d1 = reinterpret_cast<double*>(r2);
      return *d1 - static_cast<double>(r1->get_n()) / static_cast<double>(r1->get_d());
    }
    else if (std::is_same<R, Rational>::value && std::is_same<D, Rational>::value)
    {
      auto* r2 = &rr;
      Rational* r1 = reinterpret_cast<Rational*>(r2);
      auto* d2 = &dd;
      Rational* d1 = reinterpret_cast<Rational*>(d2);
      return static_cast<double>(r1->get_n()) / static_cast<double>(r1->get_d()) -
             static_cast<double>(d1->get_n()) / static_cast<double>(d1->get_d());
    }
    return 0.0;
  }

  // friend double operator*(const double, Rational &); // Оператор *
  // friend double operator*(Rational &, const double); // Оператор *
  // friend double operator*(Rational &, Rational &);   // Оператор *

  // Оператор - для Task 3*
  template <typename R, typename D>
  friend double operator*(R rr, D dd)
  {
    if (std::is_same<R, Rational>::value && std::is_same<D, double>::value)
    {
      auto* r2 = &rr;
      Rational* r1 = reinterpret_cast<Rational*>(r2);
      auto* d2 = &dd;
      double* d1 = reinterpret_cast<double*>(d2);
      return static_cast<double>(r1->get_n()) / static_cast<double>(r1->get_d()) * *d1;
    }
    else if (std::is_same<R, double>::value && std::is_same<D, Rational>::value)
    {
      auto* d2 = &dd;
      Rational* r1 = reinterpret_cast<Rational*>(d2);
      auto* r2 = &rr;
      double* d1 = reinterpret_cast<double*>(r2);
      return *d1 * static_cast<double>(r1->get_n()) / static_cast<double>(r1->get_d());
    }
    else if (std::is_same<R, Rational>::value && std::is_same<D, Rational>::value)
    {
      auto* r2 = &rr;
      Rational* r1 = reinterpret_cast<Rational*>(r2);
      auto* d2 = &dd;
      Rational* d1 = reinterpret_cast<Rational*>(d2);
      return static_cast<double>(r1->get_n()) / static_cast<double>(r1->get_d()) * static_cast<double>(d1->get_n()) /
             static_cast<double>(d1->get_d());
    }
    return 0.0;
  }

  // friend double operator/(const double, Rational &); // Оператор /
  // friend double operator/(Rational &, const double); // Оператор /
  // friend double operator/(Rational &, Rational &);   // Оператор /

  // Оператор - для Task 3*
  template <typename R, typename D>
  friend double operator/(R rr, D dd)
  {
    if (std::is_same<R, Rational>::value && std::is_same<D, double>::value)
    {
      auto* r2 = &rr;
      Rational* r1 = reinterpret_cast<Rational*>(r2);
      auto* d2 = &dd;
      double* d1 = reinterpret_cast<double*>(d2);
      return static_cast<double>(r1->get_n()) / static_cast<double>(r1->get_d()) / *d1;
    }
    else if (std::is_same<R, double>::value && std::is_same<D, Rational>::value)
    {
      auto* d2 = &dd;
      Rational* r1 = reinterpret_cast<Rational*>(d2);
      auto* r2 = &rr;
      double* d1 = reinterpret_cast<double*>(r2);
      return *d1 / static_cast<double>(r1->get_n()) / static_cast<double>(r1->get_d());
    }
    else if (std::is_same<R, Rational>::value && std::is_same<D, Rational>::value)
    {
      auto* r2 = &rr;
      Rational* r1 = reinterpret_cast<Rational*>(r2);
      auto* d2 = &dd;
      Rational* d1 = reinterpret_cast<Rational*>(d2);
      return static_cast<double>(r1->get_n()) / static_cast<double>(r1->get_d()) / static_cast<double>(d1->get_n()) /
             static_cast<double>(d1->get_d());
    }
    return 0.0;
  }

  Rational operator++();           // Префиксный ++
  Rational operator++(const int);  // Постпрефиксный ++
  Rational operator--();           // Префиксный --
  Rational operator--(const int);  // Постпрефиксный --

  friend bool operator==(const int, Rational& rat);  // Оператор сравнения ==
  friend bool operator==(Rational& rat, const int);  // Оператор сравнения ==
  friend bool operator!=(const int, Rational& rat);  // Оператор сравнения !=
  friend bool operator!=(Rational& rat, const int);  // Оператор сравнения !=
  friend bool operator>(const int, Rational& rat);   // Оператор сравнения >
  friend bool operator>(Rational& rat, const int);   // Оператор сравнения >
  friend bool operator<(const int, Rational& rat);   // Оператор сравнения <
  friend bool operator<(Rational& rat, const int);   // Оператор сравнения <
  friend bool operator>=(const int, Rational& rat);  // Оператор сравнения >=
  friend bool operator>=(Rational& rat, const int);  // Оператор сравнения >=
  friend bool operator<=(const int, Rational& rat);  // Оператор сравнения <=
  friend bool operator<=(Rational& rat, const int);  // Оператор сравнения <=

  int get_n();      // Геттер для numeration_
  int get_d();      // Геттер для denumerator_
  double get_db();  // Геттер для db

  int gcd(int, int);  // НОД

private:
  int numerator_;
  int denumerator_;
  double db;
};

#endif  // RATIONAL_H

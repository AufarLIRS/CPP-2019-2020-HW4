#include "rational.h"

// Конструктор без параметров
Rational::Rational() : db(0.0), numerator_(0), denumerator_(1) {}

// Конструктор с двумя параметрами
Rational::Rational(int num, int den) {
  int nod = gcd(num, den);
  if (nod > 1) {
    numerator_ = num / nod;
    denumerator_ = den / nod;
  } else {
    numerator_ = num;
    denumerator_ = den;
  }
  db = static_cast<double>(num) / static_cast<double>(den);
}

// Оператор + для double
double operator+(const double db, Rational &rat) {
  double tmp;
  tmp =
      db + static_cast<double>(rat.get_n()) / static_cast<double>(rat.get_d());
  return tmp;
}

// Оператор + для double
double operator+(Rational &rat, const double db) {
  double tmp;
  tmp =
      static_cast<double>(rat.get_n()) / static_cast<double>(rat.get_d()) + db;
  return tmp;
}

// Оператор + для double
double operator+(Rational &rat1, Rational &rat2) {
  double tmp;
  tmp = static_cast<double>(rat1.get_n()) / static_cast<double>(rat1.get_d()) +
        static_cast<double>(rat2.get_n()) / static_cast<double>(rat2.get_d());
  return tmp;
}

// Оператор - для double
double operator-(const double db, Rational &rat) {
  double tmp;
  tmp =
      db - static_cast<double>(rat.get_n()) / static_cast<double>(rat.get_d());
  return tmp;
}

// Оператор - для double
double operator-(Rational &rat, const double db) {
  double tmp;
  tmp =
      static_cast<double>(rat.get_n()) / static_cast<double>(rat.get_d()) - db;
  return tmp;
}

// Оператор - для double
double operator-(Rational &rat1, Rational &rat2) {
  double tmp;
  tmp = static_cast<double>(rat1.get_n()) / static_cast<double>(rat1.get_d()) -
        static_cast<double>(rat2.get_n()) / static_cast<double>(rat2.get_d());
  return tmp;
}

// Оператор * для double
double operator*(const double db, Rational &rat) {
  double tmp;
  tmp =
      db * static_cast<double>(rat.get_n()) / static_cast<double>(rat.get_d());
  return tmp;
}

// Оператор * для double
double operator*(Rational &rat, const double db) {
  double tmp;
  tmp =
      static_cast<double>(rat.get_n()) / static_cast<double>(rat.get_d()) * db;
  return tmp;
}

// Оператор * для double
double operator*(Rational &rat1, Rational &rat2) {
  double tmp;
  tmp = static_cast<double>(rat1.get_n()) / static_cast<double>(rat1.get_d()) *
        static_cast<double>(rat2.get_n()) / static_cast<double>(rat2.get_d());
  return tmp;
}

// Оператор / для double
double operator/(const double db, Rational &rat) {
  double tmp;
  tmp =
      db / static_cast<double>(rat.get_n()) / static_cast<double>(rat.get_d());
  return tmp;
}

// Оператор / для double
double operator/(Rational &rat, const double db) {
  double tmp;
  tmp =
      static_cast<double>(rat.get_n()) / static_cast<double>(rat.get_d()) / db;
  return tmp;
}

// Оператор / для double
double operator/(Rational &rat1, Rational &rat2) {
  double tmp;
  tmp = static_cast<double>(rat1.get_n()) / static_cast<double>(rat1.get_d()) /
        static_cast<double>(rat2.get_n()) / static_cast<double>(rat1.get_d());
  return tmp;
}

// Префиксный ++
Rational Rational::operator++() {
  numerator_ += denumerator_;
  return *this;
}

// Постпрефиксный ++
Rational Rational::operator++(const int i) {
  Rational tmp = *this;
  numerator_ += denumerator_;
  return tmp;
}

// Префиксный --
Rational Rational::operator--() {
  numerator_ -= denumerator_;
  return *this;
}

// Постпрефиксный --
Rational Rational::operator--(const int i) {
  Rational tmp = *this;
  numerator_ -= denumerator_;
  return tmp;
}

// Операция сравнения ==
bool operator==(const int i, Rational &rat) {
  return (i == (rat.get_n() / rat.get_d()));
}

// Операция сравнения ==
bool operator==(Rational &rat, const int i) {
  return ((rat.get_n() / rat.get_d()) == i);
}

// Операция сравнения !=
bool operator!=(const int i, Rational &rat) {
  return !(i == (rat.get_n() / rat.get_d()));
}

// Операция сравнения !=
bool operator!=(Rational &rat, const int i) {
  return !((rat.get_n() / rat.get_d()) == i);
}

// Операция сравнения >
bool operator>(const int i, Rational &rat) {
  return (i > (rat.get_n() / rat.get_d()));
}

// Операция сравнения >
bool operator>(Rational &rat, const int i) {
  return ((rat.get_n() / rat.get_d()) > i);
}

// Операция сравнения <
bool operator<(const int i, Rational &rat) {
  return (i < (rat.get_n() / rat.get_d()));
}

// Операция сравнения <
bool operator<(Rational &rat, const int i) {
  return ((rat.get_n() / rat.get_d()) < i);
}

// Операция сравнения >=
bool operator>=(const int i, Rational &rat) {
  return (i >= (rat.get_n() / rat.get_d()));
}

// Операция сравнения >=
bool operator>=(Rational &rat, const int i) {
  return ((rat.get_n() / rat.get_d()) >= i);
}

// Операция сравнения <=
bool operator<=(const int i, Rational &rat) {
  return (i <= (rat.get_n() / rat.get_d()));
}

// Операция сравнения <=
bool operator<=(Rational &rat, const int i) {
  return ((rat.get_n() / rat.get_d()) <= i);
}

// Геттер для numeration_
int Rational::get_n() { return numerator_; }

// Геттер для denumerator_
int Rational::get_d() { return denumerator_; }

// Геттер для db
double Rational::get_db() { return db; };

// НОД у двух чисел
int Rational::gcd(int a, int b) {
  int nod = 1L;
  for (int i = a; i > 0; i--) {
    if (a % i == 0 && b % i == 0) {
      nod = i;
      break;
    }
  }
  return nod;
}

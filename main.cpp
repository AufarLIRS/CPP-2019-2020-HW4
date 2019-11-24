#include <iostream>
#include "matrix.h"
#include "rational.h"
#include <ctime>

using namespace std;

int main()
{
  srand((unsigned int)time(nullptr));

  int** matrix = create_matrix(4, 3);
  for (unsigned i = 0; i < 4; i++)
  {
    for (unsigned j = 0; j < 3; j++)
    {
      matrix[i][j] = rand() % 9 + 1;
    }
  }

  print_matrix(matrix, 4, 3);

  std::cout << endl;
  row_sum(matrix, 4, 3);
  std::cout << endl;

  int max = col_sum(matrix, 4, 3);
  std::cout << "Max column sum = " << max;
  std::cout << endl;
  std::cout << endl;

  Rational r1 = Rational(10, 5);  // == 2/1
  Rational::print(r1);
  std::cout << endl;
  std::cout << endl;

  Rational r2 = Rational(5, 3);
  Rational r3 = r1 + r2;  // 2/1 + 5/3 = 11/3
  std::cout << "2/1 + 5/3 = ";
  Rational::print(r3);
  std::cout << endl;
  std::cout << endl;

  Rational r4 = Rational(10, 1);
  Rational r5 = r4 - r3;  // 10/1 - 11/3 == 19/3
  std::cout << "10/1 - 11/3 = ";
  Rational::print(r5);
  std::cout << endl;
  std::cout << endl;

  Rational r6 = r2 * r3;  // 5/3 * 11 == 55/9
  std::cout << "5/3 * 11/3 = ";
  Rational::print(r6);
  std::cout << endl;
  std::cout << endl;

  std::cout << "Increment for r6: ";
  std::cout << endl;
  Rational::print(r6++);
  std::cout << endl;
  Rational::print(++r6);
  std::cout << endl;
  std::cout << endl;

  std::cout << "Decrement for r5: ";
  std::cout << endl;
  Rational::print(r5--);
  std::cout << endl;
  Rational::print(--r5);
  std::cout << endl;
  std::cout << endl;

  Rational r7 = Rational(5, 2);
  Rational r8 = Rational(7, 3);
  Rational r9 = Rational(25, 10);

  std::cout << endl;
  std::cout << "Warning! Danger TESTS +_+ ";
  std::cout << endl;
  std::cout << endl;

  std::cout << "r7 > r8 is ";
  if (r7 > r8)
    std::cout << "true!";
  else
    std::cout << "false..";
  std::cout << endl;

  std::cout << "r7 < r8 is ";
  if (r7 < r8)
    std::cout << "true!";
  else
    std::cout << "false..";
  std::cout << endl;

  std::cout << "r7 <= r9 is ";
  if (r7 <= r9)
    std::cout << "true!";
  else
    std::cout << "false..";
  std::cout << endl;

  std::cout << "r7 >= r9 is ";
  if (r7 >= r9)
    std::cout << "true!";
  else
    std::cout << "false..";
  std::cout << endl;

  std::cout << "r7 == r9 is ";
  if (r7 == r9)
    std::cout << "true!";
  else
    std::cout << "false..";
  std::cout << endl;

  std::cout << "r7 != r8 is ";
  if (r7 != r8)
    std::cout << "true!";
  else
    std::cout << "false..";
  std::cout << endl;
  std::cout << endl;

  std::cout << "Tests for rational and double:";
  std::cout << endl;
  Rational r10 = Rational(10, 3);
  double d1 = r10 + 5;
  double d2 = r10 - 3;
  double d3 = r10 * 3;
  double d4 = r10 / 2;
  std::cout << d1 << endl;
  std::cout << d2 << endl;
  std::cout << d3 << endl;
  std::cout << d4 << endl;
}

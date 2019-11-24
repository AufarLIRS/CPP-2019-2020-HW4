#include <iostream>
#include "Task_row_sum.h"
#include "Task_row_col.h"
#include "Task_Show_Martix.h"
#include "Rational.h"
using namespace std;

int main()
{
  int** m = new int*[5];
  m[0] = new int[5 * 4];
  for (size_t i = 1; i != 5; ++i)
    m[i] = m[i - 1] + 4;

  // Let's fulfill the arr
  for (unsigned i = 0; i < 5; i++)
    for (unsigned j = 0; j < 4; j++)
      m[i][j] = 1;

  show_matrix(m, 5, 4);
  row_sum(m, 5, 4);
  cout << "result: " << row_col(m, 5, 4) << std::endl;
  cout << endl;
  cout << endl;

  Rational x(5, 6);
  Rational y(3, 4);
  cout << "Summarising: " << endl;
  cout << x + y << endl;
  cout << endl;

  Rational q(5, 6);
  Rational w(5, 6);
  cout << "Comparing two equal nums: " << endl;
  cout << (q == w) << endl;
  cout << endl;

  Rational p(7, 6);
  Rational l(5, 2);
  cout << "Comparing two unequal nums: " << endl;
  cout << (p > l) << endl;
  cout << endl;

  Rational z(12, 6);
  Rational c(3, 3);
  cout << "Substracting: " << endl;
  cout << z - c << endl;
  cout << endl;

  double i = 0.6;
  Rational u(3, 3);
  cout << "Summarising Double and Rational: " << endl;
  cout << i + u << endl;
  cout << endl;

  double f = 4.6;
  Rational g(2, 3);
  cout << "Multiplying Double and Rational: " << endl;
  cout << f * g << endl;
  cout << endl;

  return 0;
}

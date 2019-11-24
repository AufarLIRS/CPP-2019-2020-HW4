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

  rational r1 = rational(10, 5);  // == 2/1
  rational::print(r1);
  std::cout << endl;
  std::cout << endl;

  rational r2 = rational(5, 3);
  rational r3 = r1 + r2;  // 2/1 + 5/3 = 11/3
  std::cout << "2/1 + 5/3 = ";
  rational::print(r3);
  std::cout << endl;
  std::cout << endl;

  rational r4 = rational(10, 1);
  rational r5 = r4 - r3;  // 10/1 - 11/3 == 19/3
  std::cout << "10/1 - 11/3 = ";
  rational::print(r5);
  std::cout << endl;
  std::cout << endl;

  rational r6 = r2 * r3;  // 5/3 * 11 == 55/9
  std::cout << "5/3 * 11/3 = ";
  rational::print(r6);
  std::cout << endl;
  std::cout << endl;

  std::cout << "Increment for r6: ";
  std::cout << endl;
  rational::print(r6++);
  std::cout << endl;
  rational::print(++r6);
  std::cout << endl;
  std::cout << endl;

  std::cout << "Decrement for r5: ";
  std::cout << endl;
  rational::print(r5--);
  std::cout << endl;
  rational::print(--r5);
  std::cout << endl;
  std::cout << endl;

  rational r7 = rational(5, 2);
  rational r8 = rational(7, 3);
  rational r9 = rational(25, 10);

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
}

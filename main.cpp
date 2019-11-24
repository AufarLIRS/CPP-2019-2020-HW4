#include "array_new.h"
#include "array_functions.h"
#include "rational.h"
#include <iostream>

using namespace std;

int main()
{
  int** array = create_array(5, 5);  // создание массива
  for (size_t i = 0; i < 5; i++)
  {
    for (size_t j = 0; j < 5; j++)
      cout << array[i][j] << ' ';
    cout << endl;
  }
  cout << endl;

  row_sum(array, 5, 5);  // Task1
  cout << endl;

  int max = col_sum(array, 5, 5);  // Task2
  cout << "Max sum per columns is: " << max;
  cout << endl;
  free_array(array);  // освобождение массива
  cout << endl;

  cout << (Rational(-3, 2) + 1.5 == 0.0) << endl;                        // 1
  cout << (Rational(25, 50) < 1) << endl;                                // 1
  cout << (Rational(8, 3) > 10) << endl;                                 // 0
  cout << (Rational(1, 3) + Rational(8, 9) == Rational(11, 9)) << endl;  // 1
  cout << (Rational(3, 5) * Rational(5, 2) == 1.5) << endl;              // 1
  cout << (Rational(3, 3) / Rational(6, 6) == 1.0) << endl;              // 1
  cout << (++Rational(1, 1)) << endl;                                    // 2
  cout << (--Rational(-5, -5)) << endl;                                  // 0
}

#include <iostream>
#include "SumFunc.h"
#include "2dArrFunc.h"
#include <cmath>
#include "rational.h"

using namespace std;

int main()
{
  int** m = create_array2d(3, 4);
  for (auto i = 0; i < 3; i++)
    for (auto j = 0; j < 4; j++)
    {
      m[i][j] = i + j * 2;
    }
  for (auto i = 0; i < 3; i++)
  {
    for (auto j = 0; j < 4; j++)
    {
      cout << m[i][j] << " ";
    }
    cout << endl;
  }
  auto maxcolsum = col_sum(m, 3, 4);
  cout << "maxsum = " << maxcolsum;

  free_array2d(m);

  cout << endl;
  auto rat = Rational(1, 4);
  auto sum = rat + Rational(1, 4);
  if (sum == Rational(1, 2))
    cout << "Check Paseed!!!" << endl;
  if (Rational(1, 2) > 0.1)
    cout << "Check Paseed!!!" << endl;
  if (Rational(1, 2) < 3)
    cout << "Check Paseed!!!" << endl;
  if (Rational(1, 2) + 1.5 == 2.0)
    cout << "Check Paseed!!!" << endl;
  cout << "That's enough";
  return 0;
}

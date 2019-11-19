#include "2dArrFunc.h"

int** create_array2d(int a, int b)
{
  int** m = new int*[a];
  m[0] = new int[a * b];
  for (int i = 1; i != a; ++i)
    m[i] = m[i - 1] + b;
  return m;
}

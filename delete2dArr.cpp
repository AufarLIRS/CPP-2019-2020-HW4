#include "2dArrFunc.h"

void free_array2d(int** m)
{
  delete[] m[0];
  delete[] m;
}

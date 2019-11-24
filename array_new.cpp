#include "array_new.h"

int** create_array(size_t a, size_t b)
{
  int** m = new int*[a];
  m[0] = new int[a * b];
  for (size_t i = 1; i < a; i++)
    m[i] = m[i - 1] + b;
  for (size_t i = 0; i < a; i++)
    for (size_t j = 0; j < b; j++)
      m[i][j] = i * 2 + j * 3;
  return m;
}

void free_array(int** m)
{
  delete[] m[0];
  delete[] m;
}

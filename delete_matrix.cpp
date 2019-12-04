#include "Task_Delete_Matrix.h"

void delete_matrix(int** m, unsigned rows, unsigned cols)
{
  for (unsigned i = 0; i != rows; ++i)
  {
    delete[] m[i];
  }
  delete[] m;
}

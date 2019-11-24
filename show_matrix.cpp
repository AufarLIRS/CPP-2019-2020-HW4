#include <iostream>
#include "Task_Show_Martix.h"

void show_matrix(int** m, unsigned rows, unsigned cols)
{
  for (unsigned i = 0; i < cols; i++)
  {
    for (unsigned j = 0; j < rows; j++)
      std::cout << m[i][j] << " ";
    std::cout << '\n';
  }
}

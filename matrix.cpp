#include "matrix.h"

void rowSum(int** m, unsigned rows, unsigned cols)
{
  for (unsigned i = 0; i < rows; i++)
  {
    int s = 0;
    for (unsigned j = 0; j < cols; j++)
    {
      s += m[i][j];
    }
    std::cout << "row sum №" << i + 1 << " = " << s;
    std::cout << '\n';
  }
}

int colsSum(int** m, unsigned rows, unsigned cols)
{
  int max = std::numeric_limits<int>::min();
  for (unsigned i = 0; i < cols; i++)
  {
    int s = 0;
    for (unsigned j = 0; j < rows; j++)
    {
      s += m[j][i];
    }
    if (s > max)
    {
      max = s;
    }
  }
  return max;
}

void printMatrix(int** m, unsigned rows, unsigned cols)
{
  for (unsigned i = 0; i < rows; i++)
  {
    for (unsigned j = 0; j < cols; j++)
    {
      std::cout << m[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

int** createMatrix(unsigned rows, unsigned cols)
{
  int** matrix = new int*[rows];
  for (unsigned i = 0; i != rows; ++i)
  {
    matrix[i] = new int[cols];
  }
  return matrix;
}

void deleteMatrix(int** m, unsigned rows, unsigned cols)
{
  for (unsigned i = 0; i != rows; ++i)
  {
    delete[] m[i];
  }
  delete[] m;
}

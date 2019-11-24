#include "matrix.h"

void row_sum(int** m, unsigned rows, unsigned cols)
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

int col_sum(int** m, unsigned rows, unsigned cols)
{
  int max = INT_MIN;
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

void print_matrix(int** m, unsigned rows, unsigned cols)
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

int** create_matrix(unsigned rows, unsigned cols)
{
  int** matrix = new int*[rows];
  for (unsigned i = 0; i != rows; ++i)
  {
    matrix[i] = new int[cols];
  }
  return matrix;
}

void delete_matrix(int** m, unsigned rows, unsigned cols)
{
  for (unsigned i = 0; i != rows; ++i)
  {
    delete[] m[i];
  }
  delete[] m;
}

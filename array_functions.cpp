#include "array_functions.h"

void row_sum(int** m, unsigned rows, unsigned cols)
{
  for (unsigned i = 0; i < rows; i++)
  {
    int sum = 0;
    for (unsigned j = 0; j < cols; j++)
      sum = sum + m[i][j];
    cout << i + 1 << " row's elements sum is: " << sum;
    cout << endl;
  }
}

int col_sum(int** m, unsigned rows, unsigned cols)
{
  int max = std::numeric_limits<int>::min();
  for (unsigned i = 0; i < cols; i++)
  {
    int sum = 0;
    for (unsigned j = 0; j < rows; j++)
      sum = sum + m[j][i];
    if (sum > max)
      max = sum;
  }
  return max;
}

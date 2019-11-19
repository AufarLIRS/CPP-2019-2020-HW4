#include "SumFunc.h"
#include <limits>

int col_sum(int** m, unsigned rows, unsigned cols)
{
  int maxsum = std::numeric_limits<int>::min();
  for (unsigned i = 0; i < cols; i++)
  {
    int sum = 0;
    for (unsigned j = 0; j < rows; j++)
    {
      sum += m[j][i];
    }
    if (sum > maxsum)
      maxsum = sum;
  }
  return maxsum;
}

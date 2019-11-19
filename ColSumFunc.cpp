#include "SumFunc.h"
#include <climits>

int col_sum(int** m, unsigned rows, unsigned cols)
{
  int maxsum = INT_MIN;
  for (unsigned i = 0; i < cols; i++)
  {
    int sum = 0;
    for (unsigned j = 0; j < rows; j++)
    {
      sum += m[j][i];
    }
    if (sum > maxsum)
      maxsum = sum;
    sum = 0;
  }
  return maxsum;
}

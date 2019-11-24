#include <iostream>
#include <bits/stdc++.h>
#include "Task_row_col.h"

int row_col(int** m, unsigned rows, unsigned cols)
{
  int maxSum = INT_MIN;
  int newSum = INT_MIN;
  for (unsigned j = 0; j < rows; j++)
  {
    for (unsigned i = 0; i < cols; i++)
    {
      newSum += m[i][j];
      if (newSum > maxSum)
      {
        maxSum = newSum;
      }
    }
    newSum = 0;
  }
  return maxSum;
}

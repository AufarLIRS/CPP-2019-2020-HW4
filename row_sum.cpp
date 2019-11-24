#include <iostream>
#include <bits/stdc++.h>
#include "Task_row_sum.h"

void row_sum(int** m, unsigned rows, unsigned cols)
{
  int rowSum = INT_MIN;
  for (unsigned i = 0; i < cols; i++)
    for (unsigned j = 0; j < rows; j++)
      rowSum += m[i][j];
  std::cout << "result: " << rowSum << '\n';
}

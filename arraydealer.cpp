#include "arraydealer.h"
#include <iostream>

using namespace std;

void row_sum(int** m, unsigned rows, unsigned cols)
{
  int* summ_array = new int[rows];

  for (unsigned i = 0; i < rows; i++)
    summ_array[i] = 0;

  for (unsigned i = 0; i < rows; i++)
    for (unsigned j = 0; j < cols; j++)
      summ_array[i] += m[i][j];

  for (unsigned i = 0; i < rows; i++)
    cout << summ_array[i] << endl;

  delete[] summ_array;
}

int col_sum(int** m, unsigned rows, unsigned cols)
{
  int max_val = 0, tmp_max_val = 0;

  for (int i = 0; i < cols; i++)
  {
    for (int j = 0; j < rows; j++)
    {
      if (i == 1)
        max_val += m[j][i];
      tmp_max_val += m[j][i];
    }
    if (max_val < tmp_max_val)
      max_val = tmp_max_val;
    tmp_max_val = 0;
  }
  return max_val;
}

#include <iostream>
#include "Task_row_sum.h"
#include "Task_row_col.h"
#include "Task_Show_Martix.h"
using namespace std;

int main()
{
  int** m = new int*[5];
  m[0] = new int[5 * 4];
  for (size_t i = 1; i != 5; ++i)
    m[i] = m[i - 1] + 4;

  // Let's fulfill the arr
  for (unsigned i = 0; i < 5; i++)
    for (unsigned j = 0; j < 4; j++)
      m[i][j] = 1;

  show_matrix(m, 5, 4);
  cout << '\n';
  row_sum(m, 5, 4);
  cout << '\n';
  cout << row_col(m, 5, 4) << '\n';

  return 0;
}

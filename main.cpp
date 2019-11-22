#include <iostream>

using namespace std;

void show_matrix(int** m, unsigned rows, unsigned cols)
{
  for (unsigned i = 0; i < cols; i++)
  {
    for (unsigned j = 0; j < rows; j++)
      cout << m[i][j] << " ";
    cout << '\n';
  }
}

void row_sum(int** m, unsigned rows, unsigned cols)
{
  int rowSum = 0;
  for (unsigned i = 0; i < cols; i++)
    for (unsigned j = 0; j < rows; j++)
      rowSum += m[i][j];
  std::cout << "result: " << rowSum << '\n';
}

int row_col(int** m, unsigned rows, unsigned cols)
{
  int maxSum = 0;
  int newSum = 0;
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
  row_sum(m, 5, 4);
  cout << row_col(m, 5, 4) << '\n';

  return 0;
}

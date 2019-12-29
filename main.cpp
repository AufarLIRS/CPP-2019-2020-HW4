#include "rational.h"
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

// ������� ��������� ������������ ������
// � ������� ������� �� �����
int** create_array(size_t rows, size_t cols)
{
  // ��������� ��������� ������ � ���� 10x10
  int** mas = new int*[rows];
  for (size_t i = 0; i < rows; i++)
    mas[i] = new int[cols];

  // ��������� ��������� ������ ���������� ���������� �� 0 �� 99
  srand(size_t(time(0)));
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
    {
      mas[i][j] = rand() % 100;
    }
  }

  // ������ �� �����
  cout << "\nSource array: \n";
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
    {
      cout << setw(4) << mas[i][j];
    }
    cout << endl;
  }

  return mas;
}

// �������� ���������� �������
void delete_array(int** mas, size_t rows)
{
  for (size_t i = 0; i < rows; i++)
    delete[] mas[i];
  delete[] mas;
}

// ������� ����� ���������� ������� ���������
// � ������� ���� �� �����
void rowSum(int** array, unsigned rows_count, unsigned cols_count)
{
  cout << "\nSum of rows: \n";
  for (size_t i = 0; i < rows_count; i++)
  {
    int sum = 0;
    for (size_t j = 0; j < cols_count; j++)
    {
      sum += array[i][j];
    }
    cout << sum << endl;
  }
}

// ������� ����� ���������� ������� ���������
// � ������� ���� �� �����
void colSum(int** array, unsigned rows_count, unsigned cols_count)
{
  cout << "\nSum of columns: \n";
  for (size_t i = 0; i < cols_count; i++)
  {
    int sum = 0;
    for (size_t j = 0; j < rows_count; j++)
    {
      sum += array[j][i];
    }
    cout << sum << endl;
  }
}

// �������� �������
int main()
{
  // Task 1
  // ������� ��������� ������������ ������ � �������� ��� �� �����
  int** mas = create_array(8, 10);

  // ������� ����� ������ ������ � ������� �� �����
  rowSum(mas, 8, 10);

  // ������� ������
  delete_array(mas, 8);

  // Task 2
  // ������� ��������� ������������ ������ � �������� ��� �� �����
  int** mas2 = create_array(5, 8);

  // ������� ����� ������� ������� � ������� �� �����
  colSum(mas2, 5, 8);

  // ������� ������
  delete_array(mas2, 5);

  // ��������� +
  Rational rat1(12, 24);
  double d1 = 0.347;
  double d2 = d1 + rat1;
  cout << "\nDouble = " << d1
       << "   Rational = " << static_cast<double>(rat1.get_n()) / static_cast<double>(rat1.get_d())
       << "   double+rat = " << d2 << endl;

  // ��������� -
  Rational rat2(24, 128);
  d1 = 0.467;
  d2 = d1 - rat2;
  cout << "Double = " << d1 << "   Rational = " << static_cast<double>(rat2.get_n()) / static_cast<double>(rat2.get_d())
       << "   double-rat = " << d2 << endl;

  // ��������� *
  Rational rat3(45, 128);
  d1 = 0.789;
  d2 = d1 * rat3;
  cout << "Double = " << d1 << "   Rational = " << static_cast<double>(rat3.get_n()) / static_cast<double>(rat3.get_d())
       << "   double*rat = " << d2 << endl;

  // ��������� /
  Rational rat4(21, 34);
  d1 = 0.123;
  d2 = d1 / rat4;
  cout << "Double = " << d1 << "   Rational = " << static_cast<double>(rat4.get_n()) / static_cast<double>(rat4.get_d())
       << "   double/rat = " << d2 << endl;

  // ��������� ==
  Rational rat5(1, 1);
  int i1 = 1;
  cout << "Int = " << i1 << "   Rational = (" << rat5.get_n() << "," << rat5.get_d() << ")  ";
  if (i1 == rat5)
    cout << "Int=Rational\n";
  else
    cout << "Int!=Rational\n";

  // ��������� !=
  Rational rat6(1, 1);
  i1 = 2;
  cout << "Int = " << i1 << "   Rational = (" << rat6.get_n() << "," << rat6.get_d() << ")  ";
  if (i1 == rat6)
    cout << "Int=Rational\n";
  else
    cout << "Int!=Rational\n";

  // ��������� >
  Rational rat7(3, 1);
  i1 = 5;
  cout << "Int = " << i1 << "   Rational = (" << rat7.get_n() << "," << rat7.get_d() << ")  ";
  if (i1 > rat7)
    cout << "Int>Rational\n";
  else
    cout << "Int<=Rational\n";

  // ��������� <
  Rational rat8(3, 1);
  i1 = 2;
  cout << "Int = " << i1 << "   Rational = (" << rat8.get_n() << "," << rat8.get_d() << ")  ";
  if (i1 < rat8)
    cout << "Int<Rational\n";
  else
    cout << "Int>=Rational\n";

  // ��������� <=
  Rational rat9(7, 2);
  i1 = 2;
  cout << "Int = " << i1 << "   Rational = (" << rat9.get_n() << "," << rat9.get_d() << ")  ";
  if (i1 <= rat9)
    cout << "Int<=Rational\n";
  else
    cout << "Int>Rational\n";

  // ��������� >=
  Rational rat10(7, 2);
  i1 = 12;
  cout << "Int = " << i1 << "   Rational = (" << rat10.get_n() << "," << rat10.get_d() << ")  ";
  if (i1 >= rat10)
    cout << "Int>=Rational\n";
  else
    cout << "Int<Rational\n";

  // ��������, ��� ����� �������, ����� �� �������������� ��� ����
  // �������������� ���������� ��������� ��� (������� � ����� Rational, ����� �
  // Rational � double, ����� � double � Rational.
  //
  // ��� ��������� ���� ������ �� ��������� ������� ���������������
  // � ��������� ������ ������������ � ������� �������, ��������:
  // template <class R, typename D>
  Rational rat11(45, 12);
  d1 = (rat11.get_db() + 12.34) + (rat11.get_db() - 6.21) + (rat11.get_db() * 1.01) + (rat11.get_db() / 2.12);
  cout << "Double= " << d1 << endl;

  return 0;
}

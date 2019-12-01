#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <limits>

void rowSum(int** m, unsigned rows, unsigned cols);
int colsSum(int** m, unsigned rows, unsigned cols);
void printMatrix(int** m, unsigned rows, unsigned cols);
int** createMatrix(unsigned rows, unsigned cols);
void deleteMatrix(int** m, unsigned rows, unsigned cols);

#endif  // MATRIX_H

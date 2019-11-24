#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

void row_sum(int** m, unsigned rows, unsigned cols);
int col_sum(int** m, unsigned rows, unsigned cols);
void print_matrix(int** m, unsigned rows, unsigned cols);
int** create_matrix(unsigned rows, unsigned cols);
void delete_matrix(int** m, unsigned rows, unsigned cols);

#endif  // MATRIX_H

#ifndef HELPERS_H
#define HELPERS_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_matrix.h"

#define EPS 1e-07

// Проверка матрицы
int check_correctness(matrix_t* A);

// Подматрица для вычисления минора элемента (row, col)
int get_submatrix(matrix_t* A, int row, int col, matrix_t* result);

#endif
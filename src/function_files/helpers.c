#include "helpers.h"

#include "../s21_matrix.h"

// Проверка матрицы
int check_correctness(matrix_t* A) {
  int code = OK;

  if (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0) {
    code = INCORRECT_MATRIX;
  }

  return code;
}

// Подматрица для вычисления минора элемента (row, col)
int get_submatrix(matrix_t* A, int row, int col, matrix_t* result) {
  int code = check_correctness(A);

  if (code == OK && (row < 0 || row > A->rows - 1 || col < 0 ||
                     col > A->columns - 1 || A->rows == 1 || A->columns == 1))
    code = INCORRECT_MATRIX;

  if (code == OK) code = s21_create_matrix(A->rows - 1, A->columns - 1, result);

  if (code == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (i != row && j != col) {
          result->matrix[i - (i > row)][j - (j > col)] = A->matrix[i][j];
        }
      }
    }
  }

  return code;
}
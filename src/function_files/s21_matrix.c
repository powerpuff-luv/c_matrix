#include "../s21_matrix.h"

#include "helpers.h"

/*
  0 - OK
  1 - INCORRECT_MATRIX
  2 - CALCULATION_ERROR

  0 - SUCCESS
  1 - FAILURE
*/

// Создание матриц
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int code = OK;

  if (rows > 0 && columns > 0 && result != NULL) {
    // s21_remove_matrix(result); // invalid free
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix != NULL) {
      for (int i = 0; i < rows && code == OK; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          code = INCORRECT_MATRIX;
          s21_remove_matrix(result);
        }
      }
    } else {
      result->rows = 0;
      result->columns = 0;
      code = INCORRECT_MATRIX;
    }
  } else {
    code = INCORRECT_MATRIX;
  }

  return code;
}

// Очистка матриц
void s21_remove_matrix(matrix_t *A) {
  if (A != NULL && A->matrix != NULL) {
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i] != NULL) {
        free(A->matrix[i]);
      }
    }
    free(A->matrix);
    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
  }
}

// Сравнение матриц
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int code = SUCCESS;

  if (check_correctness(A) == INCORRECT_MATRIX ||
      check_correctness(B) == INCORRECT_MATRIX || A->rows != B->rows ||
      A->columns != B->columns) {
    code = FAILURE;
  } else {
    for (int i = 0; i < A->rows && code != FAILURE; i++) {
      for (int j = 0; j < A->columns && code != FAILURE; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= EPS) code = FAILURE;
      }
    }
  }

  return code;
}

// Сложение матриц
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int code = OK;

  if (check_correctness(A) == INCORRECT_MATRIX ||
      check_correctness(B) == INCORRECT_MATRIX)
    code = INCORRECT_MATRIX;

  if (code == OK && (A->rows != B->rows || A->columns != B->columns))
    code = CALCULATION_ERROR;

  if (code == OK) code = s21_create_matrix(A->rows, A->columns, result);

  if (code == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }

  return code;
}

// Вычитание матриц
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int code = OK;

  if (check_correctness(A) == INCORRECT_MATRIX ||
      check_correctness(B) == INCORRECT_MATRIX)
    code = INCORRECT_MATRIX;

  if (code == OK && (A->rows != B->rows || A->columns != B->columns))
    code = CALCULATION_ERROR;

  if (code == OK) code = s21_create_matrix(A->rows, A->columns, result);

  if (code == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }

  return code;
}

// Умножение матрицы на число
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int code = check_correctness(A);

  if (code == OK) code = s21_create_matrix(A->rows, A->columns, result);

  if (code == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }

  return code;
}

// Умножение двух матриц
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int code = OK;

  if (check_correctness(A) == INCORRECT_MATRIX ||
      check_correctness(B) == INCORRECT_MATRIX)
    code = INCORRECT_MATRIX;

  if (code == OK && A->columns != B->rows) code = CALCULATION_ERROR;

  if (code == OK) code = s21_create_matrix(A->rows, B->columns, result);

  if (code == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        result->matrix[i][j] = 0.0;
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }

  return code;
}

// Транспонирование матрицы
int s21_transpose(matrix_t *A, matrix_t *result) {
  int code = check_correctness(A);

  if (code == OK) code = s21_create_matrix(A->columns, A->rows, result);

  if (code == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }

  return code;
}

// Матрица алгебраических дополнений
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int code = check_correctness(A);

  if (code == OK && (A->rows != A->columns)) code = CALCULATION_ERROR;

  if (code == OK) code = s21_create_matrix(A->rows, A->columns, result);

  if (code == OK) {
    if (A->rows == 1) {
      result->matrix[0][0] = A->matrix[0][0];
    } else {
      for (int i = 0; i < A->rows && code == OK; i++) {
        for (int j = 0; j < A->columns && code == OK; j++) {
          matrix_t submatrix = {0};
          double minor = 0.0;

          code = get_submatrix(A, i, j, &submatrix);
          if (code == OK) code = s21_determinant(&submatrix, &minor);
          if (code == OK) result->matrix[i][j] = minor * pow(-1, i + j);

          s21_remove_matrix(&submatrix);

          if (code != OK) s21_remove_matrix(result);
        }
      }
    }
  }

  return code;
}

// Определитель матрицы
int s21_determinant(matrix_t *A, double *result) {
  int code = check_correctness(A);

  if (code == OK && (A->rows != A->columns)) code = CALCULATION_ERROR;

  if (code == OK) {
    *result = 0.0;

    if (A->rows == 1)
      *result = A->matrix[0][0];
    else if (A->rows == 2)
      *result =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    else {
      for (int i = 0; i < A->columns && code == OK; i++) {
        matrix_t submatrix = {0};
        double minor = 0;

        code = get_submatrix(A, 0, i, &submatrix);
        if (code == OK) code = s21_determinant(&submatrix, &minor);
        if (code == OK) *result += A->matrix[0][i] * (pow(-1, i) * minor);

        s21_remove_matrix(&submatrix);
      }
    }
  }

  return code;
}

// Обратная матрица
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int code = check_correctness(A);

  double det = 0;
  if (code == OK) code = s21_determinant(A, &det);

  if (code == OK && fabs(det) < EPS) code = CALCULATION_ERROR;

  if (code == OK) {
    matrix_t compl = {0}, compl_transp = {0};

    code = s21_calc_complements(A, &compl );
    if (code == OK) code = s21_transpose(&compl, &compl_transp);
    if (code == OK) code = s21_mult_number(&compl_transp, 1 / det, result);

    s21_remove_matrix(&compl );
    s21_remove_matrix(&compl_transp);
  }

  return code;
}
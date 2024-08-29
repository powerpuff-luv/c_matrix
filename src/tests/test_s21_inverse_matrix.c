#include "tests.h"

START_TEST(test_s21_inverse_matrix_1) {
  matrix_t res = {0};
  matrix_t A = {0};

  int code = s21_create_matrix(2, 2, &A);
  ck_assert_int_eq(code, OK);

  A.matrix[0][0] = 6;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 4;

  code = s21_inverse_matrix(&A, &res);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}

START_TEST(test_s21_inverse_matrix_2) {
  matrix_t res = {0};
  matrix_t A = {0};

  s21_create_matrix(4, 2, &A);
  ck_assert_int_eq(s21_inverse_matrix(&A, &res), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}

START_TEST(test_s21_inverse_matrix_3) {
  matrix_t res = {0};
  matrix_t A = {0};

  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = -5;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 6;
  A.matrix[1][2] = 7;
  A.matrix[1][3] = 7;
  A.matrix[2][0] = 9;
  A.matrix[2][1] = 10;
  A.matrix[2][2] = -2;
  A.matrix[2][3] = 12;
  A.matrix[3][0] = 13;
  A.matrix[3][1] = 14;
  A.matrix[3][2] = 8;
  A.matrix[3][3] = 17;
  ck_assert_int_eq(s21_inverse_matrix(&A, &res), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}

START_TEST(test_s21_inverse_matrix_4) {
  matrix_t res = {0};
  matrix_t A = {0};

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = -1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = -3;
  A.matrix[1][1] = 4;
  ck_assert_int_eq(s21_inverse_matrix(&A, &res), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}

START_TEST(test_s21_inverse_matrix_5) {
  matrix_t res = {0};
  matrix_t A = {0};

  s21_create_matrix(2, 2, &A);
  ck_assert_int_eq(s21_inverse_matrix(NULL, &res), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}

Suite *s21_inverse_matrix_suite() {
  Suite *s = suite_create("s21_inverse_matrix_suite");
  TCase *core = tcase_create("s21_inverse_matrix_tcase");

  tcase_add_test(core, test_s21_inverse_matrix_1);
  tcase_add_test(core, test_s21_inverse_matrix_2);
  tcase_add_test(core, test_s21_inverse_matrix_3);
  tcase_add_test(core, test_s21_inverse_matrix_4);
  tcase_add_test(core, test_s21_inverse_matrix_5);

  suite_add_tcase(s, core);

  return s;
}
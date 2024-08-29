#include "tests.h"

START_TEST(test_s21_determinant_1) {
  double res = 0;
  matrix_t A = {0};

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = -2;
  A.matrix[1][0] = 9;
  A.matrix[1][1] = 4;
  ck_assert_int_eq(s21_determinant(&A, &res), OK);
  ck_assert_double_eq(res, 22);
  s21_remove_matrix(&A);
}

START_TEST(test_s21_determinant_2) {
  double res = 0;
  matrix_t A = {0};

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  ck_assert_int_eq(s21_determinant(&A, &res), OK);
  ck_assert_double_eq(res, -2);
  s21_remove_matrix(&A);
}

START_TEST(test_s21_determinant_3) {
  double res = 0;
  matrix_t A = {0};

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  ck_assert_int_eq(s21_determinant(&A, &res), OK);
  ck_assert_double_eq(res, 0);
  s21_remove_matrix(&A);
}

START_TEST(test_s21_determinant_4) {
  double res = 0;
  matrix_t A = {0};

  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 4;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 6;
  A.matrix[1][2] = 7;
  A.matrix[1][3] = 8;
  A.matrix[2][0] = 9;
  A.matrix[2][1] = 10;
  A.matrix[2][2] = 11;
  A.matrix[2][3] = 12;
  A.matrix[3][0] = 13;
  A.matrix[3][1] = 14;
  A.matrix[3][2] = 15;
  A.matrix[3][3] = 16;
  ck_assert_int_eq(s21_determinant(&A, &res), OK);
  ck_assert_double_eq(res, 0);
  s21_remove_matrix(&A);
}

START_TEST(test_s21_determinant_5) {
  double res = 0;
  matrix_t A = {0};

  s21_create_matrix(2, 2, &A);
  ck_assert_int_eq(s21_determinant(NULL, &res), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}

Suite *s21_determinant_suite() {
  Suite *s = suite_create("s21_determinant_suite");
  TCase *core = tcase_create("s21_determinant_tcase");

  tcase_add_test(core, test_s21_determinant_1);
  tcase_add_test(core, test_s21_determinant_2);
  tcase_add_test(core, test_s21_determinant_3);
  tcase_add_test(core, test_s21_determinant_4);
  tcase_add_test(core, test_s21_determinant_5);

  suite_add_tcase(s, core);

  return s;
}
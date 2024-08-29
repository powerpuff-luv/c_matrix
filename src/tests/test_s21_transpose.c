#include "tests.h"

START_TEST(test_s21_transpose_1) {
  matrix_t res = {0};
  matrix_t A = {0};

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 5;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 6;
  ck_assert_int_eq(s21_transpose(&A, &res), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}

START_TEST(test_s21_transpose_2) {
  matrix_t res = {0};
  matrix_t A = {0};

  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 5;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 6;
  A.matrix[2][0] = 6;
  A.matrix[2][1] = 6;
  ck_assert_int_eq(s21_transpose(&A, &res), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}

START_TEST(test_s21_transpose_3) {
  matrix_t res = {0};
  matrix_t A = {0};

  s21_create_matrix(2, 3, &A);
  A.matrix[0][0] = 5;
  A.matrix[0][1] = 1;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 6;
  A.matrix[1][2] = 6;
  ck_assert_int_eq(s21_transpose(&A, &res), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}

START_TEST(test_s21_transpose_4) {
  matrix_t res = {0};
  matrix_t A = {0};

  s21_create_matrix(0, 0, &A);
  ck_assert_int_eq(s21_transpose(&A, &res), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}

START_TEST(test_s21_transpose_5) {
  matrix_t res = {0};
  matrix_t A = {0};

  s21_create_matrix(2, 2, &A);
  ck_assert_int_eq(s21_transpose(NULL, &res), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}

Suite *s21_transpose_suite() {
  Suite *s = suite_create("s21_transpose_suite");
  TCase *core = tcase_create("s21_transpose_tcase");

  tcase_add_test(core, test_s21_transpose_1);
  tcase_add_test(core, test_s21_transpose_2);
  tcase_add_test(core, test_s21_transpose_3);
  tcase_add_test(core, test_s21_transpose_4);
  tcase_add_test(core, test_s21_transpose_5);

  suite_add_tcase(s, core);

  return s;
}
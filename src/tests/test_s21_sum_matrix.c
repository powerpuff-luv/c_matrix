#include "tests.h"

START_TEST(test_s21_sum_matrix_1) {
  matrix_t res = {0};
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(6, 6, &A);
  s21_create_matrix(6, 6, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &res), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}

START_TEST(test_s21_sum_matrix_2) {
  matrix_t res = {0};
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(70, 6, &A);
  s21_create_matrix(70, 6, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &res), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}

START_TEST(test_s21_sum_matrix_3) {
  matrix_t res = {0};
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(6, 68, &A);
  s21_create_matrix(6, 68, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &res), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}

START_TEST(test_s21_sum_matrix_4) {
  matrix_t res = {0};
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(68, 6, &A);
  s21_create_matrix(6, 69, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &res), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}

START_TEST(test_s21_sum_matrix_5) {
  matrix_t res = {0};
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(6, 69, &A);
  s21_create_matrix(0, 69, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &res), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}

Suite *s21_sum_matrix_suite() {
  Suite *s = suite_create("s21_sum_matrix_suite");
  TCase *core = tcase_create("s21_sum_matrix_tcase");

  tcase_add_test(core, test_s21_sum_matrix_1);
  tcase_add_test(core, test_s21_sum_matrix_2);
  tcase_add_test(core, test_s21_sum_matrix_3);
  tcase_add_test(core, test_s21_sum_matrix_4);
  tcase_add_test(core, test_s21_sum_matrix_5);

  suite_add_tcase(s, core);

  return s;
}
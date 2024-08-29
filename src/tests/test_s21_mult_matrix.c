#include "tests.h"

START_TEST(test_s21_mult_matrix_1) {
  matrix_t res = {0};
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(6, 6, &A);
  s21_create_matrix(6, 6, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &res), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}

START_TEST(test_s21_mult_matrix_2) {
  matrix_t res = {0};
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &res), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}

START_TEST(test_s21_mult_matrix_3) {
  matrix_t res = {0};
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(6, 6, &A);
  s21_create_matrix(6, 6, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &res), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}

START_TEST(test_s21_mult_matrix_4) {
  matrix_t res = {0};
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(6, 69, &A);
  s21_create_matrix(6, 6, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &res), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}

START_TEST(test_s21_mult_matrix_5) {
  matrix_t res = {0};
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(0, 0, &A);
  s21_create_matrix(0, 0, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &res), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}

Suite *s21_mult_matrix_suite() {
  Suite *s = suite_create("s21_mult_matrix_suite");
  TCase *core = tcase_create("s21_mult_matrix_tcase");

  tcase_add_test(core, test_s21_mult_matrix_1);
  tcase_add_test(core, test_s21_mult_matrix_2);
  tcase_add_test(core, test_s21_mult_matrix_3);
  tcase_add_test(core, test_s21_mult_matrix_4);
  tcase_add_test(core, test_s21_mult_matrix_5);

  suite_add_tcase(s, core);

  return s;
}
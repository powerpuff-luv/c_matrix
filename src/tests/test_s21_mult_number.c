#include "tests.h"

START_TEST(test_s21_mult_number_1) {
  matrix_t res = {0};
  matrix_t A = {0};

  s21_create_matrix(6, 6, &A);
  ck_assert_int_eq(s21_mult_number(&A, 7, &res), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}

START_TEST(test_s21_mult_number_2) {
  matrix_t res = {0};
  matrix_t A = {0};

  s21_create_matrix(7, 8, &A);
  ck_assert_int_eq(s21_mult_number(&A, 70, &res), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}

START_TEST(test_s21_mult_number_3) {
  matrix_t res = {0};
  matrix_t A = {0};

  s21_create_matrix(60, 69, &A);
  ck_assert_int_eq(s21_mult_number(&A, 7, &res), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}

START_TEST(test_s21_mult_number_4) {
  matrix_t res = {0};
  matrix_t A = {0};

  s21_create_matrix(0, 0, &A);
  ck_assert_int_eq(s21_mult_number(&A, 7, &res), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}

START_TEST(test_s21_mult_number_5) {
  matrix_t res = {0};
  matrix_t A = {0};

  s21_create_matrix(0, 6, &A);
  ck_assert_int_eq(s21_mult_number(&A, 9, &res), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}

Suite *s21_mult_number_suite() {
  Suite *s = suite_create("s21_mult_number_suite");
  TCase *core = tcase_create("s21_mult_number_tcase");

  tcase_add_test(core, test_s21_mult_number_1);
  tcase_add_test(core, test_s21_mult_number_2);
  tcase_add_test(core, test_s21_mult_number_3);
  tcase_add_test(core, test_s21_mult_number_4);
  tcase_add_test(core, test_s21_mult_number_5);

  suite_add_tcase(s, core);

  return s;
}
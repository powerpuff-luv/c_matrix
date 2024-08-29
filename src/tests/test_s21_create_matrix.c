#include "tests.h"

START_TEST(test_s21_create_matrix_1) {
  matrix_t A = {0};
  ck_assert_int_eq(s21_create_matrix(6, 6, &A), OK);
  s21_remove_matrix(&A);
}

START_TEST(test_s21_create_matrix_2) {
  matrix_t A = {0};
  ck_assert_int_eq(s21_create_matrix(8, 7, &A), OK);
  s21_remove_matrix(&A);
}

START_TEST(test_s21_create_matrix_3) {
  matrix_t A = {0};
  ck_assert_int_eq(s21_create_matrix(8, 8, &A), OK);
  s21_remove_matrix(&A);
}

START_TEST(test_s21_create_matrix_4) {
  matrix_t A = {0};
  ck_assert_int_eq(s21_create_matrix(6, 10, &A), OK);
  s21_remove_matrix(&A);
}

START_TEST(test_s21_create_matrix_5) {
  matrix_t A = {0};
  ck_assert_int_eq(s21_create_matrix(0, 0, &A), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}

Suite *s21_create_matrix_suite() {
  Suite *s = suite_create("s21_create_matrix_suite");
  TCase *core = tcase_create("s21_create_matrix_tcase");

  tcase_add_test(core, test_s21_create_matrix_1);
  tcase_add_test(core, test_s21_create_matrix_2);
  tcase_add_test(core, test_s21_create_matrix_3);
  tcase_add_test(core, test_s21_create_matrix_4);
  tcase_add_test(core, test_s21_create_matrix_5);

  suite_add_tcase(s, core);

  return s;
}
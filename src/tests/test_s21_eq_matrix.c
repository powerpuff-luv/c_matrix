#include "tests.h"

START_TEST(test_s21_eq_matrix_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.0000000;
  A.matrix[0][1] = 2.0000000;
  A.matrix[1][0] = 3.0000000;
  A.matrix[1][1] = 4.0000000;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1.0000000;
  B.matrix[0][1] = 2.0000000;
  B.matrix[1][0] = 3.0000000;
  B.matrix[1][1] = 4.0000000;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(test_s21_eq_matrix_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.0000070;
  A.matrix[0][1] = 2.0000000;
  A.matrix[1][0] = 3.0000006;
  A.matrix[1][1] = 4.0000000;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1.0000000;
  B.matrix[0][1] = 5.0000000;
  B.matrix[1][0] = 3.0000009;
  B.matrix[1][1] = 4.0000000;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(test_s21_eq_matrix_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.0000007;
  A.matrix[0][1] = 2.0000000;
  A.matrix[1][0] = 3.0000006;
  A.matrix[1][1] = 4.0000000;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1.0000000;
  B.matrix[0][1] = 2.0000001;
  B.matrix[1][0] = 7.0000009;
  B.matrix[1][1] = 4.0000000;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(test_s21_eq_matrix_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(12, 78, &A);
  s21_create_matrix(99, 6, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(test_s21_eq_matrix_5) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(64, 66, &A);
  s21_create_matrix(69, 6, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

Suite *s21_eq_matrix_suite() {
  Suite *s = suite_create("s21_eq_matrix_suite");
  TCase *core = tcase_create("s21_eq_matrix_tcase");

  tcase_add_test(core, test_s21_eq_matrix_1);
  tcase_add_test(core, test_s21_eq_matrix_2);
  tcase_add_test(core, test_s21_eq_matrix_3);
  tcase_add_test(core, test_s21_eq_matrix_4);
  tcase_add_test(core, test_s21_eq_matrix_5);

  suite_add_tcase(s, core);

  return s;
}
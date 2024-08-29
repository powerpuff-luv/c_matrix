#include "tests.h"

int main(void) {
  int failed = 0;
  Suite *all_cases[] = {s21_create_matrix_suite(),
                        s21_eq_matrix_suite(),
                        s21_sum_matrix_suite(),
                        s21_sub_matrix_suite(),
                        s21_mult_number_suite(),
                        s21_mult_matrix_suite(),
                        s21_transpose_suite(),
                        s21_calc_complements_suite(),
                        s21_determinant_suite(),
                        s21_inverse_matrix_suite(),
                        NULL};

  for (Suite **curr_suite = all_cases; *curr_suite != NULL; curr_suite++) {
    printf("\n");
    SRunner *sr = srunner_create(*curr_suite);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed = srunner_ntests_failed(sr) || failed;
    srunner_free(sr);
  }

  printf("\n");

  return failed;
}

#include "../test.hpp"

TEST(Determinant, Subtest_1) {
  S21Matrix mat(2, 2);

  ASSERT_EQ(mat.Determinant(), 0);
}

TEST(Determinant, Subtest_2) {
  S21Matrix mat(2, 2);
  mat(0, 0) = 1;
  mat(1, 1) = 10;

  mat(1, 0) = 1;
  mat(0, 1) = 8;

  ASSERT_EQ(mat.Determinant(), 2);
}

TEST(Determinant, Subtest_3) {
  int ROWS = 2, COLS = 2;
  S21Matrix mat(ROWS, COLS);

  mat(0, 0) = 5;
  mat(1, 1) = 10;

  mat(1, 0) = 3;
  mat(0, 1) = 7;
  ASSERT_EQ(mat.Determinant(), 29);
}

TEST(Determinant, Subtest_4) {
  int ROWS = 3, COLS = 3;
  S21Matrix mat(ROWS, COLS);
  mat(0, 0) = 10;
  mat(0, 1) = 2;
  mat(0, 2) = 4;

  mat(1, 0) = 16;
  mat(1, 1) = 25;
  mat(1, 2) = 36;

  mat(2, 0) = 64;
  mat(2, 1) = 81;
  mat(2, 2) = 100;

  ASSERT_EQ(mat.Determinant(), -3968);
}

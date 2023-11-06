#include "../test.hpp"

TEST(CopyMatrix, Subtest_1) {
  int ROWS = 3, COLS = 3;
  S21Matrix m1(ROWS, COLS);

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) m1(i, j) = 4.4;
  }

  S21Matrix m2(m1);

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      ASSERT_EQ(m2(i, j), 4.4);
    }
  }
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      ASSERT_EQ(m1(i, j), 4.4);
    }
  }
}

TEST(CopyMatrix, Subtest_2) {
  int ROWS = 3, COLS = 3;
  S21Matrix m1(ROWS, COLS);

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) m1(i, j) = i * j + 0.5;
  }

  S21Matrix m2(m1);

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      ASSERT_EQ(m2(i, j), i * j + 0.5);
    }
  }
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      ASSERT_EQ(m1(i, j), i * j + 0.5);
    }
  }
}

TEST(CopyMatrix, Subtest_3) {
  int ROWS = 1, COLS = 1;
  S21Matrix m1(ROWS, COLS);

  m1(0, 0) = -23;

  S21Matrix m2(m1);

  ASSERT_EQ(m2(0, 0), -23);
  ASSERT_EQ(m1(0, 0), -23);
}

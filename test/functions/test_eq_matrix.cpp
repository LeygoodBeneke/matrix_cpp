#include "../test.hpp"

TEST(EqMatrix, Subtest_1) {
  int ROWS = 3, COLS = 3;
  S21Matrix m1(ROWS, COLS), m2(ROWS, COLS);

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      m1(i, j) = 2;
      m2(i, j) = 3;
    }
  }
  ASSERT_FALSE(m1.EqMatrix(m2));
}

TEST(EqMatrix, Subtest_2) {
  int ROWS = 3, COLS = 3;
  S21Matrix m1(ROWS, COLS), m2(ROWS, COLS);

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      m1(i, j) = 3;
      m2(i, j) = 3;
    }
  }
  ASSERT_TRUE(m1.EqMatrix(m2));
}

TEST(EqMatrix, Subtest_3) {
  S21Matrix m1, m2;
  ASSERT_TRUE(m1.EqMatrix(m2));
}

TEST(EqMatrix, Subtest_4) {
  S21Matrix m1(2, 4), m2;
  ASSERT_FALSE(m1.EqMatrix(m2));
}

TEST(EqMatrix, Subtest_5) {
  int ROWS = 3, COLS = 3;
  S21Matrix m1, m2(ROWS, COLS);

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      m2(i, j) = 3;
    }
  }
  m1 = m2;

  ASSERT_TRUE(m1.EqMatrix(m2));
  ASSERT_TRUE(m1 == m2);
}

TEST(EqMatrix, Subtest_6) {
  S21Matrix m1, m2;
  ASSERT_TRUE(m1 == m2);
}

TEST(EqMatrix, Subtest_7) {
  S21Matrix m1(2, 4), m2;
  ASSERT_FALSE(m1 == m2);
}

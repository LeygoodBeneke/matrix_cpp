#include "../test.hpp"

TEST(Setters, Subtest_1) {
  int ROWS = 3, COLS = 3;
  S21Matrix m1(ROWS, COLS);

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      m1(i, j) = 2;
    }
  }

  m1.SetCols(5);
  m1.SetRows(5);

  ASSERT_EQ(m1.GetRows(), 5);
  ASSERT_EQ(m1.GetCols(), 5);
}

TEST(Setters, Subtest_2) {
  int ROWS = 3, COLS = 3;
  S21Matrix m1(ROWS, COLS);

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      m1(i, j) = 2;
    }
  }

  m1.SetCols(5);
  m1.SetRows(5);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (i < ROWS && j < COLS) {
        ASSERT_EQ(m1(i, j), 2);
      } else {
        ASSERT_EQ(m1(i, j), 0);
      }
    }
  }
}

TEST(Setters, Subtest_3) {
  int ROWS = 5, COLS = 5;
  S21Matrix m1(ROWS, COLS);

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      m1(i, j) = i + j;
    }
  }

  m1.SetCols(3);
  m1.SetRows(3);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ASSERT_EQ(m1(i, j), i + j);
    }
  }
}

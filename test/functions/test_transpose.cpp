#include "../test.hpp"

TEST(Transpose, Subtest_1) {
  int ROWS = 5, COLS = 5;
  S21Matrix mat1(ROWS, COLS), mat2(COLS, ROWS);

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      mat1(i, j) = std::rand() % 255;
      mat2(j, i) = mat1(i, j);
    }
  }

  S21Matrix mat3 = mat2.Transpose();

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      ASSERT_EQ(mat1(i, j), mat3(i, j));
    }
  }
}

TEST(Transpose, Subtest_2) {
  int ROWS = 1, COLS = 1;
  S21Matrix mat1(ROWS, COLS), mat2(COLS, ROWS);

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      mat1(i, j) = std::rand() % 255;
      mat2(j, i) = mat1(i, j);
    }
  }

  S21Matrix mat3 = mat2.Transpose();

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      ASSERT_EQ(mat1(i, j), mat3(i, j));
    }
  }
}

TEST(Transpose, Subtest_3) {
  int ROWS = 20, COLS = 50;
  S21Matrix mat1(ROWS, COLS), mat2(COLS, ROWS);

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      mat1(i, j) = std::rand() % 255;
      mat2(j, i) = mat1(i, j);
    }
  }

  S21Matrix mat3 = mat2.Transpose();

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      ASSERT_EQ(mat1(i, j), mat3(i, j));
    }
  }
}

TEST(Transpose, Subtest_4) {
  int ROWS = 50, COLS = 20;
  S21Matrix mat1(ROWS, COLS), mat2(COLS, ROWS);

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      mat1(i, j) = std::rand() % 255;
      mat2(j, i) = mat1(i, j);
    }
  }

  S21Matrix mat3 = mat2.Transpose();

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      ASSERT_EQ(mat1(i, j), mat3(i, j));
    }
  }
}

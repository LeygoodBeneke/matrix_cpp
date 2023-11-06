#include "../test.hpp"

TEST(SumMatrix, Subtest_1) {
  int ROWS = 10, COLS = 10;
  S21Matrix mat1(ROWS, COLS), mat2(ROWS, COLS), res(ROWS, COLS);

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      mat1(i, j) = std::rand() % 255;
      mat2(i, j) = std::rand() % 255;
    }
  }

  res = mat1;
  res.SumMatrix(mat2);

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      ASSERT_EQ(res(i, j), mat1(i, j) + mat2(i, j));
    }
  }
}

TEST(SumMatrix, Subtest_2) {
  int ROWS = 100, COLS = 100;
  S21Matrix mat1(ROWS, COLS), mat2(ROWS, COLS), res(ROWS, COLS);

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      mat1(i, j) = std::rand() % 255;
      mat2(i, j) = std::rand() % 255;
    }
  }

  res = mat1;
  res.SumMatrix(mat2);

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      ASSERT_EQ(res(i, j), mat1(i, j) + mat2(i, j));
    }
  }
}

TEST(SumMatrix, Subtest_3) {
  int ROWS = 1, COLS = 1000;
  S21Matrix mat1(ROWS, COLS), mat2(ROWS, COLS), res(ROWS, COLS);

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      mat1(i, j) = std::rand() % 255;
      mat2(i, j) = std::rand() % 255;
    }
  }

  res = mat1;
  res.SumMatrix(mat2);

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      ASSERT_EQ(res(i, j), mat1(i, j) + mat2(i, j));
    }
  }
}

TEST(SumMatrix, Subtest_4) {
  int ROWS = 1, COLS = 1000;
  S21Matrix mat1(ROWS, COLS), mat2(ROWS, COLS), res;

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      mat1(i, j) = std::rand() % 255;
      mat2(i, j) = std::rand() % 255;
    }
  }

  res = mat1 + mat2;

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      ASSERT_EQ(res(i, j), mat1(i, j) + mat2(i, j));
    }
  }
}

TEST(SumMatrix, Subtest_5) {
  int ROWS = 1, COLS = 1000;
  S21Matrix mat1(ROWS, COLS), mat2(ROWS, COLS), res(ROWS, COLS);

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      mat1(i, j) = std::rand() % 255;
      mat2(i, j) = std::rand() % 255;
    }
  }

  res = mat1;
  res += mat2;

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      ASSERT_EQ(res(i, j), mat1(i, j) + mat2(i, j));
    }
  }
}

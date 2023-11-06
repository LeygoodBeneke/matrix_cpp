#include "../test.hpp"

TEST(MulNumber, Subtest_1) {
  S21Matrix mat(2, 2);
  mat(0, 0) = 1;
  mat(1, 1) = 10;
  mat(1, 0) = 1;
  mat(0, 1) = 8;

  S21Matrix mat2;
  mat2 = mat;

  mat.MulNumber(2.5);

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) ASSERT_EQ(mat(i, j), mat2(i, j) * 2.5);
}

TEST(MulNumber, Subtest_2) {
  S21Matrix mat(2, 2);
  mat(0, 0) = 1;
  mat(1, 1) = 10;
  mat(1, 0) = 1;
  mat(0, 1) = 8;

  S21Matrix mat2;
  mat2 = mat;

  mat.MulNumber(-2.5);

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) ASSERT_EQ(mat(i, j), mat2(i, j) * -2.5);
}

TEST(MulNumber, Subtest_3) {
  S21Matrix mat(2, 2);
  mat(0, 0) = 1;
  mat(1, 1) = 10;
  mat(1, 0) = 1;
  mat(0, 1) = 8;

  S21Matrix mat2;
  mat2 = mat;

  mat.MulNumber(0);

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) ASSERT_EQ(mat(i, j), 0);
}

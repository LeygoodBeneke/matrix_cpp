#include "../test.hpp"

TEST(Inverse, Subtest_1) {
  S21Matrix mat(3, 3);

  mat(0, 0) = 23;
  mat(0, 1) = 12;
  mat(0, 2) = 4;

  mat(1, 0) = 3;
  mat(1, 1) = 20;
  mat(1, 2) = 10;

  mat(2, 0) = 5;
  mat(2, 1) = 12;
  mat(2, 2) = 6;

  S21Matrix mat1(mat.InverseMatrix());

  ASSERT_EQ(mat1(0, 0), 0);
  ASSERT_EQ(mat1(0, 1), -0.1875);
  ASSERT_EQ(mat1(0, 2), 0.3125);
  ASSERT_EQ(mat1(1, 0), 0.25);
  ASSERT_EQ(mat1(1, 1), 0.921875);
  ASSERT_EQ(mat1(1, 2), -1.703125);
  ASSERT_EQ(mat1(2, 0), -0.5);
  ASSERT_EQ(mat1(2, 1), -1.6875);
  ASSERT_EQ(mat1(2, 2), 3.3125);
}

TEST(Inverse, Subtest_2) {
  S21Matrix mat(2, 2);

  mat(0, 0) = 1;
  mat(0, 1) = 2;

  mat(1, 0) = 3;
  mat(1, 1) = 4;

  S21Matrix mat1 = mat.InverseMatrix();

  ASSERT_EQ(mat1(0, 0), -2);
  ASSERT_EQ(mat1(0, 1), 1);
  ASSERT_EQ(mat1(1, 0), 1.5);
  ASSERT_EQ(mat1(1, 1), -0.5);
}

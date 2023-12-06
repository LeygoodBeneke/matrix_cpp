#include "../test.hpp"

TEST(MulMatrix, Subtest_1) {
  S21Matrix mat1(3, 3), mat2(3, 3);

  mat1(0, 0) = 23;
  mat1(0, 1) = 152;
  mat1(0, 2) = 4;

  mat1(1, 0) = 3;
  mat1(1, 1) = 2;
  mat1(1, 2) = 10;

  mat1(2, 0) = 5;
  mat1(2, 1) = 12;
  mat1(2, 2) = 6;

  mat2(0, 0) = 23;
  mat2(0, 1) = 152;
  mat2(0, 2) = 4;

  mat2(1, 0) = 3;
  mat2(1, 1) = 2;
  mat2(1, 2) = 10;

  mat2(2, 0) = 5;
  mat2(2, 1) = 12;
  mat2(2, 2) = 6;

  mat1.MulMatrix(mat2);

  ASSERT_EQ(mat1(0, 0), 1005);
  ASSERT_EQ(mat1(0, 1), 3848);
  ASSERT_EQ(mat1(0, 2), 1636);
  ASSERT_EQ(mat1(1, 0), 125);
  ASSERT_EQ(mat1(1, 1), 580);
  ASSERT_EQ(mat1(1, 2), 92);
  ASSERT_EQ(mat1(2, 0), 181);
  ASSERT_EQ(mat1(2, 1), 856);
  ASSERT_EQ(mat1(2, 2), 176);
}

TEST(MulMatrix, Subtest_2) {
  S21Matrix mat1(3, 3), mat2(3, 3);

  mat1(0, 0) = 23;
  mat1(0, 1) = 152;
  mat1(0, 2) = 4;

  mat1(1, 0) = 3;
  mat1(1, 1) = 2;
  mat1(1, 2) = 10;

  mat1(2, 0) = 5;
  mat1(2, 1) = 12;
  mat1(2, 2) = 6;

  mat2(0, 0) = 23;
  mat2(0, 1) = 152;
  mat2(0, 2) = 4;

  mat2(1, 0) = 3;
  mat2(1, 1) = 2;
  mat2(1, 2) = 10;

  mat2(2, 0) = 5;
  mat2(2, 1) = 12;
  mat2(2, 2) = 6;

  mat1 *= mat2;

  ASSERT_EQ(mat1(0, 0), 1005);
  ASSERT_EQ(mat1(0, 1), 3848);
  ASSERT_EQ(mat1(0, 2), 1636);
  ASSERT_EQ(mat1(1, 0), 125);
  ASSERT_EQ(mat1(1, 1), 580);
  ASSERT_EQ(mat1(1, 2), 92);
  ASSERT_EQ(mat1(2, 0), 181);
  ASSERT_EQ(mat1(2, 1), 856);
  ASSERT_EQ(mat1(2, 2), 176);
}

TEST(MulMatrix, Subtest_3) {
  S21Matrix mat1(3, 3), mat2(3, 3);

  mat1(0, 0) = 23;
  mat1(0, 1) = 152;
  mat1(0, 2) = 4;

  mat1(1, 0) = 3;
  mat1(1, 1) = 2;
  mat1(1, 2) = 10;

  mat1(2, 0) = 5;
  mat1(2, 1) = 12;
  mat1(2, 2) = 6;

  mat2(0, 0) = 23;
  mat2(0, 1) = 152;
  mat2(0, 2) = 4;

  mat2(1, 0) = 3;
  mat2(1, 1) = 2;
  mat2(1, 2) = 10;

  mat2(2, 0) = 5;
  mat2(2, 1) = 12;
  mat2(2, 2) = 6;

  S21Matrix mat3(3, 3);
  mat3 = mat1 * mat2;

  ASSERT_EQ(mat3(0, 0), 1005);
  ASSERT_EQ(mat3(0, 1), 3848);
  ASSERT_EQ(mat3(0, 2), 1636);
  ASSERT_EQ(mat3(1, 0), 125);
  ASSERT_EQ(mat3(1, 1), 580);
  ASSERT_EQ(mat3(1, 2), 92);
  ASSERT_EQ(mat3(2, 0), 181);
  ASSERT_EQ(mat3(2, 1), 856);
  ASSERT_EQ(mat3(2, 2), 176);
}

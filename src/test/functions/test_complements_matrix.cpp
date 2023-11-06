#include "../test.hpp"

TEST(Complements, Subtest_1) {
  S21Matrix mat(3, 3);

  mat(0, 0) = 23;
  mat(0, 1) = 152;
  mat(0, 2) = 4;

  mat(1, 0) = 3;
  mat(1, 1) = 2;
  mat(1, 2) = 10;

  mat(2, 0) = 5;
  mat(2, 1) = 12;
  mat(2, 2) = 6;

  S21Matrix mat1 = mat.CalcComplements();

  ASSERT_EQ(mat1(0, 0), -108);
  ASSERT_EQ(mat1(0, 1), 32);
  ASSERT_EQ(mat1(0, 2), 26);
  ASSERT_EQ(mat1(1, 0), -864);
  ASSERT_EQ(mat1(1, 1), 118);
  ASSERT_EQ(mat1(1, 2), 484);
  ASSERT_EQ(mat1(2, 0), 1512);
  ASSERT_EQ(mat1(2, 1), -218);
  ASSERT_EQ(mat1(2, 2), -410);
}

TEST(Complements, Subtest_2) {
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

  S21Matrix mat1 = mat.CalcComplements();

  ASSERT_EQ(mat1(0, 0), 0);
  ASSERT_EQ(mat1(0, 1), 32);
  ASSERT_EQ(mat1(0, 2), -64);
  ASSERT_EQ(mat1(1, 0), -24);
  ASSERT_EQ(mat1(1, 1), 118);
  ASSERT_EQ(mat1(1, 2), -216);
  ASSERT_EQ(mat1(2, 0), 40);
  ASSERT_EQ(mat1(2, 1), -218);
  ASSERT_EQ(mat1(2, 2), 424);
}

TEST(Complements, Subtest_3) {
  S21Matrix mat(2, 2);

  mat(0, 0) = 1;
  mat(0, 1) = 2;

  mat(1, 0) = 3;
  mat(1, 1) = 4;

  S21Matrix mat1 = mat.CalcComplements();

  ASSERT_EQ(mat1(0, 0), 4);
  ASSERT_EQ(mat1(0, 1), -3);
  ASSERT_EQ(mat1(1, 0), -2);
  ASSERT_EQ(mat1(1, 1), 1);
}

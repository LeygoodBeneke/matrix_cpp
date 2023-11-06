#include "../test.hpp"

TEST(Exception, Subtest_1) {
  bool is_exception = false;
  try {
    S21Matrix mat(-1, -1);
  } catch (...) {
    is_exception = true;
  }
  ASSERT_EQ(is_exception, true);
}

TEST(Exception, Subtest_2) {
  bool is_exception = false;
  try {
    S21Matrix mat1(1, 2);
    S21Matrix mat2(5, 6);
    mat1.MulMatrix(mat2);
  } catch (...) {
    is_exception = true;
  }
  ASSERT_EQ(is_exception, true);
}

TEST(Exception, Subtest_3) {
  bool is_exception = false;
  S21Matrix mat(1, 2);
  try {
    mat.Determinant();
  } catch (...) {
    is_exception = true;
  }
  ASSERT_EQ(is_exception, true);
}

TEST(Exception, Subtest_4) {
  bool is_exception = false;
  S21Matrix mat(1, 2);
  try {
    mat.InverseMatrix();
  } catch (...) {
    is_exception = true;
  }
  ASSERT_EQ(is_exception, true);
}

TEST(Exception, Subtest_5) {
  bool is_exception = false;
  try {
    S21Matrix mat(1, 2);
    mat.CalcComplements();
  } catch (...) {
    is_exception = true;
  }
  ASSERT_EQ(is_exception, true);
}

TEST(Exception, Subtest_6) {
  bool is_exception = false;
  try {
    S21Matrix mat1(2, 4);
    S21Matrix mat2(2, 5);
    mat1.SumMatrix(mat2);
  } catch (...) {
    is_exception = true;
  }
  ASSERT_EQ(is_exception, true);
}

TEST(Exception, Subtest_7) {
  bool is_exception = false;
  try {
    S21Matrix mat1(5, 2);
    S21Matrix mat2(4, 2);
    mat1.SumMatrix(mat2);
  } catch (...) {
    is_exception = true;
  }
  ASSERT_EQ(is_exception, true);
}

TEST(Exception, Subtest_8) {
  bool is_exception = false;
  try {
    S21Matrix mat1(5, 23);
    S21Matrix mat2(4, 45);
    mat1.SumMatrix(mat2);
  } catch (...) {
    is_exception = true;
  }
  ASSERT_EQ(is_exception, true);
}

TEST(Exception, Subtest_10) {
  bool is_exception = false;
  try {
    S21Matrix mat1(5, 23);
    mat1(-1, 1);
    mat1(0, -1);
    mat1(1000, 1000);
  } catch (...) {
    is_exception = true;
  }
  ASSERT_EQ(is_exception, true);
}

TEST(Exception, Subtest_9) {
  bool is_exception = false;
  try {
    S21Matrix mat(3, 3);
    mat(0, 0) = 1;
    mat(0, 1) = 1;
    mat(0, 2) = 1;

    mat(1, 0) = 2;
    mat(1, 1) = 2;
    mat(1, 2) = 2;

    mat(2, 0) = 3;
    mat(2, 1) = 3;
    mat(2, 2) = 3;

    mat.InverseMatrix();
  } catch (...) {
    is_exception = true;
  }
  ASSERT_EQ(is_exception, true);
}

#ifndef S21_MATRIX_OOP
#define S21_MATRIX_OOP

#include <algorithm>
#include <cmath>
#include <stdexcept>

class S21Matrix {
 private:
  int rows_, cols_;  // Rows and columns
  double** matrix_;  // Pointer to the memory where the matrix is allocated
  
  double **create_matrix(int rows, int columns);
  void delete_matrix(int rows, double **matrix) noexcept;
  void checkSize(const S21Matrix &other);

 public:
  S21Matrix() noexcept;  // Default constructor
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;

  ~S21Matrix();  // Destructor

  void SumMatrix(const S21Matrix& other);
  bool EqMatrix(const S21Matrix& other) noexcept;
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num) noexcept;
  void MulMatrix(const S21Matrix& other);
 
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  bool operator==(const S21Matrix& other) noexcept;
  bool operator=(const S21Matrix& other);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  double &operator()(int i, int j);
};

#endif

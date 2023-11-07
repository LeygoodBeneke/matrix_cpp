#include "s21_matrix_oop.hpp"

S21Matrix::S21Matrix() noexcept : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::~S21Matrix() noexcept { delete_matrix(rows_, matrix_); }

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  matrix_ = create_matrix(rows, cols);
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  matrix_ = create_matrix(rows_, cols_);
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) matrix_[i][j] = other.matrix_[i][j];
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_(other.rows_), cols_(other.cols_) {
  matrix_ = other.matrix_;
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  checkSize(other);

  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) matrix_[i][j] += other.matrix_[i][j];
}

bool S21Matrix::EqMatrix(const S21Matrix& other) const noexcept {
  if (rows_ != other.rows_ || cols_ != other.cols_) return false;

  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++)
      if (fabs(matrix_[i][j] - other.matrix_[i][j]) > 1e-10) return false;
  return true;
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  checkSize(other);

  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) matrix_[i][j] -= other.matrix_[i][j];
}

void S21Matrix::MulNumber(const double num) noexcept {
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) matrix_[i][j] *= num;
}

S21Matrix S21Matrix::operator*(const double number) const noexcept {
  S21Matrix mat(*this);
  mat.MulNumber(number);
  return mat;
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_)
    throw std::runtime_error(
        "the number of columns of the first matrix is not equal to the number "
        "of rows of the second matrix");

  double** matrix = create_matrix(rows_, other.cols_);
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < other.cols_; j++)
      for (int l = 0; l < cols_; l++)
        matrix[i][j] += matrix_[i][l] * other.matrix_[l][j];

  delete_matrix(rows_, matrix_);
  matrix_ = matrix;
  cols_ = other.cols_;
}

S21Matrix S21Matrix::Transpose() {
  double** result = create_matrix(cols_, rows_);
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) result[j][i] = matrix_[i][j];
  delete_matrix(rows_, matrix_);
  std::swap(rows_, cols_);
  matrix_ = result;
  return S21Matrix(*this);
}

S21Matrix S21Matrix::CalcComplements() {
  if (cols_ == 1) return *this;
  if (cols_ != rows_) throw std::runtime_error("the matrix is not square");

  double** matrix = create_matrix(rows_, cols_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      S21Matrix tmp_matrix(rows_ - 1, cols_ - 1);
      for (int k = 0, m = 0; k < rows_ - 1; k++, m++) {
        for (int l = 0, n = 0; l < cols_ - 1; l++, n++) {
          m += (m == i);
          n += (n == j);
          tmp_matrix(k, l) = matrix_[m][n];
        }
      }
      double tmp_result = tmp_matrix.Determinant();
      matrix[i][j] = (1 - 2 * ((i + j) % 2)) * tmp_result;
    }
  }
  delete_matrix(rows_, matrix_);
  matrix_ = matrix;
  return S21Matrix(*this);
}

double S21Matrix::Determinant() {
  if (cols_ != rows_) throw std::runtime_error("the matrix is not square");

  if (cols_ == rows_ && cols_ == 1) return matrix_[0][0];
  double result = 0;
  for (int k = 0; k < cols_; k++) {
    S21Matrix tmp_matrix(rows_ - 1, cols_ - 1);

    for (int i = 0; i < rows_ - 1; i++)
      for (int j = 0, x = 0; j < cols_ - 1; j++, x++) {
        x += (x == k);
        tmp_matrix(i, j) = matrix_[i + 1][x];
      }
    double tmp_result = tmp_matrix.Determinant();
    result += (1 - 2 * (k % 2)) * tmp_result * matrix_[0][k];
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  S21Matrix complements(*this);
  complements = complements.CalcComplements();
  S21Matrix transpose(complements);
  transpose = transpose.Transpose();
  double det = Determinant();

  if (det == 0) throw std::runtime_error("matrix determinant is 0");

  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) matrix_[i][j] = 1 / det * transpose(i, j);
  return S21Matrix(*this);
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix mat(*this);
  mat.SumMatrix(other);
  return mat;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix mat(*this);
  mat.SubMatrix(other);
  return mat;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix mat(*this);
  mat.MulMatrix(other);
  return mat;
}

bool S21Matrix::operator==(const S21Matrix& other) const noexcept {
  return EqMatrix(other);
}

S21Matrix S21Matrix::operator=(const S21Matrix& other) {
  delete_matrix(rows_, matrix_);
  cols_ = other.cols_;
  rows_ = other.rows_;
  matrix_ = create_matrix(rows_, cols_);

  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) matrix_[i][j] = other.matrix_[i][j];
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double number) noexcept {
  MulNumber(number);
  return *this;
}

double& S21Matrix::operator()(int i, int j) const {
  if (i < 0 || j < 0 || i >= rows_ || j >= cols_)
    throw std::runtime_error("Invalid index");
  return matrix_[i][j];
}

double** S21Matrix::create_matrix(int rows, int columns) {
  if (rows <= 0 || columns <= 0)
    throw std::runtime_error("Invalid matrix size");

  double** matrix = new double*[rows];
  for (int i = 0; i < rows; i++) matrix[i] = new double[columns]();
  return matrix;
}

void S21Matrix::delete_matrix(int rows, double** matrix) noexcept {
  for (int i = 0; i < rows; i++) delete[] matrix[i];
  delete[] matrix;
}

void S21Matrix::checkSize(const S21Matrix& other) const {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::runtime_error("different matrix dimensions");
}

void S21Matrix::SetRows(int rows) {
  if (rows <= 0) throw std::runtime_error("invalid rows number");
  double** matrix = create_matrix(rows, cols_);
  int limit = std::min(rows, rows_);
  for (int i = 0; i < limit; i++)
    for (int j = 0; j < cols_; j++) matrix[i][j] = matrix_[i][j];
  delete_matrix(rows_, matrix_);
  matrix_ = matrix;
  rows_ = rows;
}

void S21Matrix::SetCols(int cols) {
  if (cols <= 0) throw std::runtime_error("invalid cols number");
  double** matrix = create_matrix(rows_, cols);
  int limit = std::min(cols, cols_);
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < limit; j++) matrix[i][j] = matrix_[i][j];
  delete_matrix(rows_, matrix_);
  matrix_ = matrix;
  cols_ = cols;
}

S21Matrix operator*(const double left, S21Matrix& other) noexcept {
  S21Matrix mat(other);
  mat.MulNumber(left);
  return mat;
}

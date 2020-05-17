// Copyright 2020 Sokolov Andrey
#include <vector>
#include <sstream>

#ifndef MODULES_MATRIX_OPERATIONS_INCLUDE_MATRIX_OPERATIONS_H_
#define MODULES_MATRIX_OPERATIONS_INCLUDE_MATRIX_OPERATIONS_H_

class Matrix {
 public:
    Matrix(const int _rows, const int _cols);
    Matrix(const int _rows,
           const int _cols,
           std::vector<std::vector<double>> _data);
    Matrix(const Matrix& _matrix);
    Matrix(const int _rows, const int _cols, std::vector<double> _data);

    int getRows() const;
    int getCols() const;
    std::vector<std::vector<double>> getData() const;

    void setRows(const int _rows);
    void setCols(const int _cols);
    void setData(std::vector<std::vector<double>> _data);

    Matrix operator+ (const Matrix& _matrix) const;
    Matrix operator- (const Matrix& _matrix) const;
    Matrix operator* (const double& _scalar) const;
    Matrix operator* (const Matrix& _matrix) const;

    Matrix& operator= (const Matrix& _matrix);

    bool operator== (const Matrix& _matrix) const;
    bool operator!= (const Matrix& _matrix) const;

    double determinant();
    Matrix transpose();
    Matrix takeInverseMatrix();

    friend std::ostringstream& operator<<(std::ostringstream& os,
      Matrix& m);

 private:
    int rows;
    int cols;
    std::vector<std::vector<double>> data;
};

#endif  // MODULES_MATRIX_OPERATIONS_INCLUDE_MATRIX_OPERATIONS_H_

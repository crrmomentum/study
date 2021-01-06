#include <iostream>
#include <string.h>
#include "matrix.h"

Matrix::Matrix(int rows, int cols, bool is_random) {
    _rows = rows;
    _cols = cols;
    if (is_random) {
        _matrix = allocate_random_matrix(100);
    }
    else {
        _matrix = allocate_empty_matrix();
    }
    transpose();
}

Matrix::Matrix(int rows, int cols, int* matrix) {
    _rows = rows;
    _cols = cols;
    _matrix = matrix;
}

Matrix::~Matrix() {
    //    delete _matrix;
    //    delete _matrix_transpose;
    //    delete _matrix_adj;
    //    delete _matrix_inv;
}

int* Matrix::allocate_empty_matrix() {
    int* m = new int[_rows*_cols];
    memset(m, 0, sizeof(m[0]) * _rows * _cols);
    return m;
}

int* Matrix::allocate_random_matrix(int maxNumber) {
    int* m = allocate_empty_matrix();

    for (int i = 0; i < _rows*_cols; ++i) {
        m[i] = rand() % maxNumber;
    }

    return m;
}

void Matrix::transpose() {
    _matrix_transpose = allocate_empty_matrix();
    int tIndex = 0;
    for (int i = 0, j = 0; i < _rows*_cols; ++i) {
        if (i > 0 && (i%_cols == 0)) {
            ++j;
        }
        tIndex = _cols * (i % _cols) + j;
        _matrix_transpose[i] = _matrix[tIndex];
    }
}

int Matrix::det(int* m, int cols) {
    int res = 0;
    if (_cols != _rows) {
        std::cout << "It's not a square matrix, can't get determinant" << std::endl;
        return 0;
    }
    if (cols == 2) {
        return (_matrix[0] * _matrix[3] - _matrix[1] * _matrix[2]);
    }
    //    else {
    //        res = _matrix[0] * det(m) - _matrix[1] * det(m) + _matrix[2] * det(m);
    //    }

    return res;
}

int* Matrix::getSubmatrix(int* matrix, int cols, int pos) {
    int submatrix_size = (cols-1)*(cols-1);
    int* submatrix = new int[submatrix_size];
    for (int j = cols, i = 0; j < cols * cols; ++j) {
        if ((j-pos)%cols == 0) continue;
        submatrix[i++] = matrix[j];
        std::cout << submatrix[i-1] << std::endl;
    }
    return submatrix;
}

void Matrix::adj() {
    _matrix_adj = allocate_empty_matrix();
    int aIndex = 0;
    for (int i = 0, j = 0; i < _rows*_cols; ++i) {
        if (i > 0 && (i%_cols == 0)) {
            ++j;
        }
        aIndex = _cols * (i % _cols) + j;
        _matrix_transpose[i] = _matrix[aIndex];
    }
}

int* Matrix::getRawMatrix() const {
    return _matrix;
}

int Matrix::getCols() const {
    return _cols;
}

int Matrix::getRows() const {
    return _rows;
}

Matrix* Matrix::operator+(const Matrix& m) {

    if (m.getCols() != _cols || m.getRows() != _rows) {
        std::cout << "Cannot sum these matrices, number of cols or rows don't match" << std::endl;
        return NULL;
    }
    Matrix* c = new Matrix(_rows, _cols, false);

    for (int i = 0; i < _rows*_cols; ++i) {
        // C = A + B
        c->getRawMatrix()[i] = this->getRawMatrix()[i] + m.getRawMatrix()[i];
    }

    return c;
}

Matrix* Matrix::operator-(const Matrix& m) {
    if (m.getCols() != _cols || m.getRows() != _rows) {
        std::cout << "Cannot substract these matrices, number of cols or rows don't match" << std::endl;
        return NULL;
    }
    Matrix* c = new Matrix(_rows, _cols, false);

    for (int i = 0; i < _rows*_cols; ++i) {
        // C = A - B
        c->getRawMatrix()[i] = this->getRawMatrix()[i] - m.getRawMatrix()[i];
    }

    return c;
}

Matrix* Matrix::operator*(const Matrix& m) {
    if (this->_cols != m.getRows()) {
        std::cout << "Cannot multiply these matrices" << std::endl;
        return NULL;
    }
    // if n = j; A[m,n]*B[j,k] = C[m,k]  // Number of rows of the first matrix and number of columns of the second matrix
    Matrix* c = new Matrix(this->_rows, m.getCols(), false);

    // Cij = sum(Aik + Bkj) = sum(A1k + Bk1); let the row of the first matrix fixed and the cols of the second matrix fixed
    // For loop to change matrix index
    std::cout << "value of B rows: " << m.getCols()<< std::endl;
    int aIndex = 0;
    int bIndex = 0;
    for (int i = 0, k = 0, h =0; i < this->_rows * m.getCols(); ++i) {
        // For loop for sum and multiplication, sum and mul for the number of cols of A, multiply the first row of A by the first col of B
        std::cout << "***************next iter**************** " << i<< std::endl;
        if (i > 0 && i%(m.getCols()) == 0) {
            ++k;
        }
        if (i > 0 && i%(m.getCols()) == 0) {
            ++h;
        }
        for (int j = 0; j < this->_cols; ++j) {
            aIndex = j + k*this->_cols;
            bIndex = j*m.getCols() + i%m.getCols();
            c->getRawMatrix()[i] += this->getRawMatrix()[aIndex] * m.getRawMatrix()[bIndex];
            std::cout << "Product of C element is: " << this->getRawMatrix()[aIndex] << " * " << m.getRawMatrix()[bIndex] << std::endl;
            std::cout << "value of C is: " << c->getRawMatrix()[i] << std::endl;
        }
    }

    return c;
}

void Matrix::print(Matrix::eMatrixType type) {
    int* pMatrix = NULL;
    switch (type) {
    case REGULAR: pMatrix = _matrix;
        break;
    case TRANSPOSE: pMatrix = _matrix_transpose;
        break;
    case ADJ: pMatrix = _matrix_adj;
        break;
    default: pMatrix = _matrix_inv;
    }

    if (!pMatrix) {
        std::cout << "Selected type to print is invalid" << std::endl;
        return;
    }

    for (int i = 0; i < _rows*_cols; ++i) {
        if (i%_cols == 0) std::cout << std::endl;
        std::cout << pMatrix[i] << "   ";
    }
    std::cout << std::endl;
}

void Matrix::print(int* matrix, int rows, int cols) {
    if (!matrix) {
        std::cout << "Input matrix is NULL" << std::endl;
        return;
    }
    for (int i = 0; i < rows*cols; ++i) {
        if (i%cols == 0) std::cout << std::endl;
        std::cout << matrix[i] << "   ";
    }
    std::cout << std::endl;
}

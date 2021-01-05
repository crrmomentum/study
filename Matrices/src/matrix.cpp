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

void Matrix::print() {

    for (int i = 0; i < _rows*_cols; ++i) {
        if (i%_cols == 0) std::cout << std::endl;
        std::cout << this->getRawMatrix()[i] << "   ";
    }
    std::cout << std::endl;
}

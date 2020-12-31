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
    if (m.getCols() != _cols && m.getRows() != _rows) {
        std::cout << "Cannot sum these matrices, nomber of cols or rows don't match" << std::endl;
        return NULL;
    }
    Matrix* c = new Matrix(_rows, _cols);

    for (int i = 0; i < _rows*_cols; ++i) {
        // C = A + B
        c->getRawMatrix()[i] = this->getRawMatrix()[i] + m.getRawMatrix()[i];
    }

    return c;
}

//Matrix* Matrix::operator-(const Matrix& m) {
//    int* c = allocate_empty_matrix();

//    for (int i = 0; i < _rows*_cols; ++i) {
//        c[i] = a[i] - b[i];
//    }

//    return c;
//}

//Matrix* Matrix::operator*(const Matrix& m) {
//    int* c = allocate_empty_matrix();

//    for (int i = 0; i < _rows*_cols; ++i) {
//        c[i] = a[i] + b[i];
//    }

//    return c;
//}

void Matrix::print() {

    for (int i = 0; i < _rows*_cols; ++i) {
        if (i%3 == 0) std::cout << std::endl;
        std::cout << this->getRawMatrix()[i] << "   ";
    }
    std::cout << std::endl;
}

#include <iostream>
#include <string.h>
#include <math.h>
#include <cstdlib>
#include "matrix.h"

Matrix::Matrix(int rows, int cols, bool is_random) {
    _rows = rows;
    _cols = cols;
    if (is_random) {
        _matrix = allocate_random_matrix(10);
        // Calculate internal values  like determinant, transpose, adj
        init_matrix();
    }
    else {
        _matrix = allocate_empty_matrix();
    }
}

Matrix::Matrix(int rows, int cols, int* matrix) {
    _rows = rows;
    _cols = cols;
    _matrix = matrix;
    // Calculate internal values  like determinant, transpose, adj
    init_matrix();
}

Matrix::~Matrix() {
    //    delete _matrix;
    //    delete _matrix_transpose;
    //    delete _matrix_adj;
    //    delete _matrix_inv;
}

void Matrix::init_matrix() {
    transpose();
    // We can only get determinants for square matrices
    if (_rows == _cols) {
      _det = det(_matrix, _cols);
      std::cout << "Det is : " << _det << std::endl;
      getCofactorMatrix();
//      std::cout << "Printing cofactor" << std::endl;
//      print(COFACTOR);
      //adj();
      // inverse();
    }
    else {
      std::cout << "Cannot get determinant, adjugate, cofactor matrix \
                    and inverse for non-square matrices " << std::endl;
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

    if (cols == 2) {
        return (m[0] * m[3] - m[1] * m[2]);
    }
    else {
        int* submatrix = NULL;
        for (int i = 0; i < cols; ++i) {
            submatrix = getSubmatrix(m, cols, i);
            res += m[i] * pow(-1, i) * det(submatrix, cols-1);
            delete[] submatrix;
        }
    }

    return res;
}

int* Matrix::getSubmatrix(int* matrix, int cols, int pos) {
    // ToDo: Evaluate 2x2 scenario
    const int submatrix_size = (cols-1)*(cols-1);
    int* submatrix = new int[submatrix_size];
    int rowNumber = pos/cols;   // Will skip all numbers associated with this row
    int currRow = 0;

    for (int j = 0, i = 0; j < cols * cols; ++j) {
        // Calculate current row
        currRow = j/cols;
        // This if condition matches the number of row, skip all columns
        // associated with that row
        if (currRow == rowNumber) {
            j = j + cols - 1;
            continue;
        }
        // Match the number of column, skip
        if ((abs(j-pos))%cols == 0) continue;
        submatrix[i++] = matrix[j];
        //std::cout << "submatrix val: " << matrix[j] << std::endl;
    }
    return submatrix;
}

int Matrix::getDeterminant() const {
    return _det;
}

void Matrix::getCofactorMatrix() {
    int* submatrix = NULL;
    _matrix_cofactor = allocate_empty_matrix();
    // Each cofactor is equal of the corresponding submatrix determinant
    for (int i = 0; i < _rows*_cols; ++i) {
        submatrix = getSubmatrix(_matrix, _cols, i);
        _matrix_cofactor[i] = pow(-1, i) * det(submatrix, _cols-1);
        delete[] submatrix;
    }
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
    int* matrix = new int[_rows*m.getCols()];

    for (int i = 0; i < _rows*_cols; ++i) {
        // C = A + B
        matrix[i] = _matrix[i] + m.getRawMatrix()[i];
    }

    Matrix* c = new Matrix(_rows, _cols, matrix);

    return c;
}

Matrix* Matrix::operator-(const Matrix& m) {
    if (m.getCols() != _cols || m.getRows() != _rows) {
        std::cout << "Cannot substract these matrices, number of cols or rows don't match" << std::endl;
        return NULL;
    }

    int* matrix = new int[_rows*m.getCols()];

    for (int i = 0; i < _rows*_cols; ++i) {
        // C = A - B
        matrix[i] = _matrix[i] - m.getRawMatrix()[i];
    }

    Matrix* c = new Matrix(_rows, _cols, matrix);

    return c;
}

Matrix* Matrix::operator*(const Matrix& m) {
    if (this->_cols != m.getRows()) {
        std::cout << "Cannot multiply these matrices" << std::endl;
        return NULL;
    }
    // if n = j; A[m,n]*B[j,k] = C[m,k]  // Number of rows of the first matrix and number of columns of the second matrix
    int* matrix = new int[_rows*m.getCols()];

    // Cij = sum(Aik + Bkj) = sum(A1k + Bk1); let the row of the first matrix fixed and the cols of the second matrix fixed
    // For loop to change matrix index
    std::cout << "value of B rows: " << m.getCols()<< std::endl;
    int aIndex = 0;
    int bIndex = 0;
    for (int i = 0, k = 0, h =0; i < this->_rows * m.getCols(); ++i) {
        // For loop for sum and multiplication, sum and mul for the number of cols of A, multiply the first row of A by the first col of B
        if (i > 0 && i%(m.getCols()) == 0) {
            ++k;
        }
        if (i > 0 && i%(m.getCols()) == 0) {
            ++h;
        }
        for (int j = 0; j < this->_cols; ++j) {
            aIndex = j + k*this->_cols;
            bIndex = j*m.getCols() + i%m.getCols();
            matrix[i] += _matrix[aIndex] * m.getRawMatrix()[bIndex];
//            std::cout << "Product of C element is: " << this->getRawMatrix()[aIndex] << " * " << m.getRawMatrix()[bIndex] << std::endl;
//            std::cout << "value of C is: " << c->getRawMatrix()[i] << std::endl;
        }
    }

    Matrix* c = new Matrix(_rows, m.getCols(), matrix);

    return c;
}

void Matrix::print(Matrix::eMatrixType type) const {
    int* pMatrix = NULL;
    switch (type) {
        case REGULAR: pMatrix = _matrix;
            break;
        case TRANSPOSE: pMatrix = _matrix_transpose;
            break;
        case COFACTOR: pMatrix = _matrix_cofactor;
            break;
        case ADJ: pMatrix = _matrix_adj;
            break;
        default: pMatrix = _matrix_inv;
    }

    if (!pMatrix) {
        std::cout << "Selected type to print is invalid" << std::endl;
        return;
    }

    std::cout << "--------------------Printing matrix--------------------" << "\n\n";
    for (int i = 0; i < _rows*_cols; ++i) {
        if (i > 0 && i%_cols == 0) std::cout << std::endl;
        std::cout << pMatrix[i] << "   ";
    }
    std::cout << "\n\n";
}

//int Matrix::operator()(int row, int col) {
//    return 0;
//}

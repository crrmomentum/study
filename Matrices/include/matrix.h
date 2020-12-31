#ifndef MATRIX_H
#define MATRIX_H

class Matrix {

public:
    Matrix(int rows, int cols, bool is_random = true);

    Matrix* operator+(const Matrix& m);
//    Matrix* operator-(const Matrix& m);
//    Matrix* operator*(const Matrix& m);

    int* getRawMatrix() const;
    int getCols() const;
    int getRows() const;
//    int* transpose(int* a);
//    int* inv(int* a);
    void print();

private:
    int* allocate_empty_matrix();
    int* allocate_random_matrix(int maxNumber);

    int* _matrix;
    int _rows;
    int _cols;
};

#endif // MATRIX_H

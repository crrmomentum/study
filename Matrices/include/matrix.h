#ifndef MATRIX_H
#define MATRIX_H

class Matrix {

public:
    Matrix(int rows, int cols, bool is_random = true);
    Matrix(int rows, int cols, int* matrix);

    ~Matrix();

    Matrix* operator+(const Matrix& m);
    Matrix* operator-(const Matrix& m);
    Matrix* operator*(const Matrix& m);

    typedef enum {
        REGULAR = 0,
        TRANSPOSE,
        ADJ,
        INVERSE
    } eMatrixType;

    int* getRawMatrix() const;
    int getCols() const;
    int getRows() const;
    void print(eMatrixType type);

    static void print(int* matrix, int rows, int cols);

private:
    int* allocate_empty_matrix();
    int* allocate_random_matrix(int maxNumber);
    int det(int* m, int cols);
    void transpose();
    void adj();
    int* getSubmatrix(int* matrix, int pos, int cols);
    //int* inv(int* a);

    int* _matrix;
    int* _matrix_transpose;
    int* _matrix_adj;
    int* _matrix_inv;
    int _rows;
    int _cols;
};

#endif // MATRIX_H

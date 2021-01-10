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
//    Matrix* operator=(const Matrix& m);
//    Matrix* operator/(const Matrix& m);
//    int operator()(int row, int col);

    typedef enum {
        REGULAR = 0,
        TRANSPOSE,
        COFACTOR,
        ADJ,
        INVERSE
    } eMatrixType;

    int* getRawMatrix() const;
    int getCols() const;
    int getRows() const;
    void print(eMatrixType type) const;
    int getDeterminant() const;

private:
    void init_matrix();
    int* allocate_empty_matrix();
    int* allocate_random_matrix(int maxNumber);
    int det(int* m, int cols);
    void transpose();
    void adj();
    int* getSubmatrix(int* matrix, int pos, int cols);
    void getCofactorMatrix();
    //int* inv(int* a);

    int* _matrix;
    int* _matrix_transpose;
    int* _matrix_adj;
    int* _matrix_inv;
    int* _matrix_cofactor;
    int _rows;
    int _cols;
    int _det;
};

#endif // MATRIX_H

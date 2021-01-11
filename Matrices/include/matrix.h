#ifndef MATRIX_H
#define MATRIX_H

class Matrix {

public:
    Matrix(int rows, int cols, bool is_random = true);
    Matrix(int rows, int cols, float* matrix);

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

    float* getRawMatrix() const;
    int getCols() const;
    int getRows() const;
    void print(eMatrixType type) const;
    float getDeterminant() const;

private:
    void init_matrix();
    float* allocate_empty_matrix();
    float* allocate_random_matrix(int maxNumber);
    float det(float* m, int cols);
    float* transpose(float* matrix);
    void adj();
    float* getSubmatrix(float* matrix, int pos, int cols);
    void getCofactorMatrix();
    void inv();

    float* _matrix;
    float* _matrix_transpose;
    float* _matrix_adj;
    float* _matrix_inv;
    float* _matrix_cofactor;
    float _det;
    int _rows;
    int _cols;
};

#endif // MATRIX_H

#ifndef MATRIX_H
#define MATRIX_H

#include <map>
#include <string.h>

class Matrix {

public:
    Matrix(int rows, int cols, bool is_random = true);
    Matrix(int rows, int cols, float* matrix);

    // Copy constructor
    Matrix(const Matrix& m);

    // Destructor
    ~Matrix();

    // Typedefs
    typedef enum {
        REGULAR = 0,
        TRANSPOSE,
        COFACTOR,
        ADJ,
        INVERSE
    } eMatrixType;

    typedef std::map<eMatrixType, std::string> MatrixType;

    Matrix* operator+(const Matrix& m);
    Matrix* operator-(const Matrix& m);
    Matrix* operator*(const Matrix& m);
    Matrix* operator/(const Matrix& m);
    Matrix* operator=(const Matrix& m);
//    int operator()(int row, int col);

    float* getRegularMatrix() const;
    float* getInverseMatrix() const;
    float getDeterminant() const;
    int getCols() const;
    int getRows() const;
    void print(eMatrixType type) const;

private:
    void init_matrix();
    void adj();
    void getCofactorMatrix();
    void inv();
    float det(float* m, int cols);
    float* allocate_empty_matrix();
    float* allocate_random_matrix(int maxNumber);
    float* transpose(float* matrix);
    float* getSubmatrix(float* matrix, int pos, int cols);
    float* getProduct(float* b, int cols);


    float* _matrix;
    float* _matrix_transpose;
    float* _matrix_adj;
    float* _matrix_inv;
    float* _matrix_cofactor;
    float _det;
    int _rows;
    int _cols;

    //MatrixTypePtr matrixTypePtr;
    MatrixType matrixType;
};

#endif // MATRIX_H

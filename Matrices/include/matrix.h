#ifndef MATRIX_H
#define MATRIX_H

#include <map>
#include <string.h>
#include "matrix_factory.h"

namespace CustomMatrix {

class Matrix : public MatrixFactory {

public:
    Matrix(int rows, int cols, bool is_random = true);
    Matrix(int rows, int cols, float* matrix);

    // Copy constructor
    Matrix(const Matrix& m);

    // Destructor
    ~Matrix();

    typedef std::map<eMatrixType, std::string> MatrixType;

    Matrix* operator+(const Matrix& m) override;
    Matrix* operator-(const Matrix& m) override;
    Matrix* operator*(const Matrix& m) override;
    Matrix* operator/(const Matrix& m) override;
    Matrix* operator=(const Matrix& m) override;
//    int operator()(int row, int col);

    float* get_regular_matrix() const override;
    float* get_inverse_matrix() const override;
    float get_determinant() const override;
    int get_cols() const override;
    int get_rows() const override;
    void print(eMatrixType type) const override;

private:
    void init_matrix();
    void calc_adjugate();
    void calc_cofactor();
    void calc_inverse();
    float calc_determinant(float* m, int cols);
    float* allocate_empty_matrix();
    float* allocate_random_matrix(int maxNumber);
    float* transpose(float* matrix);
    float* get_submatrix(float* matrix, int pos, int cols);
    float* get_product(float* b, int cols);


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

}
#endif // MATRIX_H

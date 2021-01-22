#ifndef MATRIXFACTORY_H
#define MATRIXFACTORY_H

namespace CustomMatrix {

class Matrix;

class MatrixFactory {

public:
    static Matrix* create_matrix();

    // Typedefs
    typedef enum {
        REGULAR = 0,
        TRANSPOSE,
        COFACTOR,
        ADJ,
        INVERSE
    } eMatrixType;

    virtual Matrix* operator+(const Matrix& m) = 0;
    virtual Matrix* operator-(const Matrix& m) = 0;
    virtual Matrix* operator*(const Matrix& m) = 0;
    virtual Matrix* operator/(const Matrix& m) = 0;
    virtual Matrix* operator=(const Matrix& m) = 0;
//    int operator()(int row, int col);

    virtual float* get_regular_matrix() const = 0;
    virtual float* get_inverse_matrix() const = 0;
    virtual float get_determinant() const = 0;
    virtual int get_cols() const = 0;
    virtual int get_rows() const = 0;
    virtual void print(eMatrixType type) const = 0;

private:
    //MatrixFactory();
    //virtual ~MatrixFactory();
};

}
#endif // MATRIXFACTORY_H

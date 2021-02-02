#ifndef IMATRIX_H
#define IMATRIX_H

#include <memory>

namespace CustomMatrix {

class IMatrix {

public:
    // Typedefs
    typedef enum {
        REGULAR = 0,
        TRANSPOSE,
        COFACTOR,
        ADJ,
        INVERSE
    } eMatrixType;

//    typedef std::shared_ptr<IMatrix> MatrixPtr;

    virtual std::shared_ptr<IMatrix> add(const std::shared_ptr<IMatrix>& m) = 0;
    virtual std::shared_ptr<IMatrix> substract(const std::shared_ptr<IMatrix>& m) = 0;
    virtual std::shared_ptr<IMatrix> multiply(const std::shared_ptr<IMatrix>& m) = 0;
    virtual std::shared_ptr<IMatrix> divide(const std::shared_ptr<IMatrix>& m) = 0;
//    virtual std::shared_ptr<IMatrix> operator=(const std::shared_ptr<IMatrix>& m) = 0;
//    int operator()(int row, int col);

    virtual float* get_regular_matrix() const = 0;
    virtual float* get_inverse_matrix() const = 0;
    virtual float get_determinant() const = 0;
    virtual int get_cols() const = 0;
    virtual int get_rows() const = 0;
    virtual void print(eMatrixType type) const = 0;
};

}
#endif // IMATRIX_H

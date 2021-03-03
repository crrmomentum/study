#ifndef IMATRIX_H
#define IMATRIX_H

#include <memory>

namespace CustomMatrix {

class IMatrix;
typedef std::shared_ptr<IMatrix> IMatrixPtr;

class IMatrix {

public:
    virtual ~IMatrix() {}

    // Typedefs
    typedef enum {
        REGULAR = 0,
        TRANSPOSE,
        COFACTOR,
        ADJ,
        INVERSE
    } eMatrixType;

    typedef enum {
        ROT_90 = 0,
        ROT_180,
        ROT_270
    } eRotate;

    virtual IMatrixPtr add(const IMatrixPtr& m) = 0;
    virtual IMatrixPtr substract(const IMatrixPtr& m) = 0;
    virtual IMatrixPtr multiply(const IMatrixPtr& m) = 0;
    virtual IMatrixPtr divide(const IMatrixPtr& m) = 0;
    virtual IMatrixPtr rotate(eRotate rotation) = 0;

    virtual float operator()(int row, int col) = 0;
    virtual float* get_1d_raw_matrix(eMatrixType type) const = 0;
    virtual float** get_2d_raw_matrix(eMatrixType type) const = 0;
    virtual float get_determinant() const = 0;
    virtual int get_cols() const = 0;
    virtual int get_rows() const = 0;
    virtual void print(eMatrixType type) const = 0;

private:
    IMatrixPtr operator=(const IMatrixPtr& m) = delete;
};

}
#endif // IMATRIX_H

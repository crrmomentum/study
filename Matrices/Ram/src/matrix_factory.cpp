#include "matrix_factory.h"

namespace CustomMatrix {

Matrix* MatrixFactory::create_matrix(int rows, int cols, float* matrix) {
    Matrix* m = nullptr;
    if (matrix) {
        m = new Matrix(rows, cols, matrix);
    }
    else {
        m = new Matrix(rows, cols, true);
    }
    return m;
}

}

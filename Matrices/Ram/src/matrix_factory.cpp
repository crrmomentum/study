#include "matrix_factory.h"
#include "matrix.h"

namespace CustomMatrix {

std::shared_ptr<IMatrix> MatrixFactory::create_matrix(int rows, int cols, float* matrix) {
    std::shared_ptr<IMatrix> m = nullptr;
    if (matrix) {
        m = std::make_shared<Matrix>(rows, cols, matrix);
    }
    else {
        m = std::make_shared<Matrix>(rows, cols, true);
    }
    return m;
}

}

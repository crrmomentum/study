#ifndef MATRIXFACTORY_H
#define MATRIXFACTORY_H

#include "matrix_interface.h"

namespace CustomMatrix {

class MatrixFactory {

public:
    static MatrixFactory& getInstance();
    std::shared_ptr<IMatrix> create_matrix(int rows, int cols, float* matrix = nullptr);

private:
    MatrixFactory();
    ~MatrixFactory();
    MatrixFactory(const MatrixFactory&) = delete;
    MatrixFactory operator=(const MatrixFactory&) = delete;
};

}
#endif // MATRIXFACTORY_H

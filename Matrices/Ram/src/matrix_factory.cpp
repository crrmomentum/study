#include "matrix_factory.h"
#include "matrix.h"
#include <iostream>

namespace CustomMatrix {

MatrixFactory::MatrixFactory() {
    std::cout << "MatrixFactory constructor" << std::endl;
}

MatrixFactory::~MatrixFactory() {
    std::cout << "MatrixFactory destructor" << std::endl;
}

MatrixFactory& MatrixFactory::getInstance() {
    static MatrixFactory factory;
    return factory;
}

IMatrixPtr MatrixFactory::create_matrix(int rows, int cols, float* matrix) {
    IMatrixPtr m = nullptr;
    if (matrix) {
        m = std::make_shared<Matrix>(rows, cols, matrix);
    }
    else {
        m = std::make_shared<Matrix>(rows, cols, true);
    }
    return m;
}

}

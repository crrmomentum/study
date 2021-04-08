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

IMatrixPtr MatrixFactory::create_matrix(int rows, int cols, float** matrix) {
    IMatrixPtr m = nullptr;
    std::cout << "si entro nullptr" << std::endl;
    if (matrix) {
         std::cout << "si entro if matrix" << std::endl;
        m = std::make_shared<Matrix>(rows, cols, matrix);
    }
else {
    std::cout << "Matrix no specified" << std::endl;
}
    return m;
}

}

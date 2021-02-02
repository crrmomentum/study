#ifndef MATRIXFACTORY_H
#define MATRIXFACTORY_H

#include "matrix_interface.h"

namespace CustomMatrix {

class MatrixFactory {

public:
    static std::shared_ptr<IMatrix> create_matrix(int rows, int cols, float* matrix = nullptr);


private:
    //MatrixFactory();
    //virtual ~MatrixFactory();
};

}
#endif // MATRIXFACTORY_H

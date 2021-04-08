#include <iostream>
#include "matrix_factory.h"
#include "matrix_interface.h"

using namespace CustomMatrix;

int main ()
{
    MatrixFactory& factory = MatrixFactory::getInstance(); 

    float** A = new float* [2]; 
    int k=0;

    for (int i = 0; i < 2; i++) {
        A[i] = new float[2];
        for (int j = 0; j <2; j++) {
            A[i][j]=k++;
        }
    }

    IMatrixPtr matrixA = factory.create_matrix(2,2,A);
    IMatrixPtr matrixB = factory.create_matrix(2,2,A);
    IMatrixPtr matrixC = matrixA->add(matrixB);

   for (int i = 0; i < matrixC->get_cols(); i++) {
        for (int j = 0; j <matrixC->get_rows(); j++) {
            std::cout<<matrixC->get_2d_raw_matrix((IMatrix::eMatrixType)1)[i][j]<<std::endl;;
        }
    }

    return 0;
}

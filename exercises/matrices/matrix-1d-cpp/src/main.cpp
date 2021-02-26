#include <iostream>
#include "matrix_factory.h"
#include "matrix_interface.h"

using namespace CustomMatrix;

int main() {
    std::cout << "Program testing matrices operations" << "\n";
    // Get Matrix factory
    MatrixFactory& matrixFactory = MatrixFactory::getInstance();

    // SUM
    {
        std::cout << "************************** SUM **********************" << "\n";
        float arr[9] = {-3,2,-5,-1,0,-2,3,-4,1};
        // Get Matrix factory
        IMatrixPtr a = matrixFactory.create_matrix(3, 3, &arr[0]);
        a->print(IMatrix::REGULAR);
        a->print(IMatrix::TRANSPOSE);
        IMatrixPtr b = matrixFactory.create_matrix(3, 3);
        b->print(IMatrix::REGULAR);
        IMatrixPtr c = a->add(b);
        std::cout << "Printing result matrix C: " << std::endl;
        c->print(IMatrix::REGULAR);
    }

    // SUBS
    {
        std::cout << "\n\n************************** SUBS **********************" << "\n";
        IMatrixPtr a = matrixFactory.create_matrix(3, 3);
        a->print(IMatrix::REGULAR);
        IMatrixPtr b = matrixFactory.create_matrix(3, 3);
        b->print(IMatrix::REGULAR);
        IMatrixPtr c = a->substract(b);
        c->print(IMatrix::REGULAR);
    }

    // MUL
    {
        std::cout << "\n\n************************** MUL **********************" << "\n";
        IMatrixPtr a = matrixFactory.create_matrix(3, 3);
        a->print(IMatrix::REGULAR);
        IMatrixPtr b = matrixFactory.create_matrix(3, 3);
        b->print(IMatrix::REGULAR);
        IMatrixPtr c = a->multiply(b);
        if (c) {
            c->print(IMatrix::REGULAR);
            std::cout << "C Size is: " << c->get_rows() << " " << c->get_cols() << std::endl;
            std::cout << "C matrix determinant is: " << c->get_determinant() << std::endl;
        }
    }

    // DIV
    {
        std::cout << "\n\n************************** DIV **********************" << "\n";
        IMatrixPtr a = matrixFactory.create_matrix(4, 4);
        a->print(IMatrix::REGULAR);
        IMatrixPtr b = matrixFactory.create_matrix(4, 4);
        b->print(IMatrix::REGULAR);
        IMatrixPtr c = a->divide(b);
        if (c) {
            c->print(IMatrix::REGULAR);
            std::cout << "C Size is: " << c->get_rows() << " " << c->get_cols() << std::endl;
        }
    }

}


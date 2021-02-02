#include <iostream>
#include "matrix_factory.h"
#include "matrix_interface.h"

using namespace CustomMatrix;

int main() {
    std::cout << "Program testing matrices operations" << "\n";
    // SUM
    {
        std::cout << "************************** SUM **********************" << "\n";
        float arr[9] = {-3,2,-5,-1,0,-2,3,-4,1};
        //Matrix a(3, 3, &arr[0]);
        // Get Matrix factory
        std::shared_ptr<IMatrix> a = MatrixFactory::create_matrix(3, 3, &arr[0]);
        a->print(IMatrix::REGULAR);
        a->print(IMatrix::TRANSPOSE);
        std::shared_ptr<IMatrix> b = MatrixFactory::create_matrix(3, 3);
        b->print(IMatrix::REGULAR);
        std::shared_ptr<IMatrix> c = a->add(b);
        c->print(IMatrix::REGULAR);
    }

    // SUBS
    {
        std::cout << "\n\n************************** SUBS **********************" << "\n";
        std::shared_ptr<IMatrix> a = MatrixFactory::create_matrix(3, 3);
        a->print(IMatrix::REGULAR);
        std::shared_ptr<IMatrix> b = MatrixFactory::create_matrix(3, 3);
        b->print(IMatrix::REGULAR);
        std::shared_ptr<IMatrix> c = a->substract(b);
        c->print(IMatrix::REGULAR);
    }

    // MUL
    {
        std::cout << "\n\n************************** MUL **********************" << "\n";
        std::shared_ptr<IMatrix> a = MatrixFactory::create_matrix(3, 3);
        a->print(IMatrix::REGULAR);
        std::shared_ptr<IMatrix> b = MatrixFactory::create_matrix(3, 3);
        b->print(IMatrix::REGULAR);
        std::shared_ptr<IMatrix> c = a->multiply(b);
        if (c) {
            c->print(IMatrix::REGULAR);
            std::cout << "C Size is: " << c->get_rows() << " " << c->get_cols() << std::endl;
            std::cout << "C matrix determinant is: " << c->get_determinant() << std::endl;
        }
    }

    // DIV
    {
        std::cout << "\n\n************************** DIV **********************" << "\n";
        std::shared_ptr<IMatrix> a = MatrixFactory::create_matrix(4, 4);
        a->print(IMatrix::REGULAR);
        std::shared_ptr<IMatrix> b = MatrixFactory::create_matrix(4, 4);
        b->print(IMatrix::REGULAR);
        std::shared_ptr<IMatrix> c = a->divide(b);
        if (c) {
            c->print(IMatrix::REGULAR);
            std::cout << "C Size is: " << c->get_rows() << " " << c->get_cols() << std::endl;
        }
    }

}


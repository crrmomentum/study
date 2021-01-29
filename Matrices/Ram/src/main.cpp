#include <iostream>
#include "matrix_factory.h"

using namespace CustomMatrix;

int main() {
    std::cout << "Program testing matrices operations" << "\n";
    // SUM
    {
        std::cout << "************************** SUM **********************" << "\n";
        float arr[9] = {-3,2,-5,-1,0,-2,3,-4,1};
        //Matrix a(3, 3, &arr[0]);
        // Get Matrix factory
        IMatrix* a = MatrixFactory::create_matrix(3, 3, &arr[0]);
        a->print(IMatrix::REGULAR);
        a->print(IMatrix::TRANSPOSE);
        IMatrix* b = MatrixFactory::create_matrix(3, 3);
        b->print(IMatrix::REGULAR);
//        IMatrix* c = a + b;
//        c->print(IMatrix::REGULAR);
    }
#if 0
    // SUBS
    {
        std::cout << "\n\n************************** SUBS **********************" << "\n";
        Matrix a(3, 3, true);
        a.print(Matrix::REGULAR);
        Matrix b(3, 3, true);
        b.print(Matrix::REGULAR);
        Matrix* c = a - b;
        c->print(Matrix::REGULAR);
    }

    // MUL
    {
        std::cout << "\n\n************************** MUL **********************" << "\n";
        Matrix a(3, 3, true);
        a.print(Matrix::REGULAR);
        Matrix b(3, 3, true);
        b.print(Matrix::REGULAR);
        Matrix* c = a * b;
        if (c) {
            c->print(Matrix::REGULAR);
            std::cout << "C Size is: " << c->get_rows() << " " << c->get_cols() << std::endl;
            std::cout << "C matrix determinant is: " << c->get_determinant() << std::endl;
        }
    }

    // DIV
    {
        std::cout << "\n\n************************** DIV **********************" << "\n";
        Matrix a(4, 4, true);
        a.print(Matrix::REGULAR);
        Matrix b(4, 4, true);
        b.print(Matrix::REGULAR);
        Matrix* c = a / b;
        if (c) {
            c->print(Matrix::REGULAR);
            std::cout << "C Size is: " << c->get_rows() << " " << c->get_cols() << std::endl;
        }
        Matrix d = a;
        delete c;
        std::cout << "D Size is: " << d.get_rows() << " " << d.get_cols() << std::endl;
        d.print(Matrix::REGULAR);
    }
#endif
}


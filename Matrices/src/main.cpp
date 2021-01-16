#include <iostream>
#include "matrix.h"

int main() {
    std::cout << "Program testing matrices operations" << "\n";
    
    // SUM
//    {
//        std::cout << "************************** SUM **********************" << "\n";
//        int arr[9] = {-3,2,-5,-1,0,-2,3,-4,1};
//        Matrix a(3, 3, &arr[0]);
//        a.print(Matrix::REGULAR);
//        a.print(Matrix::TRANSPOSE);
//        Matrix b(3, 3, true);
//        b.print(Matrix::REGULAR);
//        Matrix* c = a + b;
//        c->print(Matrix::REGULAR);
//    }

//    // SUBS
//    {
//        std::cout << "\n\n************************** SUBS **********************" << "\n";
//        Matrix a(3, 3, true);
//        a.print(Matrix::REGULAR);
//        Matrix b(3, 3, true);
//        b.print(Matrix::REGULAR);
//        Matrix* c = a - b;
//        c->print(Matrix::REGULAR);
//    }

//    // MUL
//    {
//        std::cout << "\n\n************************** MUL **********************" << "\n";
//        Matrix a(3, 3, true);
//        a.print(Matrix::REGULAR);
//        Matrix b(3, 3, true);
//        b.print(Matrix::REGULAR);
//        Matrix* c = a * b;
//        if (c) {
//            c->print(Matrix::REGULAR);
//            std::cout << "C Size is: " << c->getRows() << " " << c->getCols() << std::endl;
//            std::cout << "C matrix determinant is: " << c->getDeterminant() << std::endl;
//        }
//    }

    // DIV
    {
        std::cout << "\n\n************************** DIV **********************" << "\n";
        Matrix a(4, 4, true);
        a.print(Matrix::REGULAR);
        Matrix b(4, 4, true);
        b.print(Matrix::REGULAR);
        Matrix* c = a / b;
        //if (c) {
            c->print(Matrix::REGULAR);
            std::cout << "C Size is: " << c->getRows() << " " << c->getCols() << std::endl;
        //}
        Matrix d = a;
        //delete c;
        //std::cout << "D Size is: " << d.getRows() << " " << d.getCols() << std::endl;
        //d.print(Matrix::REGULAR);
    }
    std::cout << "Hello" << std::endl;
}


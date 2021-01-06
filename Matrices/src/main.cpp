#include <iostream>
#include "matrix.h"


int* ret() {
    int* ptr = new int[4];
    int i = 0;
    ptr[i] = 0;
    ptr[i++] = 1;
    ptr[i++] = 2;
    ptr[i++] = 3;
    return ptr;
}


int main() {
    std::cout << "Program testing matrices operations" << "\n";
    
    // SUM
    {
        std::cout << "-------------SUM-------------" << "\n";
        Matrix a(3, 3, true);
        a.print(Matrix::REGULAR);
        a.print(Matrix::TRANSPOSE);
        Matrix b(3, 3, true);
        b.print(Matrix::REGULAR);
        Matrix* c = a + b;
        c->print(Matrix::REGULAR);
    }

    // SUBS
    {
        std::cout << "-------------SUBS-------------" << "\n";
        Matrix a(3, 3, true);
        a.print(Matrix::REGULAR);
        Matrix b(3, 3, true);
        b.print(Matrix::REGULAR);
        Matrix* c = a - b;
        c->print(Matrix::REGULAR);
    }

    // MUL
    {
        std::cout << "-------------MUL-------------" << "\n";
        Matrix a(1, 5, true);
        a.print(Matrix::REGULAR);
        Matrix b(5, 1, true);
        b.print(Matrix::REGULAR);
        Matrix* c = a * b;
        c->print(Matrix::REGULAR);
        std::cout << "Size is: " << c->getRows() << " " << c->getCols() << std::endl;
    }

}


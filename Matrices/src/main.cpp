#include <iostream>
#include "matrix.h"

int main() {
    std::cout << "Program testing matrices operations" << "\n";
    
    // SUM
    std::cout << "-------------SUM-------------" << "\n";
    Matrix a(3, 3, true);
    a.print();
    Matrix b(3, 3, true);
    b.print();
    Matrix* c = a + b;
    c->print();

    // SUBS
    std::cout << "-------------SUBS-------------" << "\n";

    // MUL
    std::cout << "-------------MUL-------------" << "\n";
    Matrix f(1, 5, true);
    f.print();
    Matrix g(5, 1, true);
    g.print();
    Matrix* h = f * g;
    h->print();
    std::cout << "Size is: " << h->getRows() << " " << h->getCols() << std::endl;
}

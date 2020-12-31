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

}

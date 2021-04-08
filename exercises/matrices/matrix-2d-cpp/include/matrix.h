#ifndef MATRIX_H
#define MATRIX_H

#include <map>
#include <string.h>

#include "matrix_interface.h"

namespace CustomMatrix {

class Matrix : public IMatrix {

public:

    Matrix(int rows, int cols, float** m);
    ~Matrix();                                  

    IMatrixPtr add(const IMatrixPtr& m) override;
    IMatrixPtr substract(const IMatrixPtr& m) override;
    IMatrixPtr multiply(const IMatrixPtr& m) override; 
    IMatrixPtr divide(const IMatrixPtr& m) override;
    IMatrixPtr rotate(eRotate rotation) override;

    float operator()(int row, int col) override;// interface 
    float* get_1d_raw_matrix(eMatrixType type) const override;// interface 
    float** get_2d_raw_matrix(eMatrixType type) const override;// interface 
    float get_determinant() const override;// interface 
    int get_cols() const override;// interface 
    int get_rows() const override;// interface 
    void print(eMatrixType type) const override;// interface 

private:

int _columns;
int _rows;
float** _matrix;

};

}
#endif // MATRIX_H

#include <iostream>
#include "matrix.h"
 
namespace CustomMatrix {

  Matrix::Matrix(int rows, int cols, float** m)
    {
        _rows=rows;
        _columns=cols;
        _matrix=m;

        std::cout<<"Construyendo Matrix"<<std::endl;
    }
  Matrix::~Matrix()
    {
       std::cout<<"Destruyendo Matrix"<<std::endl;
    }  
    
    IMatrixPtr Matrix::add(const IMatrixPtr& m)
    {

    if(this->_columns == m->get_cols() && this->_rows== m->get_rows())
        {

         float** C = new float* [_columns]; 

    for (int i = 0; i < _columns; i++) {
        C[i] = new float[_rows];
        for (int j = 0; j <_rows; j++) {
            C[i][j]=0;
        }
    }

                for (int i = 0; i < this->_rows; i++) {
                    for (int j = 0; j < this->_columns; j++) {
                       C[i][j] = this->_matrix[i][j] + m->get_2d_raw_matrix((eMatrixType)1)[i][j];
                    }
                }

   IMatrixPtr matrix_result = std::make_shared<Matrix>(_rows, _columns, C);
        return matrix_result;
        } 
    else
    {
        std::cout << "The Matrices cannot be sum(matrices must be square and of the same size to sum)";
        std::cout << std::endl << std::endl;
    }


    }
    IMatrixPtr Matrix::substract(const IMatrixPtr& m)  {

    }
    IMatrixPtr Matrix::multiply(const IMatrixPtr& m)  {} 
    IMatrixPtr Matrix::divide(const IMatrixPtr& m)  {}
    IMatrixPtr Matrix::rotate(eRotate rotation)  {}

    float Matrix::operator()(int row, int col){}
    float* Matrix::get_1d_raw_matrix(eMatrixType type) const {}
    float** Matrix::get_2d_raw_matrix(eMatrixType type) const {
        return _matrix;

    } 
    float Matrix::get_determinant() const {} 
    
    int Matrix::get_cols() const {
        return _columns;
    }

    int Matrix::get_rows() const {
        return _rows;
    } 
    void Matrix::print(eMatrixType type) const {}

}
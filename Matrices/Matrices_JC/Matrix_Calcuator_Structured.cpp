// Matrix_Calcuator_Structured.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "iostream"
#include "stdio.h"
#include "string"
#include "memory"
#include "cstdlib"

class Matrix {    // This typedef contain the data struct for build one matrix
public:

  /*  Matrix() {
        std::cout << "Llamando al constructor matriz" << std::endl;
    }*/
    ~Matrix() {
      //  std::cout << "Llamando al destructor matriz" << std::endl;
        for (int i = 0; i < rows; i++) {
            delete[] A[i];
           // std::cout << "Borrando 1 Reserva" << std::endl;
        }
        delete[] A;
    }

    int** A;
    int rows;
    int columns;
    char matrix_name;

};

void configure_matrix (Matrix* matrix)  
{
            do // This cycle request one number difernt to zero, while this number is equal to zero the app continue request a new number
            {
                std::cout << std::endl;
                std::cout << "The number of rows should be greater than 0 (zero)" << std::endl;
                std::cout << "How many rows will the matrix " << matrix->matrix_name << " have? ";
                std::cin >> matrix->rows;
            } while (matrix->rows == 0);
        
            do // This cycle request one number difernt to zero, while this number is equal to zero the app continue request a new number
            {
                std::cout << std::endl;
                std::cout << "The number of columns should be greater than 0 (zero)" << std::endl;
                std::cout << "How many columns will the matrix  " << matrix->matrix_name << " have? ";
                std::cin >> matrix->columns;
            } while (matrix->columns == 0);
       
}

void New_Matrix(Matrix* matrix) // This method create one matrix null, the method use all values requested by "configure_matrix"
{                                         
    matrix->A = new int* [matrix->rows];
    for (int i = 0; i < matrix->rows; i++) {
        matrix->A[i] = new int[matrix->columns];
        for (int j = 0; j < matrix->columns; j++) {
            matrix->A[i][j] = 0;
        }
    }
    
}

void Set_Matrix(Matrix* matrix, int type)
{
    if (type==2)
    { 
    std::cout << std::endl;
    for (int i = 0; i < matrix->rows; i++) {
        matrix->A[i] = new int[matrix->columns];
        for (int j = 0; j < matrix->columns; j++) {
            std::cout << "Enter the value [" << i + 1 << "][" << j + 1 << "] of the matrix " << matrix->matrix_name << ": ";
            std::cin >> matrix->A[i][j];
        }
    }
    std::cout << std::endl;
    }
    else 
    {
        for (int i = 0; i < matrix->rows; i++) {
            matrix->A[i] = new int[matrix->columns];
            for (int j = 0; j < matrix->columns; j++) 
            {
                matrix->A[i][j]= rand();
            }
        }
        std::cout << std::endl;
    }
}

Matrix* Create_Matrix(char matrix_name)
{
    int type;
    Matrix* A = new Matrix;
    A->matrix_name = matrix_name;
    configure_matrix(A);
    New_Matrix(A);
  
    do
    {
    std::cout << std::endl;
    std::cout << "How you want to input the values to the matrix:\n\n";
    std::cout <<  "1)  Random\n";
    std::cout <<  "2)  Manual\n";
    std::cin >> type;
    } while (type > 2);
   
    Set_Matrix(A, type);
    return A;
 }

void Print_Matrix (Matrix* matrix)
{
    if (matrix == NULL)
    {
        std::cout << "Verify all data\n";
    }
    else
    { 
    //std::cout << "The values of matrix " << matrix->matrix_name << " are:\n";

    for (int i = 0; i < matrix->rows; i++)
    {
        std::cout << std::endl;

        for (int j = 0; j < matrix->columns; j++)
        {
            std::cout << " " << matrix->A[i][j];
        }
    }
}
    std::cout << std::endl << std::endl;
}

void Print_Result(Matrix* matrix_A, Matrix* matrix_B, Matrix* matrix_C, char simbol_operator)
{
    std::cout << std::endl;
    Print_Matrix(matrix_A);
    std::cout << simbol_operator << std::endl;
    Print_Matrix(matrix_B);
    std::cout << "=" << std::endl;
    Print_Matrix(matrix_C);

}

Matrix* matrix_sum(Matrix* matrix_A, Matrix* matrix_B)
{ 
    if(matrix_A->columns == matrix_B->columns && matrix_A->rows == matrix_B->rows  
        && matrix_A->columns == matrix_A->rows && matrix_B->columns == matrix_B->rows)
        {
        Matrix* matrix_C = new Matrix;
        matrix_C->matrix_name = 'C';
        matrix_C->rows = matrix_A->rows;
        matrix_C->columns = matrix_A->columns;
        New_Matrix(matrix_C);  
            if (matrix_A->rows == matrix_B->rows && matrix_A->columns == matrix_B->columns)
            {
                for (int i = 0; i < matrix_A->rows; i++) {
                    for (int j = 0; j < matrix_A->columns; j++) {
                        matrix_C->A[i][j] = matrix_A->A[i][j] + matrix_B->A[i][j];
                    }
                }
            }
        Print_Result(matrix_A, matrix_B, matrix_C, '+');
        
        return matrix_C;
        } 
    else
    {
        std::cout << "The Matrices cannot be sum(matrices must be square and of the same size to sum)";
        std::cout << std::endl << std::endl;
    }
}

void matrix_substract(Matrix* matrix_A, Matrix* matrix_B)
{
    if (matrix_A->columns == matrix_B->columns && matrix_A->rows == matrix_B->rows
        && matrix_A->columns == matrix_A->rows && matrix_B->columns == matrix_B->rows)
        {
        Matrix* matrix_C = new Matrix;
        matrix_C->matrix_name = 'C';
        matrix_C->rows = matrix_A->rows;
        matrix_C->columns = matrix_A->columns;
        New_Matrix(matrix_C);
        if (matrix_A->rows == matrix_B->rows && matrix_A->columns == matrix_B->columns)
        {
            for (int i = 0; i < matrix_A->rows; i++) {
                for (int j = 0; j < matrix_A->columns; j++) {
                    matrix_C->A[i][j] = matrix_A->A[i][j] - matrix_B->A[i][j];
                }
            }
        }
        Print_Result(matrix_A, matrix_B, matrix_C, '-');
        delete matrix_C;
        }
    else
    {
        std::cout << "The Matrices cannot be subtract(matrices must be square and of the same size to substract)";
        std::cout << std::endl << std::endl;
    }
}

void matrix_product(Matrix* matrix_A, Matrix* matrix_B)
{
    if (matrix_A->columns == matrix_B->rows)
    {
        Matrix* matrix_C = new Matrix;
        matrix_C->matrix_name = 'C';
        matrix_C->rows = matrix_A->rows;
        matrix_C->columns = matrix_B->columns;
        New_Matrix(matrix_C);

        for (int k = 0; k < matrix_A->rows; k++) {

            for (int m = 0; m < matrix_B->columns; m++) {

                for (int l = 0; l < matrix_A->columns; l++) {

                    matrix_C->A[k][m] = matrix_C->A[k][m] + (matrix_A->A[k][l] * matrix_B->A[l][m]);

                }
            }
        }
        Print_Result(matrix_A, matrix_B, matrix_C, '*');
        delete matrix_C;
    }
    else
    {
        std::cout << "The Matrices are not supported for product";
        std::cout << "(the number of columns matrix A must be the same as the number of rows of matrix B)";
        std::cout << std::endl << std::endl;
    }
    
}



Matrix* Producto_escalar(Matrix* matrix_A, int num_escalar)
{

    /*Matrix_data datos_R;
    datos_R.rows = matrix_A->rows;
    datos_R.columns = matrix_A->columns;
    datos_R.matrix_name = matrix_A->matrix_name;

    Matrix* R = New_Matrix(datos_R);

    for (int i = 0; i < matrix_A->rows; i++) {
        for (int j = 0; j < matrix_A->columns; j++) {
            R->A[i][j] = matrix_A->A[i][j] * num_escalar;
        }
    }
    return R;*/
    return 0;
}



Matrix* higher_diagonal(Matrix* matrix, char name)
{
    Matrix* HigherDiagonal = new Matrix;
    HigherDiagonal->matrix_name = name;
    HigherDiagonal->rows = 1;
    HigherDiagonal->columns = matrix->columns;

    HigherDiagonal->A = new int* [HigherDiagonal->rows];
    HigherDiagonal->A[1] = new int[HigherDiagonal->columns];
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->columns; j++)
        {
            if (i = j) {
                HigherDiagonal->A[1][j] = matrix->A[i][j];
            }
        }
    }
    return HigherDiagonal;
}



void print_menu()
{
    int i = 1;
    std::cout << std::endl;
    std::cout << "What would you like to do: \n\n";
    std::cout << i++ << ")  Sum\n";
    std::cout << i++ << ")  Subtract\n";
    std::cout << i++ << ")  Product\n";
    std::cout << i++ << ")  Division\n";
    //std::cout << i++ << ")  Create one Matrix Null\n";
    //std::cout << i++ << ")  Find the Main diagonal\n";
    //std::cout << i++ << ")  Find the Major diagonal\n";
    //std::cout << i++ << ")  Find the Minior diagonal\n";
    //std::cout << i++ << ")  Find the Traza of Matrix\n";
    //std::cout << i++ << ")  Find the Transpose Matrix \n";
    //std::cout << i++ << ")  Product by a scalar\n";
    // std::cout << i++ << ")  \n";
    std::cout << i++ << ") Show menu\n";
    std::cout << i++ << ") Finish the program\n";
    std::cout << std::endl;
}


int main()
{
    int option;

    std::cout << "Welcome to work with Matrix \n";
    std::cout << "Please capture the next data\n";

    do
    {
        Matrix* A = Create_Matrix('A');
        //Print_Matrix(A);
        Matrix* B = Create_Matrix('B');
        //Print_Matrix(B);
        
        Matrix* C = NULL;

        print_menu();
        std::cin >> option;
        switch (option)
        {
        case 1: //Sum Matrix
        {
            C = matrix_sum(A, B); 

        }
        break;

        case 2: //Substract Matrix
        {
            matrix_substract(A, B);
        }
        break;

        case 3: //Prodcut Matrix
        {
            matrix_product(A, B);
        }
        break; 

        case 4: //Division Matrix
            break;
        case 6: print_menu();
            break;
        case 7: std::cout << "Thanks for working with Matrices ";
            break;

        default: std::cout << "Enter a valid value from menu";
        }
        delete A;
        A = NULL;
        delete B;
        B = NULL;
        delete C;
        C = NULL;
    } while (option != 7);

    system("pause");
    return 0;
}

#include <json/json.h>
#include <fstream>
#include <iostream>
#include <vector>

#define  GOLDEN_MODEL_JSON_PATH  "/media/ramsesrago/Shared/Development/study/exercises/matrices/matrix-1d-cpp/test/golden-model-py/golden_matrices.json"
//#define  GOLDEN_MODEL_JSON_PATH  "/media/ramsesrago/Shared/Development/study/exercises/matrices/matrix-1d-cpp/test/golden-model-py/simple_file.json"

struct JsonMatrixWrapper {
    JsonMatrixWrapper(int rows, int cols) : _rows(rows), _cols(cols) {
        json1DMatrix = new float[rows*cols];
    }
    ~JsonMatrixWrapper() {
        delete[] json1DMatrix;
    }
    void setJsonMatrix(Json::Value jsonMatrix) {
        //sonRegularMatrix
        for(int i = 0, index = 0; i < _rows ; i++){
            for(int j = 0; j < _cols ; j++) {
                json1DMatrix[index] = jsonMatrix[i][j].asFloat();
                ++index;
            }
        }
    }

    void printJsonMatrix() {
        for(int i = 0; i < _rows*_cols ; i++) {
            std::cout << "Matrix element: " << json1DMatrix[i] << std::endl;
        }
    }

    int _rows;
    int _cols;
    float*  json1DMatrix;
//    float** json2DMatrix;
};

int main() {
    Json::Value jsonRoot;

    // Read file Json database
    std::string filename (GOLDEN_MODEL_JSON_PATH);
    std::ifstream config_doc(filename.c_str(), std::ifstream::binary);
    config_doc >> jsonRoot;
    // Printing the whole json file
    std::cout << jsonRoot.toStyledString() << std::endl;

    // Printing 2x2 json matrix
    std::cout << "Matrix: " << jsonRoot["input"]["A"]["2x2"]["matrix"].toStyledString() << std::endl;
    // Printing determinant value
    std::cout << "Determinant: " << jsonRoot["input"]["A"]["2x2"]["ops"]["DET"].asFloat() << std::endl;
    // Convert json matrix to standard 2d matrix
    Json::Value matrix = jsonRoot["input"]["A"]["2x2"]["matrix"];
    int rows = matrix.size();
    int cols = matrix[0].size();
    std::cout << "Size of json matrix is: " << rows << "x" << cols << std::endl;
    // Printing array elements
    std::cout << "Element is: " << matrix[0][0] << std::endl;
    std::cout << "Element is: " << matrix[0][1] << std::endl;
    std::cout << "Element is: " << matrix[1][0] << std::endl;
    std::cout << "Element is: " << matrix[1][1] << std::endl;
    std::cout << "Element is: " << matrix[1] << std::endl;

    JsonMatrixWrapper jsonWrapper(rows, cols);
    jsonWrapper.setJsonMatrix(matrix);
    jsonWrapper.printJsonMatrix();

    return EXIT_SUCCESS;
}

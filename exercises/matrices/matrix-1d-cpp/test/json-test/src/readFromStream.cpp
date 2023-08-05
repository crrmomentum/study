#include <json/json.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

#define  GOLDEN_MODEL_JSON_PATH  "/media/ramsesrago/Shared/Development/study/exercises/matrices/matrix-1d-cpp/test/golden-model-py/golden_matrices.json"
//#define  GOLDEN_MODEL_JSON_PATH  "/media/ramsesrago/Shared/Development/study/exercises/matrices/matrix-1d-cpp/test/golden-model-py/simple_file.json"

class JsonMatrixWrapper {
public:
    JsonMatrixWrapper(int rows, int cols) : _rows(rows), _cols(cols) {
        _json_1d_matrix = new float[rows*cols];
    }

    ~JsonMatrixWrapper() {
        delete[] _json_1d_matrix;
    }

    JsonMatrixWrapper& operator=(const JsonMatrixWrapper& json) {
        return *this;
    }

    void setJsonMatrix(Json::Value jsonMatrix) {
        //sonRegularMatrix
        for(int i = 0, index = 0; i < _rows ; i++){
            for(int j = 0; j < _cols ; j++) {
                _json_1d_matrix[index] = jsonMatrix[i][j].asFloat();
                ++index;
            }
        }
    }

    void printJsonMatrix() {
        for(int i = 0; i < _rows*_cols ; i++) {
            std::cout << "Matrix element: " << _json_1d_matrix[i] << std::endl;
        }
    }

    float* getJsonMatrix() const {
        // ToDo: If JsonMatrixWrapper goes of of scope then the internal matrix will go out of scope too
        return _json_1d_matrix;
    }

private:
    float* _json_1d_matrix;
    float* _json_1d_matrix_transpose;
    float* _json_1d_matrix_adj;
    float* _json_1d_matrix_inv;
    float* _json_1d_matrix_cofactor;
    float _json_1d_det;
    int _rows;
    int _cols;
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
    // Printing A array size
    std::cout << "A isArray: " << jsonRoot["input"]["A"].isArray() << std::endl;
    std::cout << "A array size: " << jsonRoot["input"]["A"].size() << std::endl;
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

    auto jsonMatrixWrapperVectorA = std::vector<JsonMatrixWrapper>{}; // Contains all A matrices
    auto jsonMatrixWrapperVectorB = std::vector<JsonMatrixWrapper>{}; // Contains all B matrices
    auto jsonMatrixWrapperVectorC = std::vector<JsonMatrixWrapper>{}; // Contains all C matrices

    std::cout << "iterator value is: " << (*(++jsonRoot["input"]["A"].begin()))["matrix"].toStyledString() << std::endl;

    auto lambda = [](Json::Value jsonElement){
        std::cout << "Hello" << std::endl;
        //std::cout << "Lambda Element is: " << jsonElement["matrix"].toStyledString() << std::endl;
        //jsonElement["matrix"];
        //rows = matrix.size();
        //cols = matrix[0].size();
        //JsonMatrixWrapper jsonWrapper(rows, cols);
        //jsonMatrixWrapperVectorA.push_back();
    };

//    // Transform all json matrices into C++ regular objects containing all information from the matrices database
    std::transform(jsonRoot["input"]["A"].begin(), jsonRoot["input"]["A"].end(),
                    std::back_inserter(jsonMatrixWrapperVectorA),
            [](Json::Value jsonElement){});
//    for (int i = 0; i <= jsonRoot["input"]["A"].size(); ++i) {

//    }

    return EXIT_SUCCESS;
}

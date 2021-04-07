#ifndef JSON_MATRIX_PARSER_H
#define JSON_MATRIX_PARSER_H

#include <json/json.h>
#include <fstream>
#include <iostream>
#include <vector>

class JsonMatrixParser {

    public:
    JsonMatrixParser(int rows, int cols);
    ~JsonMatrixParser();

    void setJsonMatrix(Json::Value jsonMatrix);
    void printJsonMatrix();

    int _rows;
    int _cols;
    float*  json1DMatrix;
//    float** json2DMatrix;
};

#endif // JSON_MATRIX_PARSER_H
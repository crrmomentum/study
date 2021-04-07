JsonMatrixParser::JsonMatrixParser(int rows, int cols) : _rows(rows), _cols(cols)
{
    std::cout << "Constructing JsonMatrixParser" << std::endl;
    json1DMatrix = new float[rows * cols];
}

JsonMatrixWrapper::~JsonMatrixWrapper()
{
    delete[] json1DMatrix;
}

void JsonMatrixWrapper::setJsonMatrix(Json::Value jsonMatrix)
{
    //sonRegularMatrix
    for (int i = 0, index = 0; i < _rows; i++)
    {
        for (int j = 0; j < _cols; j++)
        {
            json1DMatrix[index] = jsonMatrix[i][j].asFloat();
            ++index;
        }
    }
}

void JsonMatrixWrapper::printJsonMatrix()
{
    for (int i = 0; i < _rows * _cols; i++)
    {
        std::cout << "Json Matrix element: " << json1DMatrix[i] << std::endl;
    }
}
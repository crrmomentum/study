#include <json/json.h>
#include <fstream>
#include <iostream>

#define  GOLDEN_MODEL_JSON_PATH  "/media/ramsesrago/Shared/Development/study/exercises/matrices/matrix-1d-cpp/test/golden-model-py/golden_matrices.json"
//#define  GOLDEN_MODEL_JSON_PATH  "/media/ramsesrago/Shared/Development/study/exercises/matrices/matrix-1d-cpp/test/golden-model-py/simple_file.json"

int main() {
    Json::Value jsonRoot;

    // Read file and overwrite Json database
    std::string filename (GOLDEN_MODEL_JSON_PATH);
    std::ifstream config_doc(filename.c_str(), std::ifstream::binary);
    //std::ifstream config_doc(filename.c_str());
    config_doc >> jsonRoot;
//    std::cout << jsonRoot["encoding"].asString() << std::endl;
//    std::cout << jsonRoot["test"].asString() << std::endl;
    std::cout << jsonRoot.toStyledString() << std::endl;

    return EXIT_SUCCESS;
}

//
// Created by gmook on 4/7/2021.
//

#ifndef P3P2_JSONTOKENIZER_HPP
#define P3P2_JSONTOKENIZER_HPP


#include <string>
#include "JSONToken.hpp"
#include <fstream>

class JSONTokenizer {
public:
    JSONTokenizer(std::string);
    JSONToken getToken();

private:
    std::string inputFileName;
    std::ifstream inputStream; //declare input-stream variable
};

#endif //P3P2_JSONTOKENIZER_HPP

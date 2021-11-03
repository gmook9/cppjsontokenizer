//
// Created by gmook on 4/7/2021.
//

#ifndef P3P2_JSONPARSER_HPP
#define P3P2_JSONPARSER_HPP

#include <string>
#include <iostream>
#include "EntityInstance.hpp"
#include "JSONTokenizer.hpp"
#include "EntitySet.hpp"

class JSONParser {
public:
    JSONParser(JSONTokenizer &tokenizer);
    Pair parseAPair();
    EntityInstance parseJSONObject();
    EntitySet parseJSONEntity();

private:
    JSONTokenizer &tokenizer;
    std::vector<std::pair<std::string,double>> currentMatrix;
};


#endif //P3P2_JSONPARSER_HPP

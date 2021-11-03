//
// Created by gmook on 4/7/2021.
//

#ifndef P3P2_PAIR_HPP
#define P3P2_PAIR_HPP

#include <string>

class Pair { // represents a single attribute and its value:

public:
    Pair();
    // use the first constructor if the value of the pair is a string
    // and use the second one if it is a double value.
    Pair(std::string attributeName, std::string attributeValue);
    Pair(std::string attributeName, double c);
    bool &isDouble();
    void print();
    void print(int numSpaces, bool addComma);
    std::string locateId();
    void setterForId(bool boolId);
    bool foundTheId();
    double locateGpa();

private:
    std::string _attributeName, _attributeStringValue;
    double _attributeNumberValue;
    bool _isNumber, idSearch;
};


#endif //P3P2_PAIR_HPP

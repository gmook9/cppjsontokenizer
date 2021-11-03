//
// Created by gmook on 4/2/2021.
//

#include <vector>
#include <iostream>
#include <iomanip>
#include "Pair.hpp"

//Constructor
Pair::Pair():
        _attributeName{""},
        _attributeStringValue{""},
        _attributeNumberValue{0},
        _isNumber{false}
{}

//Constructor
Pair::Pair(std::string attributeName, double c){
    _attributeName = attributeName;
    _attributeNumberValue = c;
    _isNumber = true;
}

//Constructor
Pair::Pair(std::string attributeName, std::string attributeValue){
    _attributeName = attributeName;
    _attributeStringValue = attributeValue;
    _isNumber = false;
}


bool &Pair::isDouble() {
    return _isNumber;
}


void Pair::print(int numSpaces, bool addComma) {
    std::cout << std::setw(numSpaces) << "\"" << _attributeName << "\" : ";
    if(isDouble()) {
        std::cout << _attributeNumberValue;
    } else {
        std::cout << "\"" << _attributeStringValue << "\"";
    }
    if(addComma) {
        std::cout << "," << std::endl;
    } else
        std::cout << std::endl;
}

// Function that will return _attributeStringValue to the entityInstance class
std::string Pair::locateId() {
    // Simply check if a string "id" is found
    if (_attributeName == "id") {
        // If found set a boolean flag to be TRUE
        setterForId(true);
        // Then simply return the ID that was found
        return _attributeStringValue;
    }
    else {
        // Otherwise, set the boolean flag to be FALSE
        // meaning no ID was found.
        setterForId(false);
        // Since its not a VOID function datatype we must
        // return something therefore we simply return N/A
        // meaning no applicable ID was found
        return "N/A";
    }
}

void Pair::setterForId(bool boolId) {
    idSearch = boolId;
}

bool Pair::foundTheId() {
    return idSearch;
}

// This function is used by the entityInstance class in order to grab the GPA
double Pair::locateGpa() {
    // If double (meaning if a GPA) then simply return that number
    if(isDouble()) {
        return _attributeNumberValue;
    }
    // Otherwise, no GPA has been found. So just return 0.
    // This is a area in which a error message can be placed
    // or customized because GPA should be found.
    else {
        return 0;
    }
}
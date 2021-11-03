//
// Created by gmook on 4/2/2021.
//

#include "EntityInstance.hpp"
#include <iostream>
#include <iomanip>


void EntityInstance::print(int numSpaces, bool addComma) {
    // Printing a instance within a set
    // Instance is represented by { }
    std::cout  << std::setw(numSpaces-1) << "{" << std::endl;
    for (int i = 0; i < numAttributes(); i++) {
        // Create a variable that represents the last element
        int last = numAttributes() - 1;
        // Check if we are at the last attribute with a IF
        if (i == last) {
            // If we are at the last attribute then do not add a comma
            // we do this by setting addComma to false by passing it
            // with the print function call
            entityPairs.at(i).print(7, false);
        } else {
            // However, if we are not at the last attribute
            // add a comma by passing true with the print function call
            entityPairs.at(i).print(7, true);
        }
    }
        if(addComma) {
            // If the addComma boolean flag is set to true
            // then we simply add a comma to the end of }
            std::cout << std::setw(numSpaces) << "}," << std::endl;
        }
            else {
                // If the boolean addComma flag is set to false then remember
                // the comma takes up a extra space when printing. Since not adding comma
                // be sure to setw to setw(numSpaces - 1) in order to have
                // the correct alignment
            std::cout << std::setw(numSpaces - 1) << "}" << std::endl;
        }

}

// Function of STRING datatype because it is used to
// return a ID which is off STRING datatype
std::string EntityInstance::locateId() {
    //********
    // This functions will be similar to the locateGpa() function
    // because they both same the same goal, however, instead of a double(GPA)
    // this function will retrieve and return a string(ID).
    //********
    // Start by creating a variable of string datatype that can hold
    // the retrieved IDs
    std::string locateId;
    // Create a loop that goes over each element in the entityPairs vector
    for(int i = 0; i < entityPairs.size(); i++) {
        // Set the string we just created equal to a function from
        // the Pair class called locateId(). locateId() will
        // return _attributeStringValue when a previous token "ID" is found
        locateId = entityPairs.at(i).locateId();
        // We create a boolean in the Pair class called foundTheId() this acts
        // as a flag so we know when we locate a valid ID. If we find a valid ID using
        // the Pair class function locateID() then the flag foundTheId() becomes true.
        // Next, we simply set a test to say if(we found a ID from Pair) then break out of the loop
        if(entityPairs.at(i).foundTheId())
            break;
    }
    // Once broken out of the loop simply return the _attributeStringValue that was found and
    // set equal to locateId
    return locateId;
}


void EntityInstance::addPair(Pair &pair) {
    entityPairs.push_back(pair);
}

int EntityInstance::numAttributes() {
    return entityPairs.size();
}

// Function of DOUBLE datatype because we want to return a GPA
// which is of DOUBLE datatype
double EntityInstance::locateGpa() {
    // create a variable of double datatype to hold GPAs
    double locateGpa;
    // Next create a loop that can through through all pairs in the
    // entityPairs vector
    for (int i = 0; i < entityPairs.size(); i++) {
        // locateGpa() is a function inside of the Pair class
        // when it is called on it will return the _attributeNumberValue
        // at the selected pair
        locateGpa = entityPairs.at(i).locateGpa();
        // If the GPA is retrieved successfully, meaning its not 0
        //  then we simply break out of the loop and return
        // the retrieved GPA
        if (locateGpa != 0)
            break;
    }
    // return the GPA > 0 that we just pulled from the Pair class
    return locateGpa;
}


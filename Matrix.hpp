//
// Created by gmook on 4/08/2021.
//

#ifndef P3P2_MATRIX_HPP
#define P3P2_MATRIX_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Matrix {
public:
    //Constructor
    Matrix(std::vector<std::pair<std::string, double>>, std::vector<std::pair<std::string, double>>);
    //Operations that we perform on the datatype
    void generateColumn(int selectedRow);
    void getGpa();
    void print();
    void checkAndPrint();
private:
    double preSelectGpa;
    double selectGpa;
    int createMatrix[8][8];
    // **********INFO ON THE DATA STRUCTURES WE NEED TO SUPPORT PUBLIC OPERATIONS*************
    // In order to keep track of 2 documents data and then store a subset of
    // data from the documents 3 Vectors are needed.
    // 1. Vector for ID AND GPA of DOC 1
    //      1a. This vector stores a pair of all IDs and GPAs from DOC 1
    // 2. Vector for ID and GPA of DOC 2
    //      2a. This vector stores a pair of all IDs and GPAs from DOC 2
    // 3. Vector for just GPAs of DOC 1 AND 2 that have if matching ID in both DOCs.
    //      3a. If a ID exists in DOC 1 and DOC 2 then GRAB just the GPA of the
    //          ones that match.
    // ***************************************************************************************
    // 1. Create a vector that holds ID and GPA for the first file
    std::vector<std::pair<std::string, double>> matrixPreSelect;
    // 2. Create a vector that holds ID and GPA for the second file
    std::vector<std::pair<std::string, double>> matrixSelect;
    // 3. Vector containing pairs of doubles to hold GPAs of matching IDs.
    std::vector<std::pair<double, double>> vecForGpa;
};


#endif //P3P2_MATRIX_HPP

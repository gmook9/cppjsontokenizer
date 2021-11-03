//
// Created by gmook on 3/14/2021.
//

#include <iostream>
#include "JSONTokenizer.hpp"
#include "JSONParser.hpp"
#include "Matrix.hpp"

int main(int argc, char *argv[]) {
    std::ifstream inputStream;
    inputStream.open(argv[1], std::ios::in);    // open for reading
    if (!inputStream.is_open()) {
        std::cout << "Unable to open " << argv[1] << ". Terminating...";
        exit(2);
    }
    inputStream.close();

    //***NOTE FOR PROF***
    // Please grade phase 2 AND 3, confirmed via README.
    // IN ORDER TO GRADE PHASE 2, SIMPLY CHANGE
    // testPhase2 to TRUE.
    // THANK YOU.
    //*******************
    int testPhase2 = false;
    if( testPhase2 ) {
        JSONTokenizer jsonTokenizer(argv[1]);
        JSONParser parser(jsonTokenizer);
        EntitySet createSet = parser.parseJSONEntity();
        createSet.print();
    } else {

        //****FOR FILE 1****
        //Create a instance of Tokenizer that opens file 1
        JSONTokenizer jsonTokenizerPreSelect(argv[1]);
        JSONToken token;
        JSONParser parserPreSelect(jsonTokenizerPreSelect);
        EntitySet setPreSelect;
        EntityInstance instancePreSelect;
        setPreSelect = parserPreSelect.parseJSONEntity();
        // Populate matrixPreSelect. This is NOT a matrix but a vector
        // This creates a vector of pairs from the first document
        // that each element is in the form (ID, GPA)
        std::vector<std::pair<std::string, double>> matrixPreSelect = setPreSelect.getterForMatrix();
        //*****************

        //****FOR FILE 2****
        // Create a instance of Tokenizer that opens file 2
        JSONTokenizer jsonTokenizerSelect(argv[2]);
        JSONToken tokenSelect;
        JSONParser parserSelect(jsonTokenizerSelect);
        EntitySet setSelect;
        EntityInstance instanceSelect;
        setSelect = parserSelect.parseJSONEntity();
        // Populate matrixSelect. This is NOT a matrix but a vector
        // This creates a vector of pairs from the second document
        // that each element is in the form (ID, GPA)
        std::vector<std::pair<std::string, double>> matrixSelect = setSelect.getterForMatrix();
        //*****************

        // Next we create a object of Matrix class that stores the resultant vectors
        // this allows us to pass them into functions from the Matrix class
        // a period is used to access these functions as usual
        Matrix currentMatrix(matrixPreSelect,matrixSelect);
        // The getGpa() functions is very important. It is used to
        // create a vector of GPA pairs from document 1 and document 2.
        currentMatrix.getGpa();
        // The checkAndPrint() function itself also calls on the generateColumn() function
        // in order to create the populated matrix.
        currentMatrix.checkAndPrint();
    }
    return 0;
}
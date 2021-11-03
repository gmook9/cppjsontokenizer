//
// Created by gmook on 4/08/2021.
//

#include <iomanip>
#include "Matrix.hpp"

//Constructor/Initializer
Matrix::Matrix(std::vector<std::pair<std::string, double>> theMatrixPreSelect, std::vector<std::pair<std::string, double>> theMatrixSelect) :
matrixPreSelect(theMatrixPreSelect),matrixSelect(theMatrixSelect) {
    //Nested FOR loop. One for [i] and one for [j] in the matrix
    //ROWS
    for (int i = 0; i < 8; i++) {
        //COLUMNS
        for (int k = 0; k < 8; k++) {
            // Initialize every thing in ROWS and COLUMNS to be a value of 0.
            // This creates a 8 x 8 matrix that looks like:
            //[
            //   [0,0,0,0,0,0,0,0],
            //   [0,0,0,0,0,0,0,0],
            //   [0,0,0,0,0,0,0,0],
            //   [0,0,0,0,0,0,0,0],
            //   [0,0,0,0,0,0,0,0],
            //   [0,0,0,0,0,0,0,0],
            //   [0,0,0,0,0,0,0,0],
            //   [0,0,0,0,0,0,0,0]
            //]
           createMatrix[i][k] = 0;
        }
    }
}

void Matrix::print() {
    std::cout << "[" << std::endl;

    //Nested FOR loop. One for [i] and one for [j] in the matrix
    //ROWS
    for (int i = 0; i < 8; i++) {
        std::cout << std::setw(3) << "[";
        //COLUMNS
        for (int k = 0; k < 8; k++) {
            std::cout << createMatrix[i][k];
            if (k != 7) {
                std::cout << ", ";
            }
            // This else if is responsible for printing the caps
            // if we are at the last element in a row BUT we are
            // not on the last row. Then we can print a ] with a ,
            else if (k == 7 && i != 7 ) {
                std::cout << "],";
            }
            // However, if we are at the last element AND the last
            // row. Then we want to cap the entire matrix with a ]
            // without a ,
            else if (k == 7 && i == 7 ) {
                std::cout << "]";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "]";
}


void Matrix::getGpa() {
    // TWO for loops
    // One for the first vector
    // The second is for the second vector
    for(int i = 0; i < matrixPreSelect.size(); i++) {
        for (int k = 0; k < matrixSelect.size(); k++) {
            // Then we use a if statement to check a comparison between both vectors IDs
            // We are saying IF the ID on one vector matches the ID on another vector
            if (matrixPreSelect[i].first == matrixSelect[k].first) {
                //****HOW IT WORKS****
                // The vectors exist as:
                //  std::vector<std::pair<std::string, double>> matrixSelect;
                //  and
                //  std::vector<std::pair<std::string, double>> matrixPreSelect;
                //  This means that each vector contains elements which exist of a ID and GPA pair.
                //  .first refers to the ID and .second refers to the GPA
                //  Therefore, if the ID's match then we want to make a pair of the GPA in each vector.
                //  we due this by using .second to access the GPA of each vector and use std::make_pair
                //  to make the pair
                //********************
                vecForGpa.push_back(std::make_pair(matrixPreSelect[i].second,matrixSelect[k].second));
            }
        }
    }
}


void Matrix::generateColumn(int selectedRow) {
    //****HOW IT WORKS****
    // This function is called by checkAndPrint(). Therefore, it gets called
    // many times because of the FOR loop in checkAndPrint()  --> for (int i = 0; i < sizeOfVec; i++) <--
    // It It adds a plus 1 to where the GPAs fit
    //********************
    //******EXAMPLE*******
    // When selectGpa = 4 and preSelectGpa = 4 then it hits on
    // the first if statement and runs:
    //        if (selectGpa > 3.67)
    //              createMatrix[0][selectedRow]++;
    // Then we add a plus 1 to the location that was found via the function
    //[
    //   [1,0,0,0,0,0,0,0],
    //   [0,0,0,0,0,0,0,0],
    //   [0,0,0,0,0,0,0,0],
    //   [0,0,0,0,0,0,0,0],
    //   [0,0,0,0,0,0,0,0],
    //   [0,0,0,0,0,0,0,0],
    //   [0,0,0,0,0,0,0,0],
    //   [0,0,0,0,0,0,0,0]
    //]
    // That is how the first insertion works. From there it just keeps counting
    // and repeating via the functions generateColumn(int selectedRow) and checkAndPrint()
    //********************
    if (selectGpa > 3.67)
        createMatrix[0][selectedRow]++;
    else if (selectGpa > 3.3)
        createMatrix[1][selectedRow]++;
    else if (selectGpa > 3.0)
        createMatrix[2][selectedRow]++;
    else if (selectGpa > 2.67)
        createMatrix[3][selectedRow]++;
    else if (selectGpa > 2.3)
        createMatrix[4][selectedRow]++;
    else if (selectGpa > 2.0)
        createMatrix[5][selectedRow]++;
    else if (selectGpa > 1.67)
        createMatrix[6][selectedRow]++;
    else if (selectGpa >= 0)
        createMatrix[7][selectedRow]++;
}

void Matrix::checkAndPrint() {
    // The first IF statement was used for debugging, however,
    // it works as a great checker to make sure the data is
    // being read properly therefore it stays in the code.
    // It does NOT affect the program. It simply catches if data
    // if not inputted correctly.
    if (vecForGpa.size() == 0) {
        std::cout << "EXITING: Vector is NOT being populated" ;
        exit(1);
    }
    int sizeOfVec = vecForGpa.size();
    // Create a FOR loop that goes over the entire
    // vector of GPAs. This vector is a vector of pairs of doubles.
    // It pairs up GPA in both files with a common ID. That is why it is important
    // to us here.
    for (int i = 0; i < sizeOfVec; i++) {
        //****HOW IT WORKS****
        // Since the vector is std::vector<std::pair<double, double>> vecForGpa
        // It is known that each element in the vector is really a pair that
        // contains two elements inside of it.
        //********************
        // First GPA of the pair. This the GPA from document 1
        preSelectGpa = vecForGpa.at(i).first;
        //Second GPA of the pair. Same vector, however, this the GPA from document 2.
        selectGpa = vecForGpa.at(i).second;
        //******EXAMPLE******
        // Example: at i = 2
        // preSelectGpa = 3.53333...
        // selectGPA = 3.66000...
        // Both have "id" : "MDcwNDAwMTYyOTQ2Mzg3NzYx"
        // However preSelectGpa is from "term" : "2187"
        // and selectGPA is from "term" : "2193"
        //*******************
        if (preSelectGpa > 3.67)
            generateColumn(0);
        else if (preSelectGpa > 3.3)
            generateColumn(1);
        else if (preSelectGpa > 3.0)
            generateColumn(2);
        else if (preSelectGpa > 2.67)
            generateColumn(3);
        else if (preSelectGpa > 2.3)
            generateColumn(4);
        else if (preSelectGpa > 2.0)
            generateColumn(5);
        else if (preSelectGpa > 1.67)
            generateColumn(6);
        else if (preSelectGpa >= 0)
            generateColumn(7);
    }
    print();
}


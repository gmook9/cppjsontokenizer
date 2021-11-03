//
// Created by gmook on 3/14/2021.
//

#include "JSONTokenizer.hpp"

//READER/LEXICAL ANALYZER


#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <ctype.h>

//Initializer List
JSONTokenizer::JSONTokenizer(std::string name):
        inputFileName{name} {
    inputStream.open(inputFileName, std::ios::in);  // open the input file. We will make sure that it is open in getToken.
}

JSONToken JSONTokenizer::getToken() {
    char c;
    JSONToken jsonToken;
    //Checks to see if the file we are trying to read is open
    if( ! inputStream.is_open()) {
        std::cout << "getToken called with a stream that is not open." << std::endl;
        std::cout << "Make sure that " << inputFileName << " exists and is readable. Terminating.";
        exit(2);
    }
    //This allows us to starting reading in once getToken is called from main.cpp
    // Without this line of code below the entire getToken function would not work
    // because it needs a way of continuing to read everytime its called again
    inputStream >> c;

    if( inputStream.eof() ) {
        jsonToken.endOfFile() = true;
    }
//If this statement is NOT here to check for the END of file then a extra unknown token is given at the end after all
// input has been read. In order to fix this, we check to make sure we are not at the end of the file before
// starting to look for anymore tokens. This fix does not add any complications to the program and works well.
    if (inputStream.eof() != true) {
        //Next, we create if, and else if statements. For each type of token we are trying to detect we need
        // to have a case.
        if (c == ':') {
            jsonToken.createColonJsonToken();
        } else if (c == '{') {
            jsonToken.createOpenCurlyJsonToken();
        } else if (c == '}') {
            jsonToken.createClosedCurlyJsonToken();
        } else if (c == ',') {
            jsonToken.createCommaJsonToken();
        } else if (c == '[') {
            jsonToken.createOpenSquareBracketJsonToken();
        } else if (c == ']') {
            jsonToken.createClosedSquareBracketJsonToken();
        } else if (isdigit(c)) {
            //If a DIGIT is found that means we have arrived at a GPA
            //We store TERM and ID as Strings
            // therefore, we do not need to represent anything but GPA here
            // since the numbers from TERM are stored as a string not a double

            //Start by putting back the first digit we just read
            inputStream.putback(c);
            //Create a variable of double datatype that can hold
            // what the entire list of numbers we are about to store
            double curGpa;
            //Then read into the double using >>
            inputStream >> curGpa;
            //Finally, create a token out of the double we just created
            jsonToken.createGPAJsonToken(curGpa);
        } else if (c == '"') {
            //NOTE: We DO NOT use >> here to read from the inputStream because this will grab use everything
            //including the " at the end which we DO NOT WANT
            //When we find a " that means it is about to contain a set of letters or letters and numbers
            // Therefore, when we find a " we create a string to store what we are going to find
            // also we create a variable of CHAR datatype that exists as the c that comes next
            // here the c that comes next is represented as the runnerC
            std::string quoted;
            char runnerC;
            //Since we have detected " we know that it will start off with a letter or number so
            // we start by getting the next available char and reading it into runnerC
            inputStream.get(runnerC);
            //We want to create a loop that does not stop
            // while we are still getting letters or numbers, as detected by isalnum()
            while (isalnum(runnerC)) {
                //We have are string that we created a couple lines above
                // we want to add each letter or number to the string
                quoted += runnerC;
                //After adding the letter or number just found
                // into the string we want to read the next char
                // using inputStream.get(runnerC) and then restart
                // the while loop to check if it should be stored
                inputStream.get(runnerC);
            }
            //The while loop is exited when it no longer detects a letter or a number
            // which means when it finds the next " to end on the loop ends. Thus it does
            // not add the final " to the string because of how the while loop it setup

            //Next, we create a token of the string that was just found
            //This string was created by adding CHARs to it and is represented as 'quoted'
            jsonToken.createFetchQuotedString(quoted);
        } else {
            //We only run the else statement if we do not recognize something in the JSON file
            //because we have built a tokenizer to read every single input
            //there should not be a unknown character unless it is a invalid JSON character
            std::cout << "Unknown Character: " << c;
            jsonToken.createUnknownToken();
            exit(1);
        }
    }


    return jsonToken;
}

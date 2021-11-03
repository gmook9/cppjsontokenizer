//
// Created by gmook on 4/7/2021.
//

#ifndef P3P2_JSONTOKEN_HPP
#define P3P2_JSONTOKEN_HPP

#include <string>

class JSONToken {
public:
    //Default Constructor
    JSONToken();
    //We want to return a string when we fetch the stuff inside of quotes
    //Therefore we must set out fetchQuotedString() function to be of string datatype
    std::string fetchQuotedString();
    //Because we have floating-point values (decimal values) we must use a datatype of double for setting our GPA function
    // due to the fact we want to return a decimal, therefore, we are returning a double in grabGPA()
    double grabGPA();

    //****NOTE ABOUT USE OF REFERENCES****
    //Passing by reference allows for modification
    // of the local variables that are inside caller function while
    // keeping memory allocation to a minimum
    //*************************************
    //The variables these functions return are initialized as FALSE
    //These functions are used to return the BOOLEAN value of the private variables down below in private:
    //These functions act as a getter. Hence why a reference is okay because we are getting a address.
    bool &boolCreateClosedSquareBracketJsonToken();
    bool &boolCreateOpenSquareBracketJsonToken();
    bool &boolCreateCommaJsonToken();
    bool &boolCreateClosedCurlyJsonToken();
    bool &boolCreateOpenCurlyJsonToken();
    bool &boolCreateColonJsonToken();
    bool &endOfFile();
    bool &gpaF();
    bool &notToken();
    bool &retrieveString();

    //These functions act as the setter. They are used to set the BOOLEAN value
    // of the private variables down below in private:
    void createUnknownToken();
    void createFetchQuotedString(std::string quoted);
    void createGPAJsonToken(double curGpa);
    void createClosedSquareBracketJsonToken();
    void createOpenSquareBracketJsonToken();
    void createCommaJsonToken();
    void createClosedCurlyJsonToken();
    void createOpenCurlyJsonToken();
    void createColonJsonToken();

    //Print function is used to print out all the tokens that were found
    void print();

//These private variables are in use by the GETTER and SETTER functions
private:
    //Our SETTER functions (void) above are used to set the value of these variables below

    //Booleans will be used to determine if a certain type of token is found
    bool _gpa, _quotedJsonString, _colon, _openCurly, _closedCurly, _comma, _openSquare, _closedSquare, _unknown, _eof;

    //When something inside quotes is detected we created a token of datatype string.
    //Note: in createFetchQuotedString(std::string quoted) we set fetchQuoted = quoted
    std::string fetchQuoted;
    //when a GPA token is created it is created of datatype double
    //Note in createGPAJsonToken(double curGpa) we set cureGPa = gpa
    double gpa;
};




#endif //P3P2_JSONTOKEN_HPP

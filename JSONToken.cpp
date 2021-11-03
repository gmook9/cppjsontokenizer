//
// Created by gmook on 3/14/2021.
//

#include "JSONToken.hpp"
#include <iostream>

//Initializer List
//Initialize everything to false, set GPA to 0 which
// represents NULL in this case, and set the string(fetchQuoted) to be empty.
// This way when we find reach a statement that makes one of these TRUE we update it
// but we do not want it to be TRUE until be find it, therefore, start out as FALSE.
JSONToken::JSONToken():
        _gpa{false},
        _quotedJsonString{false},
        _colon{false},
        _openCurly{false},
        _closedCurly{false},
        _comma{false},
        _openSquare{false},
        _closedSquare{false},
        _unknown{false},
        _eof{false},
        gpa{0},
        fetchQuoted{""}
{}

//GETTER Functions
//These functions are used to return the BOOLEAN value of the private variables from JSONToken.hpp
bool &JSONToken::endOfFile() { return _eof; }
bool &JSONToken::boolCreateClosedSquareBracketJsonToken() { return _closedSquare; }
bool &JSONToken::boolCreateOpenSquareBracketJsonToken() { return _openSquare; }
bool &JSONToken::boolCreateCommaJsonToken() { return _comma; }
bool &JSONToken::boolCreateClosedCurlyJsonToken() { return _closedCurly; }
bool &JSONToken::boolCreateOpenCurlyJsonToken() { return _openCurly; }
bool &JSONToken::boolCreateColonJsonToken() { return _colon; }
bool &JSONToken::gpaF() { return _gpa; }
bool &JSONToken::notToken() { return _unknown; }
bool &JSONToken::retrieveString() { return _quotedJsonString; }

//Next, come the SETTER functions
//These are only called on to create tokens.
// In project 1 we had this idea of charOfInterest
// In those terms you can say the SETTER functions only
// run when a charOfInterest is found
void JSONToken::createUnknownToken() {
    _unknown = true;
}

std::string JSONToken::fetchQuotedString() {
    return fetchQuoted;
}
void JSONToken::createFetchQuotedString(std::string quoted) {
    _quotedJsonString = true;
    fetchQuoted = quoted;
}
void JSONToken::createGPAJsonToken(double curGpa) {
    _gpa = true;
    gpa = curGpa;
}
void JSONToken::createClosedSquareBracketJsonToken() {
    _closedSquare = true;
}
void JSONToken::createOpenSquareBracketJsonToken() {
    _openSquare = true;
}
void JSONToken::createCommaJsonToken() {
    _comma = true;
}
void JSONToken::createClosedCurlyJsonToken() {
    _closedCurly = true;
}
void JSONToken::createOpenCurlyJsonToken() {
    _openCurly = true;
}
void JSONToken::createColonJsonToken() {
    _colon = true;
}

double JSONToken::grabGPA() {
    return gpa;
}

void JSONToken::print() {
    if(boolCreateColonJsonToken()) {
        std::cout << ":" << std::endl;
    } else if(boolCreateOpenCurlyJsonToken()) {
        std::cout << "{" << std::endl;
    } else if(boolCreateClosedCurlyJsonToken()) {
        std::cout << "}" << std::endl;
    } else if(boolCreateCommaJsonToken()) {
        std::cout << "," << std::endl;
    } else if(boolCreateOpenSquareBracketJsonToken()) {
        std::cout << "[" << std::endl;
    } else if(boolCreateClosedSquareBracketJsonToken()) {
        std::cout << "]" << std::endl;
    } else if(gpaF()) {
        std::cout << grabGPA() << std::endl;
    } else if(notToken()) {
        std::cout << "unknown" << std::endl;
    } else if(retrieveString()) {
        std::cout << fetchQuotedString() << std::endl;
    } else {
        std::cout << "Incorrect Token" << std::endl;

    }

}
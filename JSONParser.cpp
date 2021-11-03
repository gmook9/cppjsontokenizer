//
// Created by gmook on 4/2/2021.
//

#include "JSONParser.hpp"

JSONParser::JSONParser(JSONTokenizer &tokenizer): tokenizer{tokenizer} {}

Pair JSONParser::parseAPair(){
    // Create a instance of JSONToken called token
    // and populate it with a token from tokenizer
    // using getToken()
    JSONToken token = tokenizer.getToken();
    // DO a check to see if the token received is of string datatype.
    // We know something is of string datatype because we are not reading the data
    // the tokenizer has already done that. Instead we are checking the tokens. Each time
    // a token has been made a boolean is changed alongside of its creation. For instance, when a "ID" token is found
    // it sets a boolean called retrieveString() to be true. Therefore, we can use these boolean flags to make checks
    // and further parse the data.
    if(!token.retrieveString()){
        // If not a string then exit
        // Everything below is part of a error message
        std::cout << "EXITING: parseAPair expected string, but instead received: " << std::endl;
        std::cout << "-----> ";
        token.print();
        std::cout << " <-----";
        exit(9);
    }
    // When the first IF statement does not hit that means a string is found. Therefore,
    // create a variable of string datatype that stores the string. A function has already
    // been built out inside of the token class to get this string and that function is fetchQuotedString()
    std::string firstPartOfPair = token.fetchQuotedString();
    // Get next token using getToken()
    token = tokenizer.getToken();
    if(!token.boolCreateColonJsonToken()){
        // If not a colon then exit
        // Everything below is part of a error message
        std::cout << "EXITING: parseAPair expected colon, but instead received: " << std::endl;
        std::cout << "-----> ";
        token.print();
        std::cout << " <-----";
        exit(9);
    }
    // Get next token using getToken()
    // Allows us to discard ":" since this is
    // not a token we have to save
    token = tokenizer.getToken();

    // IF the token is a GPA
    if(token.gpaF()){
        // Create a variable of double datatype set it equal
        // to the GPA using a function from token that returns gpa
        double secondPartOfPair = token.grabGPA();
        // We already have the first value of the pair so we insert our
        // newly created double into the second value of the pair
        Pair pair(firstPartOfPair, secondPartOfPair);
        return pair;
    }
    //IF the token is a string
    else if(token.retrieveString()){
        // Create a new variable with a datatype string
        // use the function from token to retrieve the string and set
        // it equal to that string
        std::string secondPartOfPair = token.fetchQuotedString();
        // We already have the first value of the pair so we insert our
        // newly created string into the second value of the pair
        Pair pair(firstPartOfPair, secondPartOfPair);
        return pair;
    }
    else{
        std::cout << "EXITING: Neither a string or double datatype were found:";
        std::cout << "-----> ";
        token.print();
        std::cout << " <----- ";
        exit(9);
    }
}

// This ENTIRE function was given by Professor
// It is used as a model for parseAPair and parseJSONEntity
// However, it is pretty much replicated in order
// to make parseJSONEntity because it holds the same structure
EntityInstance JSONParser::parseJSONObject() {
    // parseJSONObject is responsible for parsing a JSON object. As such,
    // the first token is expected to be an open brace.
    JSONToken token = tokenizer.getToken();
    if( ! token.boolCreateOpenCurlyJsonToken() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an open brace, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    EntityInstance instance;
    do {
        Pair pair = parseAPair();
        instance.addPair(pair);
        token = tokenizer.getToken();
    } while( token.boolCreateCommaJsonToken() );  // after having read a pair, we expect a comma
    // So, the above loop terminates when we did find a comma.
    // that means we have parsed an entire object. In that case, token must contain
    // the close brace of that object.
    if( ! token.boolCreateClosedCurlyJsonToken() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected a close brace, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }

    //**********MATRIX CREATION AID************
    //1.
    // Make a pair in the currentMatrix with ID and GPA
    // Create a variable of datatype string that stores the ID
    std::string existingID = instance.locateId();
    //2.
    // Create a variable of datatype double that stores GPA
    double existingGPA = instance.locateGpa();
    //1 & 2.
    // Push back a pair into the currentMatrix
    // std::make_pair MUST be used to create the pair of ID and GPA
    currentMatrix.push_back(std::make_pair(existingID, existingGPA));
    //******************************************
    return instance;
}

// Similar to parseJSONObject()
EntitySet JSONParser::parseJSONEntity(){
    JSONToken token = tokenizer.getToken();
    if(!token.boolCreateOpenSquareBracketJsonToken()){
        std::cout << "EXITING: parseJSONEntity expected open bracket, instead:" << std::endl;
        std::cout << "-----> ";
        token.print();
        std::cout << " <-----";
        exit(9);
    }
    EntitySet set;
    do{
        EntityInstance instance = parseJSONObject();
        set.addEntity(instance);
        token = tokenizer.getToken();
    } while(token.boolCreateCommaJsonToken());
    if(!token.boolCreateClosedSquareBracketJsonToken()){
        std::cout << "EXITING: parseJSONEntity expected close bracket, instead:" << std::endl;
        std::cout << "-----> ";
        token.print();
        std::cout << " <-----";
        exit(9);
    }
    set.setterForMatrix(currentMatrix);
    return set;
}



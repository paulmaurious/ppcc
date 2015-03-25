//
//  lex.h
//  ppcc
//
//  Created by Maurious Paul on 25/03/15.
//  Copyright (c) 2015 M.A.K.E. All rights reserved.
//

#ifndef ppcc_lex_h
#define ppcc_lex_h

#include <fstream>
#include "header.h"                 //Header that contains HEADER files(supported by ISO/IEC 14882:1998 (C++98)) patterns.
#include "keyword.h"                //Header that contains KEYWORDS(supported by ISO/IEC 14882:1998 (C++98)) patterns.
#include "operator.h"               //Header that contains OPERATORS(supported by ISO/IEC 14882:1998 (C++98)) patterns.
#include "splchar.h"                //Header that contains SPECIAL CHARACTERS(supported by ISO/IEC 14882:1998 (C++98)) patterns.

class Lex{
    
    static bool lexPass;            //Tells that Lexical Analysis is passed without any errors if set to true.
    static int order;               //Tracks the order of tokens by numbering them.
    static std::regex IDENT;        //IDENTIFIER regular expression.
    static std::regex DIGIT;        //DIGIT regular expression.
    static std::smatch mat_id;      //Matching IDENTIFIER string.
    static std::smatch mat_digit;   //Matching DIGIT string.
    static std::string Token;       //Matching string pattern from input buffer.
    static std::string validID;     //Temporary use of setters and getters for IDENTIFIER.
    static std::string validDGT;    //Temporary use of setters and getters for DIGIT.
    static bool IDpass;             //Sets to true if IDENTIFIER pattern matches with string from input buffer.
    static bool DGTpass;            //Sets to true if DIGIT pattern matches with string from input buffer.
    
public:
    
    static void setID(std::string);                                     //Setter for IDENTIFIER.
    static void setDGT(std::string);                                    //Setter for DIGIT.
    static std::string getID();                                         //Getter for IDENTIFIER.
    static std::string getDGT();                                        //Getter for DIGIT.
    static bool lex(std::ifstream&, std::ofstream&, std::ofstream&);    //Method that performs lexical analysis.
    static bool isValidID(std::string);                                 //Method that checks for an IDENTIFIER match.
    static bool isValidDGT(std::string);                                //Method that checks for a DIGIT match.
};

#endif

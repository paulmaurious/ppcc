//
//  splchar.h
//  ppcc
//
//  Created by Maurious Paul on 25/03/15.
//  Copyright (c) 2015 M.A.K.E. All rights reserved.
//

#ifndef ppcc_splchar_h
#define ppcc_splchar_h

#include<string>

class SplChar{
    
    static char validSpl;       //Temporary use of setters and getters for SPECIAL CHARACTERS.
    static bool isValidSc;      //Tells that the given SPECIAL CHARACTER is valid.
    static char es_sgq;         //'\''
    static char es_dbq;         //'\"'
    static char es_qnm;         //'\?'
    static char es_bks;         //'\\'
    static char pn_opn;         //'('
    static char pn_cls;         //')'
    static char br_opn;         //'{'
    static char br_cls;         //'}'
    static char sp_qut;         //'`'
    static char sp_trm;         //';'
    static char sq_opn;         //'['
    static char sq_cls;         //']'
    static char sp_uns;         //'_'
    static char sp_at;          //'@'
    static char sp_hsh;         //'#'
    static char sp_dlr;         //'$'
    static char spl[16];        //Array that holds list of SPECIAL CHARACTERS(supported by ISO/IEC 14882:1998 (C++98)).
    
public:
    
    static void setChar(char);                  //Setter for SPECIAL CHARACTERS.
    static char getChar();                      //Getter for SPECIAL CHARACTERS.
    static bool isValidSplChar(std::string);    //Method that checks the validity of given string as an SPECIAL CHARACTER.
};

#endif

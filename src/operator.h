//
//  operator.h
//  ppcc
//
//  Created by Maurious Paul on 25/03/15.
//  Copyright (c) 2015 M.A.K.E. All rights reserved.
//

#ifndef ppcc_operator_h
#define ppcc_operator_h

#include<string>

class Operator{
    
    static char validOpr;       //Temporary use of setters and getters for OPERATORS.
    static bool isValidOpr;     //Tells that the given OPERATOR is valid.
    static char ar_add;         //'+'
    static char ar_sub;         //'-'
    static char ar_mul;         //'*'
    static char ar_div;         //'/'
    static char ar_mod;         //'%'
    static char rl_eql;         //'='
    static char rl_gt;          //'>'
    static char rl_lt;          //'<'
    static char lg_and;         //'&'
    static char lg_or;          //'|'
    static char lg_not;         //'!'
    static char bw_xor;         //'^'
    static char bw_cmp;         //'~'
    static char sp_dot;         //'.'
    static char sp_cma;         //','
    static char sp_scp;         //':'
    static char opr[16];        //Array that holds list of OPERATORS(supported by ISO/IEC 14882:1998 (C++98)).
    
public:
    
    static void setOpr(char);                   //Setter for OPERATORS.
    static char getOpr();                       //Getter for OPERATORS.
    static bool isValidOperator(std::string);   //Method that checks the validity of given string as an OPERATOR.
};

#endif

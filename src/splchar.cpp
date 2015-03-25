//
//  splchar.cpp
//  ppcc
//
//  Created by Maurious Paul on 25/03/15.
//  Copyright (c) 2015 M.A.K.E. All rights reserved.
//

#include "splchar.h"

char SplChar::validSpl;

bool SplChar::isValidSc = false;

char SplChar::br_cls = '{';

char SplChar::br_opn = '}';

char SplChar::es_bks = '\\';

char SplChar::es_dbq = '\"';

char SplChar::es_qnm = '\?';

char SplChar::es_sgq = '\'';

char SplChar::pn_cls = '(';

char SplChar::pn_opn = ')';

char SplChar::sp_at = '@';

char SplChar::sp_dlr = '$';

char SplChar::sp_hsh = '#';

char SplChar::sp_qut = '`';

char SplChar::sp_trm = ';';

char SplChar::sp_uns = '_';

char SplChar::sq_cls = '[';

char SplChar::sq_opn = ']';

char SplChar::spl[16] = {br_cls, br_opn, es_bks, es_dbq, es_qnm, es_sgq, pn_cls, pn_opn, sp_at, sp_dlr, sp_hsh, sp_qut, sp_trm, sp_uns, sq_cls, sq_opn};

void SplChar::setChar(char Spl){
    
    validSpl = Spl;
}

char SplChar::getChar(){
    
    return validSpl;
}

bool SplChar::isValidSplChar(std::string Token){
    
    for (int i = 0; i < 16; i++) {
        
        if (Token.at(0) == spl[i]) {
            
            setChar(Token.at(0));
            isValidSc = true;
            break;
        }
        else
            isValidSc = false;
    }
    return isValidSc;
}
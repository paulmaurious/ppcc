//
//  operator.cpp
//  ppcc
//
//  Created by Maurious Paul on 25/03/15.
//  Copyright (c) 2015 M.A.K.E. All rights reserved.
//

#include "operator.h"

bool Operator::isValidOpr = false;

char Operator::validOpr;

char Operator::ar_add = '+';

char Operator::ar_div = '/';

char Operator::ar_mod = '%';

char Operator::ar_mul = '*';

char Operator::ar_sub = '-';

char Operator::bw_cmp = '~';

char Operator::bw_xor = '^';

char Operator::lg_and = '&';

char Operator::lg_not = '!';

char Operator::lg_or = '|';

char Operator::rl_eql = '=';

char Operator::rl_gt = '>';

char Operator::rl_lt = '<';

char Operator::sp_cma = ',';

char Operator::sp_dot = '.';

char Operator::sp_scp = ':';

char Operator::opr[16] = {ar_add, ar_div, ar_mod, ar_mul, ar_sub, bw_cmp, bw_xor, lg_and, lg_not, lg_or, rl_eql, rl_gt, rl_lt, sp_cma, sp_dot, sp_scp};

void Operator::setOpr(char Opr){
    
    validOpr = Opr;
}

char Operator::getOpr(){
    
    return validOpr;
}

bool Operator::isValidOperator(std::string Token){
    
    for (int i = 0; i < 16; i++) {
        
        if (Token.at(0) == opr[i]) {
            
            setOpr(Token.at(0));
            isValidOpr = true;
            break;
        }
        else
            isValidOpr = false;
    }
    return isValidOpr;
}

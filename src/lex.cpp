//
//  lex.cpp
//  ppcc
//
//  Created by Maurious Paul on 25/03/15.
//  Copyright (c) 2015 M.A.K.E. All rights reserved.
//

#include "lex.h"

bool Lex::lexPass = false;

bool Lex::IDpass = false;

bool Lex::DGTpass = false;

int Lex::order = 1;

std::string Lex::Token = "";

std::regex Lex::DIGIT("[0-9]+[.0-9]*");

std::regex Lex::IDENT("[a-zA-Z]+[a-zA-Z_0-9]*");

std::smatch Lex::mat_digit;

std::smatch Lex::mat_id;

std::string Lex::validDGT = "";

std::string Lex::validID = "";

void Lex::setDGT(std::string digit){
    
    validDGT = digit;
}

void Lex::setID(std::string id){
    
    validID = id;
}

std::string Lex::getDGT(){
    
    return validDGT;
}

std::string Lex::getID(){
    
    return validID;
}

bool Lex::lex(std::ifstream &src, std::ofstream &sym, std::ofstream &err){
    
    sym.open("symbol.tbl", std::ios::out);
    err.open("error.log", std::ios::out);
    while(!src.eof()){
        
        src >> Token;
        while(!Token.empty()){
            
            if(Header::isValidHeader(Token)){
                
                lexPass = true;
                std::string::size_type f = Token.find(Header::getHdr());
                if(f != std::string::npos)
                    Token.erase(f, Header::getHdr().length());
                if(sym.is_open()){
                    
                    sym << "HD " << Header::getHdr() << " " << order << "\n";
                }
            }
            else if(Keyword::isValidKeyword(Token)){
                
                lexPass = true;
                std::string::size_type f = Token.find(Keyword::getKeyword());
                if(f != std::string::npos)
                    Token.erase(f, Keyword::getKeyword().length());
                if(sym.is_open()){
                    
                    sym << "KW " << Keyword::getKeyword() << " " << order << "\n";
                }
            }
            else if(Operator::isValidOperator(Token)){
                
                lexPass = true;
                std::string::size_type f = Token.find(Operator::getOpr());
                if(f != std::string::npos)
                    Token.erase(f, sizeof(Operator::getOpr()));
                if(sym.is_open()){
                    
                    sym << "OP " << Operator::getOpr() << " " << order << "\n";
                }
            }
            else if(isValidID(Token)){
                
                lexPass = true;
                std::string::size_type f = Token.find(Lex::getID());
                if(f != std::string::npos)
                    Token.erase(f, Lex::getID().length());
                if(sym.is_open()){
                    
                    sym << "ID " << Lex::getID() << " " << order << "\n";
                }
            }
            else if(isValidDGT(Token)){
                
                lexPass = true;
                std::string::size_type f = Token.find(Lex::getDGT());
                if(f != std::string::npos)
                    Token.erase(f, Lex::getDGT().length());
                if(sym.is_open()){
                    
                    sym << "DG " << Lex::getDGT() << " " << order << "\n";
                }
            }
            else if(SplChar::isValidSplChar(Token)){
                
                lexPass = true;
                std::string::size_type f = Token.find(SplChar::getChar());
                if(f != std::string::npos)
                    Token.erase(f, sizeof(SplChar::getChar()));
                if(sym.is_open()){
                    
                    sym << "SC " << SplChar::getChar() << " " << order << "\n";
                }
            }
            else{
                
                lexPass = false;
                err << "Unknown symbol " << Token << " at " << order << ".\n";
                Token.erase(Token.begin(), Token.end());
            }
        }
        order++;
    }
    sym.close();
    src.close();
    err.close();
    return lexPass;
}

bool Lex::isValidID(std::string Token){
    
    if(std::regex_search(Token, mat_id, IDENT)){
        
        setID(mat_id[0].str());
        IDpass = true;
    }
    else
        IDpass = false;
    return IDpass;
}

bool Lex::isValidDGT(std::string Token){
    
    if(std::regex_search(Token, mat_digit, DIGIT)){
        
        setDGT(mat_digit[0].str());
        DGTpass = true;
    }
    else
        DGTpass = false;
    return DGTpass;
}

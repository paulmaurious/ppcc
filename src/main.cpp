//
//  main.cpp
//  ppcc
//
//  Created by Maurious Paul on 25/03/15.
//  Copyright (c) 2015 M.A.K.E. All rights reserved.
//

#include <iostream>
#include "lex.h"

bool isValidFile(std::string);

int main(int argc, char** argv) {
    
    std::ifstream fin;
    std::ofstream sym;
    std::ofstream err;
    std::string error = "";
    
    if(argc > 1){
        
        if(isValidFile(argv[1])){
            
            fin.open(argv[1], std::ios::in);
            if(Lex::lex(fin, sym, err)){
                
                std::cout << "Compilation Success!!!\n";
            }
            else{
                
                std::ifstream err;
                err.open("error.log", std::ios::in);
                if(err.is_open()){
                    
                    while(!err.eof()){
                        
                        std::getline(err, error, '\n');
                        std::cout << error << "\n";
                    }
                }
            }
        }
        else{
            
            std::cerr << "Unknown file format. Expecting a \".cpp\" file.\n";
            return 1;
        }
    }
    else{
        
        std::cerr << "Usage : ppcc <filename.cpp>\n";
        return 1;
    }
    return 0;
}

bool isValidFile(std::string fname){
    
    bool valid = false;
    std::string::size_type ext = fname.find(".cpp");
    if(ext != std::string::npos)
        valid = true;
    else
        valid =false;
    return valid;
}

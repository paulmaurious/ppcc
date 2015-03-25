//
//  header.cpp
//  ppcc
//
//  Created by Maurious Paul on 25/03/15.
//  Copyright (c) 2015 M.A.K.E. All rights reserved.
//

#include "header.h"

bool Header::isValidHdr = false;

std::string Header::Hdr = "";

std::string Header::hf_algorithm = "algorithm";

std::string Header::hf_bitset = "bitset";

std::string Header::hf_cassert = "cassert";

std::string Header::hf_cctype = "cctype";

std::string Header::hf_cerrno = "cerrno";

std::string Header::hf_cfloat = "cfloat";

std::string Header::hf_ciso646 = "ciso646";

std::string Header::hf_climits = "climits";

std::string Header::hf_clocale = "clocale";

std::string Header::hf_cmath = "cmath";

std::string Header::hf_complex = "complex";

std::string Header::hf_csetjmp = "csetjmp";

std::string Header::hf_csignal = "csignal";

std::string Header::hf_cstdarg = "cstdarg";

std::string Header::hf_cstddef = "cstddef";

std::string Header::hf_cstdio = "cstdio";

std::string Header::hf_cstdlib = "cstdlib";

std::string Header::hf_cstring = "cstring";

std::string Header::hf_ctime = "ctime";

std::string Header::hf_cwchar = "cwchar";

std::string Header::hf_cwctype = "cwctype";

std::string Header::hf_deque = "deque";

std::string Header::hf_exception = "exception";

std::string Header::hf_fstream = "fstream";

std::string Header::hf_functional = "functional";

std::string Header::hf_iomanip = "iomanip";

std::string Header::hf_ios = "ios";

std::string Header::hf_iosfwd = "iosfwd";

std::string Header::hf_iostream = "iostream";

std::string Header::hf_istream = "istream";

std::string Header::hf_iterator = "iterator";

std::string Header::hf_limits = "limits";

std::string Header::hf_list = "list";

std::string Header::hf_locale = "locale";

std::string Header::hf_map = "map";

std::string Header::hf_memory = "memory";

std::string Header::hf_new = "new";

std::string Header::hf_numeric = "numeric";

std::string Header::hf_ostream = "ostream";

std::string Header::hf_queue = "queue";

std::string Header::hf_set = "set";

std::string Header::hf_sstream = "sstream";

std::string Header::hf_stack = "stack";

std::string Header::hf_stdexcept = "stdexcept";

std::string Header::hf_streambuf = "streambuf";

std::string Header::hf_string = "string";

std::string Header::hf_typeinfo = "typeinfo";

std::string Header::hf_utility = "utility";

std::string Header::hf_valarray = "valarray";

std::string Header::hf_vector = "vector";

std::string Header::hf[50] = {hf_algorithm, hf_bitset, hf_complex, hf_deque, hf_exception, hf_fstream, hf_functional, hf_iomanip, hf_ios, hf_iosfwd, hf_iostream, hf_istream, hf_iterator, hf_limits, hf_list, hf_locale, hf_map, hf_memory, hf_new, hf_numeric, hf_ostream, hf_queue, hf_set, hf_sstream, hf_stack, hf_stdexcept, hf_streambuf, hf_string, hf_typeinfo, hf_utility, hf_valarray, hf_vector, hf_cassert, hf_cctype, hf_cerrno, hf_cfloat, hf_ciso646, hf_climits, hf_clocale, hf_cmath, hf_csetjmp, hf_csignal, hf_cstdarg, hf_cstddef, hf_cstdio, hf_cstdlib, hf_cstring, hf_ctime, hf_cwchar, hf_cwctype};

std::regex Header::dfnDir("^#[\t]*define[\t]*", std::regex::ECMAScript);

std::regex Header::elsDir("^#[\t]*else.*", std::regex::ECMAScript);

std::regex Header::endDir("^#[\t]*endif.*", std::regex::ECMAScript);

std::regex Header::ifDir("^#[\t]*if.*", std::regex::ECMAScript);

std::regex Header::ifnDir("^#[\t]*ifndef.*", std::regex::ECMAScript);

std::regex Header::incHdr("^#[\t]*include[\t]*\\<.*\\>)", std::regex::ECMAScript);

std::smatch Header::mat_hdr;

std::regex Header::linDir("^#[\t]*line.*", std::regex::ECMAScript);

void Header::setHdr(std::string Token){
    
    Hdr = Token;
}

std::string Header::getHdr(){
    
    return Hdr;
}

bool Header::isValidHeader(std::string Token){
    
    char hf[] = "<>";
    std::string hdr = Token;
    if(std::regex_search(hdr, mat_hdr, incHdr)){
        
        setHdr(mat_hdr[0].str());
        size_t pos = hdr.find("<");
        hdr = hdr.substr(pos);
        for (unsigned int i = 0; i < (sizeof(hf)/sizeof(*hf)); ++i)
        {
            
            hdr.erase (std::remove(hdr.begin(), hdr.end(), hf[i]), hdr.end());
        }
        if(isValidHdFile(hdr)){
            
            isValidHdr = true;
        }
    }
    else if(std::regex_search(hdr, mat_hdr, elsDir)){
        
        setHdr(mat_hdr[0].str());
        isValidHdr = true;
    }
    else if(std::regex_search(hdr, mat_hdr, endDir)){
        
        setHdr(mat_hdr[0].str());
        isValidHdr = true;
    }
    else if(std::regex_search(hdr, mat_hdr, ifDir)){
        
        setHdr(mat_hdr[0].str());
        isValidHdr = true;
    }
    else if(std::regex_search(hdr, mat_hdr, ifnDir)){
        
        setHdr(mat_hdr[0].str());
        isValidHdr = true;
    }
    else if(std::regex_search(hdr, mat_hdr, linDir)){
        
        setHdr(mat_hdr[0].str());
        isValidHdr = true;
    }
    else if(std::regex_search(hdr, mat_hdr, dfnDir)){
        
        setHdr(mat_hdr[0].str());
        isValidHdr = true;
    }
    else{
        
        setHdr(Token);
        isValidHdr = false;
    }
    hdr.erase(hdr.begin(), hdr.end());
    return isValidHdr;
}

bool Header::isValidHdFile(std::string hfile){
    
    bool isValidHf = false;
    for(int i = 0; i < 50; i++){
        
        if(hfile.compare(hf[i]) == 0){
            
            isValidHf = true;
            break;
        }
        else
            isValidHf = false;
    }
    return isValidHf;
}

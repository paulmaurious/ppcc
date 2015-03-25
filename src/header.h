//
//  header.h
//  ppcc
//
//  Created by Maurious Paul on 25/03/15.
//  Copyright (c) 2015 M.A.K.E. All rights reserved.
//

#ifndef ppcc_header_h
#define ppcc_header_h

#include<regex>
#include <string>

class Header{
    
    static bool isValidHdr;             //Tells that the provided string is in perfect HEADER format.
    static std::string Hdr;             //Temporary use of setters and getters for HEADERS.
    static std::string hf_algorithm;
    static std::string hf_bitset;
    static std::string hf_complex;
    static std::string hf_deque;
    static std::string hf_exception;
    static std::string hf_fstream;
    static std::string hf_functional;
    static std::string hf_iomanip;
    static std::string hf_ios;
    static std::string hf_iosfwd;
    static std::string hf_iostream;
    static std::string hf_istream;
    static std::string hf_iterator;
    static std::string hf_limits;
    static std::string hf_list;
    static std::string hf_locale;
    static std::string hf_map;
    static std::string hf_memory;
    static std::string hf_new;
    static std::string hf_numeric;
    static std::string hf_ostream;
    static std::string hf_queue;
    static std::string hf_set;
    static std::string hf_sstream;
    static std::string hf_stack;
    static std::string hf_stdexcept;
    static std::string hf_streambuf;
    static std::string hf_string;
    static std::string hf_typeinfo;
    static std::string hf_utility;
    static std::string hf_valarray;
    static std::string hf_vector;
    static std::string hf_cassert;
    static std::string hf_cctype;
    static std::string hf_cerrno;
    static std::string hf_cfloat;
    static std::string hf_ciso646;
    static std::string hf_climits;
    static std::string hf_clocale;
    static std::string hf_cmath;
    static std::string hf_csetjmp;
    static std::string hf_csignal;
    static std::string hf_cstdarg;
    static std::string hf_cstddef;
    static std::string hf_cstdio;
    static std::string hf_cstdlib;
    static std::string hf_cstring;
    static std::string hf_ctime;
    static std::string hf_cwchar;
    static std::string hf_cwctype;
    static std::string hf[50];          //Array that holds all the HEADER files(supported by ISO/IEC 14882:1998 (C++98)).
    static std::regex incHdr;           //HEADER pattern for "#include<>".
    static std::regex ifDir;            //Preprocessor pattern for "#if".
    static std::regex elsDir;           //Preprocessor pattern for "#else".
    static std::regex endDir;           //Preprocessor pattern for "#endif".
    static std::regex dfnDir;           //Preprocessor pattern for "#define".
    static std::regex linDir;           //Preprocessor pattern for "#line".
    static std::regex ifnDir;           //Preprocessor pattern for "#ifndef"
    static std::smatch mat_hdr;         //Matching HEADER string.
    
public:
    
    static void setHdr(std::string);            //Setter for HEADER.
    static std::string getHdr();                //Getter for HEADER.
    static bool isValidHeader(std::string);     //Method that checks the validity of HEADER pattern.
    static bool isValidHdFile(std::string);     //Method that checks the validity of HEADER files(supported by ISO/IEC 14882:1998 (C++98)).
};

#endif

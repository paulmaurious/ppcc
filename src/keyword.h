//
//  keyword.h
//  ppcc
//
//  Created by Maurious Paul on 25/03/15.
//  Copyright (c) 2015 M.A.K.E. All rights reserved.
//

#ifndef ppcc_keyword_h
#define ppcc_keyword_h

#include<string>
#include<regex>

class Keyword{
    
    static std::string keywrd;          //Temporary use of setters and getters for KEYWORDS.
    static bool isValidKw;              //Tells that the provided string is a KEYWORD(supported by ISO/IEC 14882:1998 (C++98)).
    static std::regex alpha;            //To seperate KEYWORD from special charcters such as '(', '*', etc.,
    static std::smatch mat_alpha;       //Matching ALPHA string.
    static std::string kw_asm;
    static std::string kw_auto;
    static std::string kw_bool;
    static std::string kw_break;
    static std::string kw_case;
    static std::string kw_catch;
    static std::string kw_char;
    static std::string kw_class;
    static std::string kw_const;
    static std::string kw_const_cast;
    static std::string kw_continue;
    static std::string kw_default;
    static std::string kw_delete;
    static std::string kw_do;
    static std::string kw_double;
    static std::string kw_dynamic_cast;
    static std::string kw_else;
    static std::string kw_enum;
    static std::string kw_explicit;
    static std::string kw_export;
    static std::string kw_extern;
    static std::string kw_false;
    static std::string kw_float;
    static std::string kw_for;
    static std::string kw_friend;
    static std::string kw_goto;
    static std::string kw_if;
    static std::string kw_inline;
    static std::string kw_int;
    static std::string kw_long;
    static std::string kw_mutable;
    static std::string kw_namespace;
    static std::string kw_new;
    static std::string kw_operator;
    static std::string kw_private;
    static std::string kw_protected;
    static std::string kw_public;
    static std::string kw_register;
    static std::string kw_reinterpret_cast;
    static std::string kw_return;
    static std::string kw_short;
    static std::string kw_signed;
    static std::string kw_sizeof;
    static std::string kw_static;
    static std::string kw_static_cast;
    static std::string kw_struct;
    static std::string kw_switch;
    static std::string kw_template;
    static std::string kw_this;
    static std::string kw_throw;
    static std::string kw_true;
    static std::string kw_try;
    static std::string kw_typedef;
    static std::string kw_typeid;
    static std::string kw_typename;
    static std::string kw_union;
    static std::string kw_unsigned;
    static std::string kw_using;
    static std::string kw_virtual;
    static std::string kw_void;
    static std::string kw_volatile;
    static std::string kw_wchar_t;
    static std::string kw_while;
    static std::string kw[63];                  //Array that holds the list of KEYWORDS(supported by ISO/IEC 14882:1998 (C++98)).
    
public:
    static void setKeyword(std::string);        //Setter for KEYWORD.
    static std::string getKeyword();            //Getter for KEYWORD.
    static bool isValidKeyword(std::string);    //Method that checks validity of provided string as a KEYWORD.
};

#endif

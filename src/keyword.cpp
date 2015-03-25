//
//  keyword.cpp
//  ppcc
//
//  Created by Maurious Paul on 25/03/15.
//  Copyright (c) 2015 M.A.K.E. All rights reserved.
//

#include "keyword.h"

std::string Keyword::keywrd = "";

bool Keyword::isValidKw = false;

std::regex Keyword::alpha("[a-zA-Z]*");

std::smatch Keyword::mat_alpha;

std::string Keyword::kw_asm = "asm";

std::string Keyword::kw_auto = "auto";

std::string Keyword::kw_bool = "bool";

std::string Keyword::kw_break = "break";

std::string Keyword::kw_case = "case";

std::string Keyword::kw_catch = "catch";

std::string Keyword::kw_char = "char";

std::string Keyword::kw_class = "class";

std::string Keyword::kw_const = "const";

std::string Keyword::kw_const_cast = "const_cast";

std::string Keyword::kw_continue = "continue";

std::string Keyword::kw_default = "default";

std::string Keyword::kw_delete = "delete";

std::string Keyword::kw_do = "do";

std::string Keyword::kw_double = "double";

std::string Keyword::kw_dynamic_cast = "dynamic_cast";

std::string Keyword::kw_else = "else";

std::string Keyword::kw_enum = "enum";

std::string Keyword::kw_explicit = "explicit";

std::string Keyword::kw_export = "export";

std::string Keyword::kw_extern = "extern";

std::string Keyword::kw_false = "false";

std::string Keyword::kw_float = "float";

std::string Keyword::kw_for ="for";

std::string Keyword::kw_friend = "friend";

std::string Keyword::kw_goto = "goto";

std::string Keyword::kw_if = "if";

std::string Keyword::kw_inline = "inline";

std::string Keyword::kw_int = "int";

std::string Keyword::kw_long = "long";

std::string Keyword::kw_mutable = "mutable";

std::string Keyword::kw_namespace = "namespace";

std::string Keyword::kw_new = "new";

std::string Keyword::kw_operator = "operator";

std::string Keyword::kw_private = "private";

std::string Keyword::kw_protected = "protected";

std::string Keyword::kw_public = "public";

std::string Keyword::kw_register = "register";

std::string Keyword::kw_reinterpret_cast = "reinterpret_cast";

std::string Keyword::kw_return = "return";

std::string Keyword::kw_short = "short";

std::string Keyword::kw_signed = "signed";

std::string Keyword::kw_sizeof = "sizeof";

std::string Keyword::kw_static = "static";

std::string Keyword::kw_static_cast = "static_cast";

std::string Keyword::kw_struct = "struct";

std::string Keyword::kw_switch = "switch";

std::string Keyword::kw_template = "template";

std::string Keyword::kw_this = "this";

std::string Keyword::kw_throw = "throw";

std::string Keyword::kw_true = "true";

std::string Keyword::kw_try = "try";

std::string Keyword::kw_typedef = "typedef";

std::string Keyword::kw_typeid = "typeid";

std::string Keyword::kw_typename = "typename";

std::string Keyword::kw_union = "union";

std::string Keyword::kw_unsigned = "unsigned";

std::string Keyword::kw_using = "using";

std::string Keyword::kw_virtual = "virtual";

std::string Keyword::kw_void = "void";

std::string Keyword::kw_volatile = "volatile";

std::string Keyword::kw_wchar_t = "wchar_t";

std::string Keyword::kw_while = "while";

std::string Keyword::kw[63] = {kw_asm, kw_auto, kw_bool, kw_break, kw_case, kw_catch, kw_char, kw_class, kw_const, kw_const_cast, kw_continue, kw_default, kw_delete, kw_do, kw_double, kw_dynamic_cast, kw_else, kw_enum, kw_explicit, kw_export, kw_extern, kw_false, kw_float, kw_for, kw_friend, kw_goto, kw_if, kw_inline, kw_int, kw_long, kw_mutable, kw_namespace, kw_new, kw_operator, kw_private, kw_protected, kw_public, kw_register, kw_reinterpret_cast, kw_return, kw_short, kw_signed, kw_sizeof, kw_static, kw_static_cast, kw_struct, kw_switch, kw_template, kw_this, kw_throw, kw_true, kw_try, kw_typedef, kw_typeid, kw_typename, kw_union, kw_unsigned, kw_using, kw_virtual, kw_void, kw_volatile, kw_wchar_t, kw_while};

void Keyword::setKeyword(std::string Token){
    
    keywrd = Token;
}

std::string Keyword::getKeyword(){
    
    return keywrd;
}

bool Keyword::isValidKeyword(std::string Token){
    
    if(std::regex_search(Token, mat_alpha, alpha)){
        
        for(int i = 0; i < 63; i++){
            
            if(mat_alpha[0].compare(kw[i]) == 0){
                
                isValidKw = true;
                setKeyword(mat_alpha[0].str());
                break;
            }
            else
                isValidKw = false;
        }
    }
    else
        isValidKw = false;
    return isValidKw;
}

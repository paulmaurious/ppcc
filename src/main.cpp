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
    std::string temp = argv[1];
    
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
        else if (temp.compare("--v") == 0 || temp.compare("--version") == 0){
            
            std::cout << "ppcc (M.A.K.E PPCC) 1.0.0\n";
            std::cout << "\nCopyright (c) 2015 M.A.K.E. All rights reserved.\n";
            std::cout << "\nLicense GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.\n";
            std::cout << "This program comes with ABSOLUTELY NO WARRANTY.\n";
            std::cout << "This is free software, and you are welcome to redistribute it under certain conditions.\n";
            std::cout << "You should have received a copy of the GNU General Public License along with this program.  If not, see <http://www.gnu.org/licenses/>.\n";
            exit(0);
        }
        else if(temp.compare("--help") == 0){
            
            std::cout << "Usage : ppcc [FILE]\n";
            std::cout << "\nOperation modes:\n";
            std::cout << "\n\t--help\t\t\tdisplay this help and exit\n";
            std::cout << "\t--version\t\toutput version information and exit\n";
            exit(0);
        }
        else{
            
            std::cerr << "ppcc : Invalid option '" << argv[1] << "'\n";
            std::cout << "Try ppcc --help for more information.\n";
            exit(1);
        }
    }
    else{
        
        std::cerr << "ppcc : Insufficient number of arguments.\n";
        std::cout << "Try ppcc --help for more information.\n";
        exit(1);
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

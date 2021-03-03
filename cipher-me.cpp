#include <iostream>
#include <fstream>
#include "Cipher/Cipher.h"
int main(int argc, char**argv){
    if(argc < 2){
       std::cout << "No file provided.\n" << std::endl; 
       return -1;
    }else if(argc < 3){
        std::cout << "No shift value provided.\n" << std::endl;
    }
    Cipher cipher(argv[1], std::stoi(argv[2]));
    std::string op = argv[3];
    if(op == "-d"){
        cipher.decode();
        return 0;
    }else if(argc == 3){
        cipher.encode();
        return 0;
    }else{
        std::cout << "Too many arguments.\n" << std::endl;
        return -1;
    }
}
#include <iostream>
#include <fstream>
#include <exception>
class Cipher{
    private:
    std::string file_name;
    int shift;
    enum class Operation{
       ENCODE, DECODE 
    };
    const int alphabet_length = 26;
    class Cipher_Error:public std::exception{
        public:
        virtual const char* what() const noexcept {
            return "Couldn't open stream";
        }
    };
    char wrap(char, int, int);
    void shift_char(std::string&, Operation);
    public:
    Cipher(std::string s, int sh):file_name{s}, shift{sh}{}
    void encode();
    void decode();
    void shift_string(Operation);
};
#include "Cipher.h"
void Cipher::shift_char(std::string &source, Operation op){
    //Decoding is the oposite operation so the source must be shifted (alphabet length - shift) places
    int local_shift = op == Operation::DECODE?alphabet_length - shift:shift;
    for(auto &c: source){
       if(isalpha(c)){
           //Starting point for shift in ASCII depends on lower or upper case.
           int start = isupper(c)?'A':'a';
           c = wrap(c, start, local_shift);
       }
   }
}
/*
Since the values of the chars are in ASCII we must first transform them into the [0,26) range 
*/
char Cipher::wrap(char c, int start, int local_shift){
    return static_cast<char>(static_cast<int>(c + local_shift - start)%alphabet_length + start); 
} 
void Cipher::shift_string(Operation op){
   std::ifstream ifs{file_name};
   try{
      if(!ifs) throw Cipher_Error{};
   }catch(Cipher_Error &e){
       std::cout << e.what() << std::endl;
   }
   std::string source;
   char c;
   while(ifs.get(c)){
       source+=c;
   }
   ifs.close();
   shift_char(source, op);
   std::ofstream ofs{file_name};
   ofs << source;
   ofs.close();
}
void Cipher::encode(){
    shift_string(Operation::ENCODE);
}
void Cipher::decode(){
    shift_string(Operation::DECODE);
}
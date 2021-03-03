# Caesar Cipher
A fun project that encrypts and decrypts a file based on the [Caesar Cipher]("https://en.wikipedia.org/wiki/Caesar_cipher"). 
## Why?
I've always been interested in cryptography and this seem like a good starting point. 
## Compiling
Since it's a small project using your default compiler would suffice. Personally, I use the GNU g++ compiler and the following command (Assuming you are in the project root directory):
`g++ ./Cipher/Cipher.cpp cipher-me.cpp -o cipher-me`

## Usage
It's pretty simple the program takes a couple of arguments:
1. File name (The file to be decrypted or encrypted)
2. The shift value (An integer)
3. An optional decode command ("-d")

`./cipher-me <File name> <Shift value> -d(optional)`




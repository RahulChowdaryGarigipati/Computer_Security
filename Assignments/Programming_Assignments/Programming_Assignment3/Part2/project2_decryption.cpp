#include <iostream>
#include <string>
#include <fstream>
#include <sys/stat.h>

using namespace std;

int main(int argc, char * argv[]) {


  //verifying with the signed encrypted file with our public key(publickey.pem)

  string s1 = " openssl dgst -sha256 -verify " + std::string(argv[2]) + " -signature " + std::string(argv[1]) + " encrypt.txt";

  const char * cmd1 = s1.c_str();

  system(cmd1);

  //Decrypting the encrypted file using the content in symmetric.txt

  string s2 = "openssl enc -d -aes-256-cbc -in encrypt.txt -out decrypt.txt -pass file:" + std::string(argv[3]) + "";

  const char * cmd2 = s2.c_str();

  system(cmd2);

  return 0;

}

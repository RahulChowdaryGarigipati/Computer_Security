#include <iostream>
#include <string>
#include<fstream>
#include<sys/stat.h>

using namespace std;

int main(int argc, char * argv[]) {


  //Decrypting the given symm.bin with the given third party public key
  string s1 = "openssl rsautl -encrypt -pubin -inkey " + std::string(argv[2]) + " -in " + std::string(argv[1]) + " -raw -hexdump -out symmetric.txt";
 
  const char * cmd1 = s1.c_str();

  system(cmd1);

  //Encrypting the plaintext with the obtained decrypted symmetric.txt file
  system("openssl enc -aes-256-cbc -salt -in plaintext -out encrypt.txt -pass file:symmetric.txt");

  //Signing the encrypted file with the private I have from first part
  string s2 = "openssl dgst -sha256 -sign " + std::string(argv[3]) + " -out signed.txt.sha256 encrypt.txt";

  const char * cmd2 = s2.c_str();

  system(cmd2);

  return 0;

}

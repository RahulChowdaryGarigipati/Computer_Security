/// Q1.) Implementing A5/1 Algorithm.


// Include header file
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include<bits/stdc++.h>

#define c_key 7 

using namespace std;

class Settlement {
	public:
template < typename T > static string vector_to_string(std::vector < T > record, std::string separator) {
	stringstream text;
	for (size_t index = 0; index < record.size(); ++index) {
		if (index != 0) {
			// include custom separator
			text << separator;
		}
		// Add vector element
		text << to_string(record[index]);
	}
	// Return result
	return text.str();
}
};

// Main Class
class Main
{
    // Shifts all array elements up by 1.
    public:
    static void shiftArray(std::vector<int> &arr)
    {
        for (int i = arr.size() - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
    }

    // Generate a keystream bit based on x18 XOR y21 XOR z22 
    static std::string getKeyStreamBit(std::vector<int> &x, std::vector<int> &y, std::vector<int> &z)
    {
        return "" + std::to_string((x[18] ^ y[21] ^ z[22]));
    }

    // Calculate the majority rate of x8, y10, z10
    static int maj(std::vector<int> &x, std::vector<int> &y, std::vector<int> &z)
    {
        return ((x[8] & y[10]) ^ (x[8] & z[10]) ^ (y[10] & z[10]));
    }

    // x - register steps
    static void stepX(std::vector<int> &x)
    {
        int t = (x[13] ^ x[16] ^ x[17] ^ x[18]);
        Main::shiftArray(x);
        x[0] = t;
    }

    // y - register steps
    static void stepY(std::vector<int> &y)
    {
        int t = (y[20] ^ y[21]);
        Main::shiftArray(y);
        y[0] = t;
    }

    // z - register steps
    static void stepZ(std::vector<int> &z)
    {
        int t = (z[7] ^ z[20] ^ z[21] ^ z[22]);
        Main::shiftArray(z);
        z[0] = t;
    }
    static void printRegisters(std::vector<int> &x, std::vector<int> &y, std::vector<int> &z)
    {
        std::cout << "X: " + Settlement::vector_to_string(x,",") << std::endl;
        std::cout << "Y: " + Settlement::vector_to_string(y,",") << std::endl;
        std::cout << "Z: " + Settlement::vector_to_string(z,",") << std::endl;
    }

    // A function to generate a 32-bit keystream using A5/1
    static void TestA51()
    {
        std::vector<int> x{1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0};
        std::vector<int> y{0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1};
        std::vector<int> z{1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0};
        std::string keyStream = "";
        std::cout << "Initial Fill of the Registers is: " << std::endl;
        Main::printRegisters(x, y, z);
        for (int i = 0; i < 32; i++)
        {
            int m = Main::maj(x, y, z);
            if (x[8] == m)
            {
                Main::stepX(x);
            }
            if (y[10] == m)
            {
                Main::stepY(y);
            }
            if (z[10] == m)
            {
                Main::stepZ(z);
            }
            keyStream = Main::getKeyStreamBit(x, y, z) + keyStream;
        }
        std::cout << "\n32 keystream bits is: " + keyStream << std::endl;
        std::cout << "\nAfter 32 keystream bits generated: " << std::endl;
        Main::printRegisters(x, y, z);
    }

    // Main function
    static void main(std::vector<std::string> &args)
    {
        Main::TestA51();
    }
};


// encrypt function
string encrypt(string input_str){
    string output_str;
    for(int i=0; i<input_str.size(); i++){
        if(input_str[i]>='0' && input_str[i]<='9'){
            output_str+=(input_str[i]-'0'+c_key)%10+'0';
        }
        else if(input_str[i]>='A' && input_str[i]<='Z'){
            output_str+=(input_str[i]-'A'+c_key)%26+'A';
        }
        else if(input_str[i]>='a' && input_str[i]<='z'){
            output_str+=(input_str[i]-'a'+c_key)%26+'a';
        }
    }
    return output_str;
}

// decrypt function
string decrypt(string input_str){
    string output_str;
    for(int i=0; i<input_str.size(); i++){
        if(input_str[i]>='0' && input_str[i]<='9'){
            output_str+=(input_str[i]-'0'-c_key+10)%10+'0';
        }
        else if(input_str[i]>='A' && input_str[i]<='Z'){
            output_str+=(input_str[i]-'A'-c_key+26)%26+'A';
        }
        else if(input_str[i]>='a' && input_str[i]<='z'){
            output_str+=(input_str[i]-'a'-c_key+26)%26+'a'; 
        }
    }
    return output_str;
}

int main(int argc, char **argv){
	std::vector<std::string> parameter(argv + 1, argv + argc);
	Main::main(parameter); 

    string input_str;
    int choice;
    char ch='c';
    while(ch!='e'){
        cout<<"Enter the string (if for Decryption please enter the ciphertext. else for encryption enter the plaintext):\n";
        cin>>input_str;
        cout<<"Enter 1 to encrypt the above entered string\n";
        cout<<"Enter 2 to decrypt the above entered string\n";
        cin>>choice;
        if(choice==1){
            string output_str=encrypt(input_str);
            cout<<"CipherText is: "<<output_str<<"\n";
        }
        if(choice==2){
            string output_str=decrypt(input_str);
            cout<<"PlainText is: "<<output_str<<"\n";
        }
        cout<<"If You want to continue press 'c'\n";
        cout<<"If you want to exit press 'e'\n";
        cin>>ch;
    }


	return 0;
};
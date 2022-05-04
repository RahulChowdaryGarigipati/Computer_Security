// #include <stdint>
#include <iostream>
// #include <stdlib.h>
#include <string.h>

using namespace std;



int main()
{
int i, j, count=0, key;
char c;
int dict[200]={0};
char ct[1000] = {"KEKPRLBNOLMKYBPRGPBMMLTJLJBAZIPTKVRLKPVILIVJBAZWBATVKYBWUSMLIRAKIPVGPBMTPORLIRRLKSJBNCYLIEKJBAZWBATVKYIPSBQRLKATVKPBNOLRBAIGKNVATVRWNVRQNCBQICCBQRLKARLTVTVOBTPORBAIGKTRLIWYQBWCIWOKJBAZIPTKVCTGKOBBOCKIPYATJWBVBQRRBOKRUIJGRLKRWNVRRLKSCBVRKEKPTQRLKSVNJJKKYTPCTATRTPOOBEKWPAKPRVNWEKTCCIPJKKEKPTQRLKSVNJJKKYTPTAZWBETPORLKTWBMPTPRKWPICVKJNWTRSRLKUKVRRLKSCCUKIUCKRBVISTVMKLIEKVKJNWKYBNWVKCEKVQWBARLKPVIKDJKZRQBWRLKZIWRVRLIRMKKTRLKWYBPRGPBMIUBNRBWJIPRRICGIUBNR"};
int length = strlen(ct);

/// Function for computing and displaying the frequency analysis of the ciphertext.

for(i=0; i<length; i++)
    {
        dict[ct[i]]++;
    }
for(i=65; i<100; i++)
    {
        if(dict[i]!=0)
        {
            count++;
            cout<< "The Frequency of " << char(i) << " is: " << dict[i] << endl;
        }
    }

/// Function for guessing the cipher key.
/// Computing the Frequency ordering of the letters by mapping them to the standard english letter frequency ordering.
 
    for(i=0; i<length; i++)
    {
        if(ct[i]=='K')
        {
            ct[i]='E';
        }
    else  if(ct[i]=='R')
            ct[i]='T';

    else  if(ct[i]=='B')
            ct[i]='O';

    else if(ct[i]=='T')
            ct[i]='I';
       
    else if(ct[i]=='P')
            ct[i]='N';
       
    else if(ct[i]=='V')
            ct[i]='S';
       
    else if(ct[i]=='I')
            ct[i]='A';
       
    else if(ct[i]=='L')
            ct[i]='H';
       
    else if(ct[i]=='W')
            ct[i]='R';
       
    else if(ct[i]=='J')
            ct[i]='C';
       
    else if(ct[i]=='C')
            ct[i]='L';
       
    else if(ct[i]=='B')
            ct[i]='O';
       
    else if(ct[i]=='A')
            ct[i]='H';
       
    else if(ct[i]=='N')
            ct[i]='U';
       
    else if(ct[i]=='O')
            ct[i]='G';
       
    else if(ct[i]=='Y')
            ct[i]='D';
       
    else if(ct[i]=='Q')
            ct[i]='F';
       
    else if(ct[i]=='S')
            ct[i]='Y';
       
    else if(ct[i]=='M')
            ct[i]='W';
       
    else if(ct[i]=='E')
            ct[i]='V';
       
    else if(ct[i]=='G')
            ct[i]='K';
       
    else if(ct[i]=='Z')
            ct[i]='P';
       
    else if(ct[i]=='U')
            ct[i]='B';
    }
    cout<< "After Decryption, The Plain Text is:\n" << ct;


/// Function for Decrpyting the plain text after the user enters the key.

    cout << " \n Enter key: ";

  cin >> key;

  for(j = 0; ct[j] != '\0'; ++j){

    c = ct[j];

    if(c >= 'A' && c <= 'Z'){

      c = c - key;

      if(c <'A'){

        c = c + 'Z' - 'A' + 1;

      }

      ct[j] = c;

    }

  }

  cout << "Decrypted message is:\n" << ct;

  return 0;

}

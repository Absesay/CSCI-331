#include <iostream>
#include <string>
//#include "libxl.h"

#include "P1.h"

using namespace std; 

int DelimTextBuffer::Read(ifstream & infile)
{
string info;

int counter =0;
  
  infile.open ("us_postal_codes.csv");


 
if (infile.is_open()) {
    cout << "File has been opened" << endl;
}
else {
    cout << "NO FILE HAS BEEN OPENED" << endl;
}

while (!infile.eof()) {
  counter++;
    //infile >> info;
    getline(infile, info); 
    cout << info << endl;  
}
  infile.close();
  return 0;
}


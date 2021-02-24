#include <iostream>
#include <string>
#include <fstream>


using namespace std; 

class DelimTextBuffer
{
public:
    DelimTextBuffer(char Delim = ',', int maxBytes = 1000);
    int Read (istream & infile);
    //int Write(ostream & file);
    //int Pack (const char * str, int size = -1);
    //int Unpack (char * str);

private:

    char Delim; // delimiter
    char* Buffer; // Array to hold information piece in
    int Buffersize; // size of field
    int MaxBytes; // Max number of chars in the buffer
    int NextByte; // packing/unpacking position in buffer
};
    

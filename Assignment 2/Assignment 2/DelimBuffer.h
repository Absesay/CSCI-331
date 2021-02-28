///******************************************************************
/// @author Authors: Ben Olson,Gia Dat Diep
///					 Moffat Omuya, Sandesh Raj and Abraham Sesay
/// 
/// @details This is the buffer class, DelimBuffer.h and .cpp
/// This class reads in each line from the provided file or instream
/// 
/// 
///******************************************************************

#ifndef DELIMBUFFER_HEADER
#define DELIMBUFFER_HEADER

#include <iostream>
#include <string>


using namespace std;

class DelimBuffer
{
	public:

		/// Default Constructor
		DelimBuffer(char del = ',')
		{
			delim = del; 
			bufferSize = 0; 
			nextCharIndex = 0;
		}

		bool read(istream& infile);
		bool unpack(string& aStr);

	protected:
		void clear();

	private:
		char delim = ' '; ///Delimiter
		string buffer; /// The buffer
		int bufferSize = 0; /// Size of the buffer string
		int nextCharIndex = 0;
};
#endif

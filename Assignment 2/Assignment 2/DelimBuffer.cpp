///*************************************************************
/// @file DelimBuffer.cpp
/// @author Authors: Ben Olson, Gia Dat Diep
///					 Moffat Omuya, Sandesh Raj and Abraham Sesay
/// 
/// @details Definition of DelimBuffer.h
/// 
///*************************************************************


#include "DelimBuffer.h"

/// @brief clear the buffer
/// @param no parameters passed
/// @return no return values
void DelimBuffer :: clear()
{
	bufferSize = 0;
	nextCharIndex = 0;
}

/// @brief method reads from the file stream and tests to see if stream open
/// @param infile  file stream is passed in
/// @return returns a boolean value about whether the stream is open or not
bool DelimBuffer :: read (istream& infile)
{
	if (infile.fail()) return false;
	getline(infile, buffer, (char)infile.eof());
	bufferSize = buffer.length();
	return true;
}

/// @brief method "unpacks" the passed string pointer
/// @param string pointer aStr
/// @return Returns a boolean value if the delimeter is in the string or not
bool DelimBuffer :: unpack(string& aStr)
{
	if (nextCharIndex > bufferSize) return false;
	
	int len = -1; // length of unpacking string
	int start = nextCharIndex; // first character to be unpacked
	
	for (int i = start; i < bufferSize; i++)
		if (buffer[i] == delim || buffer[i] == '\n') {len = i - start; break;}
	
	if (len == -1) return false; // delimeter not found
	nextCharIndex += len + 1;
	
	aStr = buffer.substr(start, len);
	aStr[len] = '\0';
	return true;
}

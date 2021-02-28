#include "DelimBuffer.h"


void DelimBuffer :: clear()
{
	bufferSize = 0;
	nextCharIndex = 0;
}

bool DelimBuffer :: read (istream& infile)
{
	if (infile.fail()) return false;
	getline(infile, buffer, (char)infile.eof());
	bufferSize = buffer.length();
	return true;
}

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

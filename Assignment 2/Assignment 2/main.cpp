///*************************************************************
/// @file Main.cpp
/// @author Authors: Ben Olson, Gia Dat Diep
///					 Moffat Omuya, Sandesh Raj and Abraham Sesay
/// 
/// @details This is the main program that process the input
/// from the provided file, passing it to the buffer, parsing
/// it and storing the information for processing.
/// 
///*************************************************************


#include "Location.h"
#include "DelimBuffer.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "QuickSort.cpp"
#include <iomanip>


using namespace std;

int main()
{
	vector<Location> location;
	fstream infile;
	infile.open("us_postal_codes.csv");
	DelimBuffer buffer;
	if (!buffer.read(infile)) return 0;
	string field[6];
	for (int i = 0; i < 6; i++) { buffer.unpack(field[i]); } 
	
	while (1)
	{
		Location temp;
		if (!temp.unpack(buffer)) {break;}
		location.push_back(temp);
	}
	
	int size = location.size();
	qSort(location, 0, size - 1);
	
	cout << "+---------------------------------------------------------------------+" << endl;
	cout << '|' << setw(5) << "State"
		 << '|' << setw(15) << "Westernmost"
		 << '|' << setw(15) << "Easternmost"
		 << '|' << setw(15) << "Northernmost"
		 << '|' << setw(15) << "Southernmost" << '|' << endl;	
	cout << "+---------------------------------------------------------------------+" << endl;
	int currentIndex = 0;
	while (currentIndex < size)
	{
		string currentState = location[currentIndex].getState();
		int   w_most = currentIndex,
			  e_most = currentIndex,
			  s_most = currentIndex,
			  n_most = currentIndex;
		
		currentIndex++;
		while (currentState == location[currentIndex].getState())
		{
			if (location[currentIndex].getLong() > location[w_most].getLong()) w_most = currentIndex;
			if (location[currentIndex].getLong() < location[e_most].getLong()) e_most = currentIndex;
			if (location[currentIndex].getLat() > location[n_most].getLat())   n_most = currentIndex;
			if (location[currentIndex].getLat() < location[s_most].getLat())   s_most = currentIndex;
			currentIndex++;
			if (currentIndex == size) break;
		}
		cout << '|' << setw(5) << location[currentIndex - 1].getState() 
			 << '|' << setw(15) << location[w_most].getZipCode() 
			 << '|' << setw(15) << location[e_most].getZipCode() 
			 << '|' << setw(15) << location[n_most].getZipCode() 
			 << '|' << setw(15) << location[s_most].getZipCode()  << '|' << endl;
	}
	cout << "+---------------------------------------------------------------------+" << endl;
}


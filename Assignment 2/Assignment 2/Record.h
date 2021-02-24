///*************************************************************
/// @author Authors: Ben Olson,Gia Dat Diep
///					 Moffat Omuya, Sandesh Raj and Abraham Sesay
/// 
/// Description of project goes here
/// 
/// 
///*************************************************************


//#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

class Record
{
	int zipCode = 0;
	string placeName = " ";
	string State = " ";
	string County = " ";
	float Lat = 0;
	float Long = 0;

	Record(){};
	Record(int zCode, string place, string state, string county, float lat, float long1)
	{
		zipCode = zCode;
		placeName = place;
		State = state;
		County = county;
		Lat = lat;
		Long = long1;
	}
	~Record(){};


};
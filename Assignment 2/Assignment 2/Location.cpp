///*************************************************************
/// @file Location.cpp
/// @author Authors: Ben Olson, Gia Dat Diep
///					 Moffat Omuya, Sandesh Raj and Abraham Sesay
/// 
/// @details Definition of Location.h methods
/// 
///*************************************************************


#include "Location.h"
#include <sstream>

/// @brief This method "unpacks" the delimiter object that is passed
///			and reads from its provided file
/// @param DelimBuffer object buffer
/// @return Returns a boolean result about whether the object piece is actually there
bool Location :: unpack(DelimBuffer &buffer)
{
	bool result;
	result = buffer.unpack(zipcode);
	result = result && buffer.unpack(name);
	result = result && buffer.unpack(state);
	result = result && buffer.unpack(county);
	string lat_str, long_str;
	result = result && buffer.unpack(lat_str);
	result = result && buffer.unpack(long_str);
	stringstream(lat_str) >> latitude;
	stringstream(long_str) >> longitude;
	return result;
}

string Location :: getZipCode() const { return zipcode; } // @return Fetches zipcode value
string Location :: getName() const { return name; } // @return Fetches Name value 
string Location :: getCounty() const { return county; } // @return Fetches County value
string Location :: getState() const { return state; } // @return Fetches State value
float Location :: getLat() const { return latitude; } // @return Fetches Latitude value
float Location :: getLong() const { return longitude; } // @return Fetches longitude value

/// @param passed a string value to set zipcode
/// @return no return value
void Location :: setZipCode(string val) { zipcode = val; }

/// @param passed a string value to set place name 
/// @return no return value
void Location :: setName(string val) { name = val; }

/// @param passed a string value to set county name 
/// @return no return value
void Location :: setCounty(string val) { county = val; }

/// @param passed a string value to set state name 
/// @return no return value
void Location :: setState(string val) { state = val; }

/// @param passed a string value to set latitude 
/// @return no return value
void Location :: setLat(float val) { latitude = val; }

/// @param passed a string value to set place longitude 
/// @return no return value
void Location :: setLong(float val) { longitude = val; }

/// @brief overloaded assignment operator for a location object
/// @param passed a Location class object
/// @return no return value
void Location :: operator= (const Location &loc)
{
	setZipCode(loc.getZipCode());
	setName(loc.getName());
	setState(loc.getState());
	setCounty(loc.getCounty());
	setLat(loc.getLat());
	setLong(loc.getLong());
}

/// @brief outstream operator overloaded
/// @param outstream 
/// @param Location class object
/// @return returns the overloaded operator right hand operand
ostream& operator<< (ostream& out, const Location &loc)
{
	out << loc.getZipCode() << ' ' 
		<< loc.getName() << ' ' 
		<< loc.getState() << ' '
		<< loc.getCounty() << ' '
		<< loc.getLat() << ' '
		<< loc.getLong() << ' ';
	return out;
}

/// @brief less than comparison operator overloaded
/// @param Location class object
/// @return returns the overloaded operator's greater operand
bool  Location :: operator< (const Location &loc) const
{
	return getState() < loc.getState();
}

/// @brief less than comparison operator overloaded
/// @param Location class object
/// @return returns the overloaded operator's least operand
bool  Location :: operator> (const Location &loc) const
{
	return getState() > loc.getState();
}

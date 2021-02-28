#include "Location.h"
#include <sstream>


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

string Location :: getZipCode() const { return zipcode; }
string Location :: getName() const { return name; }
string Location :: getCounty() const { return county; }
string Location :: getState() const { return state; }
float Location :: getLat() const { return latitude; }
float Location :: getLong() const { return longitude; }

void Location :: setZipCode(string val) { zipcode = val; }
void Location :: setName(string val) { name = val; }
void Location :: setCounty(string val) { county = val; }
void Location :: setState(string val) { state = val; }
void Location :: setLat(float val) { latitude = val; }
void Location :: setLong(float val) { longitude = val; }

void Location :: operator= (const Location &loc)
{
	setZipCode(loc.getZipCode());
	setName(loc.getName());
	setState(loc.getState());
	setCounty(loc.getCounty());
	setLat(loc.getLat());
	setLong(loc.getLong());
}

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

bool  Location :: operator< (const Location &loc) const
{
	return getState() < loc.getState();
}

bool  Location :: operator> (const Location &loc) const
{
	return getState() > loc.getState();
}

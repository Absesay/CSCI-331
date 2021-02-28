///*************************************************************
/// @author Authors: Ben Olson, Gia Dat Diep
///					 Moffat Omuya, Sandesh Raj and Abraham Sesay
/// 
/// @details Location.h and associated .cpp file describe
/// a record type class that stores Zipcode, City, County 
/// and Coordinates
/// 
///*************************************************************

#ifndef LOCATION_HEADER
#define LOCATION_HEADER

#include "DelimBuffer.h"
#include <string>
#include <iostream>

using namespace std;

class Location
{       
    public:
         /** Default constructor */
        Location()
        {
            zipcode = " ";
            name = " ";
            county = " ";
            state = " ";
            latitude = 0;
            longitude = 0;
        };
        Location(string a, string b, string c, string d, float e, float f)
        {
            zipcode = a;
            name = b;
            county = c;
            state = d;
            latitude = e;
            longitude = f;
        };
        Location(const Location& loc)
        {
            zipcode = loc.getZipCode();
            name = loc.getName();
            county = loc.getCounty();
            state = loc.getCounty();
            latitude = loc.getLat();
            longitude = loc.getLong();
        };
        
		/** Access zipcode
         * @return The current value of zipcode
         */
        string getZipCode() const;
        /** Set zipcode
         * @param val New value to set
         */
        void setZipCode(string val);
        /** Access name
         * @return The current value of name
         */
        string getName() const;
        /** Set name
         * @param val New value to set
         */
        void setName(string val);
        /** Access county
         * @return The current value of county
         */
        string getCounty() const;
        /** Set county
         * @param val New value to set
         */
        void setCounty(string val);
        /** Access state
         * @return The current value of state
         */
        string getState() const;
        /** Set state
         * @param val New value to set
         */
        void setState(string val);
        /** Access lat
         * @return The current value of lat
         */
        float getLat() const;
        /** Set lat
         * @param val New value to set
         */
        void setLat(float val);
        /** Access long
         * @return The current value of long
         */
        float getLong() const;
        /** Set long
         * @param val New value to set
         */
        void setLong(float val);
        /**
         */
        bool unpack(DelimBuffer &buffer);
        /**
         */
        void operator= (const Location &loc);
        /**
         */
    	friend ostream& operator<< (ostream& out, const Location &loc);
		
		bool operator< (const Location &loc) const;
		
		bool operator> (const Location &loc) const;
        
    private:
        string zipcode; //!< Member variable "zipcode"
        string name; //!< Member variable "name"
        string county; //!< Member variable "county"
        string state; //!< Member variable "state"
        float latitude; //!< Member variable "lat"
        float longitude; //!< Member variable "long"
};
#endif
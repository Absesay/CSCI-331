///*************************************************************
/// @file Location.h
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

        /// @brief overloaded constructor
        /// @param string a sets zipcode
        /// @param string b sets name of place
        /// @param string c sets name of county
        /// @param string d sets two letter state code
        /// @param float e sets the latitude value
        /// @param float f sets the longitude value
        Location(string a, string b, string c, string d, float e, float f)
        {
            zipcode = a;
            name = b;
            county = c;
            state = d;
            latitude = e;
            longitude = f;
        };

        /// @brief copy constructor
        /// @param passes a Location object to create another object
        Location(const Location& loc)
        {
            zipcode = loc.getZipCode();
            name = loc.getName();
            county = loc.getCounty();
            state = loc.getState();
            latitude = loc.getLat();
            longitude = loc.getLong();
        };
        
		/** Access zipcode
         * @return The current value of zipcode
         */
        string getZipCode() const;
        /** Set zipcode
         * @param val New value to set
         * @post sets val to the zipCode
         */
        void setZipCode(string val);
        /** Access name
         * @return The current value of name
         */
        string getName() const;
        /** Set name
         * @param val New value to set
         * @post sets val to Name
         */
        void setName(string val);
        /** Access county
         * @return The current value of county
         */
        string getCounty() const;
        /** Set county
         * @param val New value to set
         * @post sets val to County
         */
        void setCounty(string val);
        /** Access state
         * @return The current value of state
         */
        string getState() const;
        /** Set state
         * @param val New value to set
         * @post sets val to State
         */
        void setState(string val);
        /** Access lat
         * @return The current Latitude value
         */
        float getLat() const;
        /** Set latitude
         * @param val New value to set
         * @post sets val to Latitude
         */
        void setLat(float val);
        /** Access long
         * @return The current Longitude value
         */
        float getLong() const;
        /** Set long
         * @param val New value to set
         * @post sets val to Longitude
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
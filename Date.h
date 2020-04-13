/*=====================================================================*
 | Declaration file Date.h
 |    declares : 	Date class
 |
 | For more informations (creation date, creator, etc.), please see the
 | corresponding .cpp file
 |
 *=====================================================================*/

#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <string>
#include <sstream>
#include <ostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "ErrorPersonVector.h"
#include "Typedef.h"

/**
* Very simple date class to user dates with persons
* use only dd\mm\aaaa to set a date, no check do on setting
*
* @author	Valentin Delaye
* @version	1.0
*/
class Date
{

    private :

    // Date information
    USINT day;
    USINT month;
    USINT year;

    public :

    /**
    * Constructor
    * Construct with no information
    *
    * @return USINT : the id
    */
    Date();

    /**
    * Constructor
    * Construct a date form a dd\mm\aaaa string format
    *
    * @return USINT : the id
    */
    Date(std::string date);

    /**
    * setDate
    * Construct a date form a dd\mm\aaaa string format
    *
    * @return bool : true, date has been seted corectly. False else
    */
    bool setDate(std::string date);

    /**
    * getDay
    * Get the day
    *
    * @return USINT : the day
    */
    USINT getDay() const;

    /**
    * getMonth
    * Get the month
    *
    * @return USINT : the month
    */
    USINT getMonth() const;

    /**
    * getYear
    * Get the day
    *
    * @return USINT : the day
    */
    USINT getYear() const;

    /**
    * toString
    * Return string from the date. The format is jj/mm/aaaa
    *
    * @return string : the date
    */
    std::string toString();

    /**
    * operator ==
    * Compare to date
    *
    * @return bool
    */
    bool operator == (Date date);

    /**
    * operator !=
    * Compare to date
    *
    * @return bool
    */
    bool operator != (Date date);

    /**
    * operator <
    * Compare to date
    *
    * @return bool
    */
    bool operator < (Date date);

    /**
    * operator >
    * Compare to date
    *
    * @return bool
    */
    bool operator > (Date date);

    /**
    * operator <=
    * Compare to date
    *
    * @return bool
    */
    bool operator <= (Date date);

    /**
    * operator >=
    * Compare to date
    *
    * @return bool
    */
    bool operator >= (Date date);

    /**
    * getMaxDay
    * Get maximum day of a year. Return 0 if not valid
    *
    * @return USINT : the day
    */
    static USINT getMaxDay(USINT month, USINT year);

    /**
    * isBissextileYear
    * Return if the year is bissextile
    *
    * @return bool : true, the year is bissextile. False else
    */
    static bool isBissextileYear(USINT year);

    /**
    * parse
    * Parse a string of date and return infos and if correct
    *
    * @return bool : true, the date is correct. False else
    */
    static bool parse(std::string date, USINT & day, USINT & month, USINT & year);

    /**
    * verify
    * Verify a date. Use parse function
    *
    * @return bool : true, the date is correct. False else
    */
    static bool verify(std::string date);

    private :

    /**
    * operator <<
    * Put a date into a flush
    *
    * @return ostream &
    */
    friend std::ostream & operator << (std::ostream & os, Date date);

};

#endif // DATE_H_INCLUDED

/*==============================================================*
 | Implementation file Date.cpp
 |    implements : Date class
 |
 | Creator : Valentin Delaye
 | Creation date : 24.08.2009
 |
 | Modification tag : -
 |
 | Version of the file : 1.0
 |
 *==============================================================*/

#include "Date.h"

/**
* Constructor
* Construct with no information
*
* @return USINT : the id
*/
Date::Date() {}

/**
* Constructor
* Construct a date form a dd\mm\aaaa string format
*
* @return USINT : the id
*/
Date::Date(std::string date)
{
    if(!this->setDate(date))
        throw new ErrorPersonVector("Impossible de setter la date");
}

/**
* setDate
* Construct a date form a dd\mm\aaaa string format
*
* @return bool : true, date has been seted corectly. False else
*/
bool Date::setDate(std::string date)
{

    // To recup info
    USINT l_day;
    USINT l_month;
    USINT l_year;

    // Its correct
    if(this->parse(date, l_day, l_month, l_year))
    {
        this->day = l_day;
        this->month = l_month;
        this->year = l_year;
        return true;
    }
    else
        return false;
}

/**
* getDay
* Get the day
*
* @return USINT : the day
*/
USINT Date::getDay() const
{
    return this->day;
}

/**
* getMonth
* Get the month
*
* @return USINT : the month
*/
USINT Date::getMonth() const
{
    return this->month;
}

/**
* getYear
* Get the day
*
* @return USINT : the day
*/
USINT Date::getYear() const
{
    return this->year;
}

/**
* toString
* Return string from the date. The format is jj/mm/aaaa
*
* @return USINT : the day
*/
std::string Date::toString()
{
    std::ostringstream flux;

    // Add 0 if necessary
    if (this->getDay() < 10)
        flux << '0' << this->getDay();
    else
        flux << this->getDay();

    // Add separator
    flux << "\\";

    if (this->getMonth() < 10)
        flux << '0' << this->getMonth();
    else
        flux << this->getMonth();

    // Add separator and year
    flux << "\\" << this->getYear();

    return flux.str();
}

/**
* operator ==
* Compare to date
*
* @return bool
*/
bool Date::operator == (Date date)
{
    return this->getDay() == date.getDay() &&
    this->getMonth() == date.getMonth() &&
    this->getYear() == date.getYear();
}

/**
* operator !=
* Compare to date
*
* @return bool
*/
bool Date::operator != (Date date)
{
    return !(*this == date);
}


/**
* operator <
* Compare two date
*
* @return bool
*/
bool Date::operator < (Date date)
{
    // if the year is the same
    if(this->getYear() == date.getYear())
    {
        if(this->getMonth() == date.getMonth())
        {
            return this->getDay() < date.getDay();
        }

        //Just compare the moth if they aren't the same
        else
            return this->getMonth() < date.getMonth();

    }

    // Just compare the year if they aren't the same
    else
        return this->getYear() < date.getYear();

}

/**
* operator >
* Compare two date
*
* @return bool
*/
bool Date::operator > (Date date)
{
    // Not < but different of ==
    return !(*this < date) && *this != date;
}

/**
* operator <=
* Compare two date
*
* @return bool
*/
bool Date::operator <= (Date date)
{
    // < or ==
    return *this < date || *this == date;
}

/**
* operator >=
* Compare two date
*
* @return bool
*/
bool Date::operator >= (Date date)
{
    // > or ==
    return *this > date || *this == date;
}

/**
* getMaxDay
* Get maximum day of a year. Return 0 if not valid
*
* @return USINT : the day
*/
USINT Date::getMaxDay(USINT month, USINT year)
{
    switch(month)
    {
        // January
        case 1 :
            return 31u;
        // February
        case 2 :
            if (Date::isBissextileYear(year))
                return 29u;
            else
                return 28u;
        // March
        case 3 :
            return 31u;
        // April
        case 4 :
            return 30u;
        // May
        case 5 :
            return 31u;
        // June
        case 6 :
            return 30u;
        // July
        case 7 :
            return 31u;
        // August
        case 8 :
            return 31u;
        // September
        case 9 :
            return 30u;
        // October
        case 10 :
            return 31u;
        // November
        case 11 :
            return 30u;
        // December
        case 12 :
            return 31u;

        // Default
        default :
            return 0u;
    }
}

/**
* isBissextileYear
* Return if the year is bissextile
*
* @return bool : true, the year is bissextile. False else
*/
bool Date::isBissextileYear(USINT year)
{
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

/**
* verify
* Verify a date
*
* @return bool : true, the date is correct. False else
*/
bool Date::parse(std::string date, USINT & day, USINT & month, USINT & year)
{

    // New c string
    char * cstr = new char [date.size()+1];

    // Copy value and parse
    strcpy(cstr, date.c_str());
    day = atoi(strtok(cstr,"\\"));
    month = atoi(strtok(NULL,"\\"));
    year = atoi(strtok(NULL, "\\"));

    // Check if can convert
    if(day == 0 || month == 0 || year == 0)
        return false;

    // Check value
    else if (day > Date::getMaxDay(month, year) || month > 12 || year > 9999)
        return false;
    else
        return true;
}

/**
* verify
* Verify a date. Use parse function
*
* @return bool : true, the date is correct. False else
*/
bool Date::verify(std::string date)
{
    USINT l_day;
    USINT l_month;
    USINT l_year;
    return Date::parse(date, l_day, l_month, l_year);
}

/**
* operator <<
* Put a date into a flush
*
* @return ostream &
*/
std::ostream & operator << (std::ostream & os, Date date)
{
    return os << date.toString();
}

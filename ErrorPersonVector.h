/*=====================================================================*
 | Declaration file ErrorPersonVector.h
 |    declares : 	ErrorPersonVector class
 |
 | For more informations (creation date, creator, etc.), please see the
 | corresponding .cpp file
 |
 *=====================================================================*/

#ifndef ERRORPERSONVECTOR_H_INCLUDED
#define ERRORPERSONVECTOR_H_INCLUDED

#include <exception>
#include <string>
#include "Typedef.h"

/**
* Class of exception used in personVector, inherit from standard exception
*
* @author	Alexis Signer
* @version	1.0
*/
class ErrorPersonVector : public std::exception
{

    private:

    // Number of the error
    USINT m_number;

    // Message of the error
    std::string m_message;

    // Level of the error
    USINT m_level;

    public:

    /**
    * Constructor
    * Construct a new error with message, number of error and level (default value)
    *
    * @param string : message of erreor
    * @param USINT : number of the error
    * @param USINT : level of the error
    */
    ErrorPersonVector(const std::string & message, USINT number=0, USINT level=0) throw();

    /**
    * what
    * Return a C string of the error of message
    *
    * @return const char * : message of the curent the error
    */
    virtual const char* what() const throw();

    /**
    * getLevel
    * Return the level of the error
    *
    * @return USINT : level of the error

    */
    USINT getLevel() const throw();

    /**
    * destructor
    * delete the error
    *
    */
    virtual ~ErrorPersonVector() throw();

};

#endif // ERRORPERSONVECTOR_H_INCLUDED

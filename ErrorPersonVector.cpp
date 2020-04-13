/*==============================================================*
 | Implementation file ErrorPersonVector.cpp
 |    implements : ErrorPersonVector class
 |
 | Creator : Alexis Signer
 | Creation date : 24 aout 2009
 | Copyright: EIAJ, all rights reserved
 |
 | Modification tag : //MODIF1
 |
 | Version of the file : 1.0
 |
 *==============================================================*/

#include "ErrorPersonVector.h"

/**
* Constructor
* Construct a new error with message, number of error and level (default value)
*
* @param string : message of erreor
* @param USINT : number of the error
* @param USINT : level of the error
*/
ErrorPersonVector::ErrorPersonVector(const std::string & message, USINT number, USINT level) throw()
{
    this->m_number = number;
    this->m_message = message;
    this->m_level = level;
}

/**
* what
* Return a C string of the error of message
*
* @return const char * : message of the curent the error
*/
const char* ErrorPersonVector::what() const throw()
{
    return m_message.c_str();
}

/**
* getLevel
* Return the level of the error
*
* @return USINT : level of the error

*/
USINT ErrorPersonVector::getLevel() const throw()
{
    return m_level;
}

/**
* destructor
* delete the error
*
*/
ErrorPersonVector::~ErrorPersonVector() throw()
{}

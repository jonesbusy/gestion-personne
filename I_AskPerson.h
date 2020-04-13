/*=====================================================================*
 | Interface file I_AskPerson.h
 *=====================================================================*/

#ifndef I_ASKPERSON_H_INCLUDED
#define I_ASKPERSON_H_INCLUDED

#include <vector>
#include <string>
#include "ErrorMessages.h"

/**
* Interface to have a method to ask all information for creating a person
*
* @author	Valentin Delaye
* @version	1.0
*/
class I_AskPerson
{
    public :

    virtual std::vector<std::string> * askInfo() = 0;

};

#endif // I_ASKPERSON_H_INCLUDED

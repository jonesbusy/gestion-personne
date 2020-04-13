/*=====================================================================*
 | Interface file I_CompareComportement.h
 *=====================================================================*/

#ifndef I_COMPARECOMPORTEMENT_H_INCLUDED
#define I_COMPARECOMPORTEMENT_H_INCLUDED

#include "Person.h"

/**
* Interface to have a comportement to sort the vector
*
* @author	Valentin Delaye
* @version	1.0
*/
class I_CompareComportement
{
    public:

    /**
    * compare
    * Compare an information of two person
    *
    * @param Person * : person 1
    * @param Person * : person 2
    * @return bool    : result of comparison
    */
    virtual bool compare(Person * person1, Person * person2) = 0;

    /**
    * egality
    * Compare an information of two person
    *
    * @param Person * : person 1
    * @param Person * : person 2
    * @return bool    : result of comparison
    */
    virtual bool egality(Person * person1, Person * person2) = 0;

    /**
    * egality
    * Compare an information of a person a a string value
    *
    * @param Person * : person 1
    * @param string   : information to check
    * @return bool    : result of comparison
    */
    virtual bool egality(Person * person1, std::string) = 0;

};


#endif // I_COMPARECOMPORTEMENT_H_INCLUDED

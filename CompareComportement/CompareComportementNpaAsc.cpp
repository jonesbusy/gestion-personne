/*==============================================================*
 | Implementation file CompareComportementNpaAsc.cpp
 |    implements : CompareComportementNpaAsc class
 |
 | Creator : Valentin Delaye
 | Creation date : 25 aout 2009
 | Copyright: EIAJ, all rights reserved
 |
 | Modification tag : //MODIF1
 |
 | Version of the file : 1.0
 |
 *==============================================================*/

#include "CompareComportementNpaAsc.h"

/**
* compare
* Compare an information of two person
*
* @param Person * : person 1
* @param Person * : person 2
* @return bool    : result of comparison
*/
bool CompareComportementNpaAsc::compare(Person * person1, Person * person2)
{
    return person1->getNpa() > person2->getNpa();
}

/**
* egality
* Compare an information of two person
*
* @param Person * : person 1
* @param Person * : person 2
* @return bool    : result of comparison
*/
bool CompareComportementNpaAsc::egality(Person * person1, Person * person2)
{
    return person1->getNpa() == person2->getNpa();
}

/**
* egality
* Compare an information of a person a a string value
*
* @param Person * : person 1
* @param string   : information to check
* @return bool    : result of comparison
*/
bool CompareComportementNpaAsc::egality(Person * person1, std::string value)
{
    // Create string with npa
    if(!CheckPersonProfessorStudent::checkNpa(value))
        throw new ErrorPersonVector("La valeur du NPA n'est pas correcte");
    else
    {
        std::ostringstream toString;
        toString << person1->getNpa();
        return toString.str() == value;
    }
}

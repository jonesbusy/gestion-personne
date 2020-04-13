/*==============================================================*
 | Implementation file CompareComportementFirstNameDesc.cpp
 |    implements : CompareComportementFirstNameDesc class
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

#include "CompareComportementFirstNameDesc.h"

/**
* compare
* Compare an information of two person
*
* @param Person * : person 1
* @param Person * : person 2
* @return bool    : result of comparison
*/
bool CompareComportementFirstNameDesc::compare(Person * person1, Person * person2)
{
    return person1->getFirstName() < person2->getFirstName();
}

/**
* egality
* Compare an information of two person
*
* @param Person * : person 1
* @param Person * : person 2
* @return bool    : result of comparison
*/
bool CompareComportementFirstNameDesc::egality(Person * person1, Person * person2)
{
    return person1->getFirstName() == person2->getFirstName();
}

/**
* egality
* Compare an information of a person a a string value
*
* @param Person * : person 1
* @param string   : information to check
* @return bool    : result of comparison
*/
bool CompareComportementFirstNameDesc::egality(Person * person1, std::string value)
{
    // Check if valid format
    if (!CheckPersonProfessorStudent::checkFirstName(value))
        throw new ErrorPersonVector("Le prenom n'est pas valide");

    // Else compare
    else
        return person1->getFirstName() == value;
}

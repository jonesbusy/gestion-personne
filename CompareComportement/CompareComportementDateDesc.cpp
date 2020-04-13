/*==============================================================*
 | Implementation file CompareComportementDateDesc.cpp
 |    implements : CompareComportementDateDesc class
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

#include "CompareComportementDateDesc.h"

/**
* compare
* Compare an information of two person
*
* @param Person * : person 1
* @param Person * : person 2
* @return bool    : result of comparison
*/
bool CompareComportementDateDesc::compare(Person * person1, Person * person2)
{
    return *(person1->getBirthday()) < *(person2->getBirthday());
}

/**
* egality
* Compare an information of two person
*
* @param Person * : person 1
* @param Person * : person 2
* @return bool    : result of comparison
*/
bool CompareComportementDateDesc::egality(Person * person1, Person * person2)
{
    return *(person1->getBirthday()) == *(person2->getBirthday());
}

/**
* egality
* Compare an information of a person a a string value
*
* @param Person * : person 1
* @param string   : information to check
* @return bool    : result of comparison
*/
bool CompareComportementDateDesc::egality(Person * person1, std::string value)
{
    if(!CheckPersonProfessorStudent::checkBirthday(value))
        throw new ErrorPersonVector("Mauvais format de date ou la date n'est pas valide");
    else
        return *person1->getBirthday() == *(new Date(value));
}

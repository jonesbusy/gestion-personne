/*==============================================================*
 | Implementation file CompareComportementSalaryAsc.cpp
 |    implements : CompareComportementSalaryAsc class
 |
 | Creator : Valentin Delaye
 | Creation date : 20 aout 2009
 | Copyright: EIAJ, all rights reserved
 |
 | Modification tag : //MODIF1
 |
 | Version of the file : 1.0
 |
 *==============================================================*/

#include "CompareComportementSalaryAsc.h"
#include "../Professor.h"


/**
* compare
* Compare an information of two person
*
* @param Person * : person 1
* @param Person * : person 2
* @return bool    : result of comparison
*/
bool CompareComportementSalaryAsc::compare(Person * person1, Person * person2)
{
    Professor * professor1 = dynamic_cast<Professor *>(person1);
    Professor * professor2 = dynamic_cast<Professor *>(person2);

    // If bad cast (if compare professor with other person), down the person with propriety
    if (professor1 == NULL)
        return false;
    else if (professor2 == NULL)
        return true;
    else
        return professor1->getSalary() > professor2->getSalary();
}

/**
* egality
* Compare an information of two person
*
* @param Person * : person 1
* @param Person * : person 2
* @return bool    : result of comparison
*/
bool CompareComportementSalaryAsc::egality(Person * person1, Person * person2)
{
    Professor * professor1 = dynamic_cast<Professor *>(person1);
    Professor * professor2 = dynamic_cast<Professor *>(person2);

    // If bad cast (if compare professor with other person), down the person with propriety
    if (professor1 == NULL)
        return false;
    else if (professor2 == NULL)
        return false;
    else
        return professor1->getSalary() == professor2->getSalary();
}

/**
* egality
* Compare an information of a person a a string value
*
* @param Person * : person 1
* @param string   : information to check
* @return bool    : result of comparison
*/
bool CompareComportementSalaryAsc::egality(Person * person1, std::string value)
{
    // Try to cast
    Professor * professor = dynamic_cast<Professor *>(person1);

    // Cannot compare if is not a professor
    if (professor == NULL)
        return false;
    else
    {
        // If bad value
        if (!CheckPersonProfessorStudent::checkSalary(value))
            throw new ErrorPersonVector("Le salaire n'est pas valide");

        // Else compare
        else
        {
            // Create string with npa
            std::ostringstream toString;
            toString << professor->getSalary();
            return toString.str() == value;
        }
    }
}

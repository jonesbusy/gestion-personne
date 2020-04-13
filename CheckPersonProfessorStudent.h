/*=====================================================================*
 | Declaration file CheckPersonProfessorStudent.h
 |    declares : 	CheckPersonProfessorStudent class
 |
 | For more informations (creation date, creator, etc.), please see the
 | corresponding .cpp file
 |
 *=====================================================================*/

#ifndef CHECKPERSONPROFESSORSTUDENT_H_INCLUDED
#define CHECKPERSONPROFESSORSTUDENT_H_INCLUDED

#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>

#include "I_CheckPerson.h"
#include "Typedef.h"
#include "Date.h"

/**
* Factory for creating students or professors (based on number of parameters)
*
* @author	Valentin Delaye
* @version	1.0
*/
class CheckPersonProfessorStudent : public I_CheckPerson
{

    public :

    /**
    * checkInfos
    * Check all information contained in the vector of string
    *
    * @param vector<string> & : informations to be verified
    * @return bool - true : correct / false : wrong
    */
    bool checkInfos(std::vector<std::string> &);

    /**
    * checkLastName
    * Verifies that the name in parameter is in a correct format
    *
    * @param string _lastName : The name that needs to be verified
    * @return bool - true : correct / false : wrong
    */
    static bool checkLastName(std::string & _lastName);

    /**
    * checkFirstName
    * Verifies that the name in parameter is in a correct format
    *
    * @param string _firstName : The name that needs to be verified
    * @return bool - true : correct / false : wrong
    */
    static bool checkFirstName(std::string & _firstName);

    /**
    * checkBirthday
    * Verifies that the birthday in parameter is in a correct format
    *
    * @param string _birthday : The birthday that needs to be verified
    * @return bool - true : correct / false : wrong
    */
    static bool checkBirthday(std::string & _birthday);

    /**
    * checkAdress
    * Verifies that the road name in parameter is in a correct format
    *
    * @param string _adress : The road name that needs to be verified
    * @return bool - true : correct / false : wrong
    */
    static bool checkAdress(std::string & _adress);

    /**
    * checkNumber
    * Verifies that the number of the house in parameter is in a correct format
    *
    * @param string _number : The number of the house that needs to be verified
    * @return bool - true : correct / false : wrong
    */
    static bool checkNumber(std::string & _number);

    /**
    * checkNpa
    * Verifies that the NPA in parameter is in a correct format
    *
    * @param string _npa : The NPA that needs to be verified
    * @return bool - true : correct / false : wrong
    */
    static bool checkNpa(std::string & _npa);

    /**
    * checkSalary
    * Verifies that the string in parameter is in the correct salary format
    *
    * @param string _salary : The string that needs to be verified
    * @return bool - true : correct / false : wrong
    */
    static bool checkSalary(std::string & _salary);

};


#endif // CHECKPERSONPROFESSORSTUDENT_H_INCLUDED

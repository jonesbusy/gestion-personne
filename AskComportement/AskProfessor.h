/*=====================================================================*
 | Declaration file AskProfessor.h
 |    declares : 	AskProfessor class
 |
 | For more informations (creation date, creator, etc.), please see the
 | corresponding .cpp file
 |
 *=====================================================================*/

#ifndef ASKPROFESSOR_H_INCLUDED
#define ASKPROFESSOR_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "../Typedef.h"
#include "../I_AskPerson.h"
#include "../CheckPersonProfessorStudent.h"

/**
* Implements the interface I_AskPerson, define the methods to ask information
* to create professor. Use CheckPersonProfessorStudent class to check informations
*
* @author	Valentin Delaye
* @version	1.0
*/
class AskProfessor : public I_AskPerson
{

    public :

    /**
    * askInfo
    * Ask to the user all informations for creating a professor, then return
    * vector of information
    *
    * @return vector<string> : the vector of informations
    */
    std::vector<std::string> * askInfo();

    /**
    * askMethod
    * Template for a methode of asking
    *
    * @param string : message for user
    * @param string : message if error
    * @param bool(* checker)(std::string) : pointer of function for the checking
    * @return UINT : salary
    */
    std::string askMethod(std::string messageInvit, std::string messageError, bool(* checker)(std::string&));

    /**
    * askLastName
    * Ask to the user the last name of professor
    *
    * @return string : last name
    */
    std::string askLastName();

    /**
    * askFirstName
    * Ask to the user the first name of professor
    *
    * @return string : first name
    */
    std::string askFirstName();

    /**
    * askBirthday
    * Ask to the user the birthday of professor
    *
    * @return string : birthday
    */
    std::string askBirthday();

    /**
    * askAdress
    * Ask to the user the adress of professor
    *
    * @return string : adress
    */
    std::string askAdress();

    /**
    * askNumber
    * Ask to the user the street number of professor
    *
    * @return USINT : street number
    */
    USINT askNumber();

    /**
    * askNpa
    * Ask to the user the npa of professor
    *
    * @return USINT : npa
    */
    USINT askNPA();

    /**
    * askSalary
    * Ask to the user the salary of professor
    *
    * @return UINT : salary
    */
    UINT askSalary();

};


#endif // ASKPROFESSOR_H_INCLUDED

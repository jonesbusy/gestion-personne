/*==============================================================*
 | Implementation file AskStudent.cpp
 |    implements : AskStudent class
 |
 | Creator : Valentin Delaye
 | Creation date : 23 aout 2009
 | Copyright: EIAJ, all rights reserved
 |
 | Modification tag : //MODIF1
 |
 | Version of the file : 1.0
 |
 *==============================================================*/

#include "AskStudent.h"

std::vector<std::string> * AskStudent::askInfo()
{

    std::cout << std::endl << "Veuillez saisir les informations de l'etudiant " << std::endl;
    std::cout              << "-----------------------------------------------" << std::endl;

    // Create new vector of informations
    std::vector<std::string> * infos = new std::vector<std::string>();
    infos->push_back(this->askLastName());
    infos->push_back(this->askFirstName());
    infos->push_back(this->askBirthday());
    infos->push_back(this->askAdress());

    // Convert int trop string (for number, npa and salary)

    // Ask Street number
    std::ostringstream * convert = new std::ostringstream();
    *convert << this->askNumber();
    infos->push_back(convert->str());

    // Ask NPA
    convert = new std::ostringstream();
    *convert << this->askNPA();
    infos->push_back(convert->str());

    // Return vector of information
    return infos;
}

/**
* askMethod
* Template for a methode of asking
*
* @param string : message for user
* @param string : message if error
* @param bool(* checker)(std::string) : pointer of function for the checking
* @return UINT : salary
*/
std::string AskStudent::askMethod(std::string messageInvit, std::string messageError, bool(* checker)(std::string&))
{
    // For getting info
    std::string info;

    do
    {
        std::cout << messageInvit << " : ";
        getline (std::cin, info);
    }
    // Call the checker
    while (!checker(info) && std::cout << messageError << std::endl);
    return info;
}

/**
* askLastName
* Asks for the last name and calls the verifier to make sure  it's a correct format
*
* @return a string - the last name that the user inputs
*/
std::string AskStudent::askLastName()
{
    return this->askMethod("Donnez le nom de famille", errorName, CheckPersonProfessorStudent::checkLastName);
}
/**
* askFirstName
* Asks for the first name and calls the verifier to make sure  it's a correct format
*
* @return a string - the first name that the user inputs
*/
std::string AskStudent::askFirstName()
{
    return this->askMethod("Donnez le prenom", errorName, CheckPersonProfessorStudent::checkFirstName);
}
/**
* askBirthday
* Asks for the birthday and calls the verifier to make sure  it's a correct format
*
* @return a string - the birthday that the user inputs
*/
std::string AskStudent::askBirthday()
{
    return this->askMethod("Donnez la date de naissance [jj\\mm\\aaaa]", errorDate, CheckPersonProfessorStudent::checkBirthday);
}
/**
* askAdress
* Asks for the name of the street (Adress) and calls the verifier to make sure  it's a correct format
*
* @return a string - the Adress that the user inputs
*/
std::string AskStudent::askAdress()
{
    return this->askMethod("Donnez le nom de la rue", errorAdress, CheckPersonProfessorStudent::checkAdress);
}
/**
* askNumber
* Asks for the number of the house and calls the verifier to make sure it's a correct format
*
* @return an USINT - the number of the house that the user inputs
*/
USINT AskStudent::askNumber()
{
    return atoi(this->askMethod("Donnez le numero de rue [1-999]", errorNumber, CheckPersonProfessorStudent::checkNumber).c_str());
}
/**
* askNPA
* Asks for the NPA and calls the verifier to make sure it's a correct format
*
* @return an USINT - the NPA that the user inputs
*/
USINT AskStudent::askNPA()
{
    return atoi(this->askMethod("Donnez le numero postal [1000-9999]", errorNumber, CheckPersonProfessorStudent::checkNpa).c_str());
}

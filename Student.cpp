/*==============================================================*
 | Implementation file Student.cpp
 |    implements : Student class
 |
 |
 | Creator : Valentin Delaye
 | Creation date : 17.08.2009
 |
 | Modification tag : -
 |
 | Version of the file : 1.0
 |
 *==============================================================*/


#include <iostream>
#include <sstream>
#include "Student.h"

/**
* Constructor
* Create a person with essential information
* @param std::string : last name of the person
* @param std::string : first name of the person
* @param std::string : birthday of the person (format jj\mm\aaaa)
* @param std::string : adress of the person
* @param USINT       : number of the street
* @param USINT       : npa of the person
*
*/
Student::Student(std::string lastName, std::string firstName, std::string birthday, std::string adress, USINT number, USINT npa) : Person(lastName, firstName, birthday, adress, number, npa)
{
}

/**
* display
* Display on screen the informations of the person
*
* @return void
*/
 void Student::display() const
 {
    std::cout << "ID : "<< this->getId()       << std::endl;
    std::cout << "Etudiant" << std::endl;
    std::cout << this->getLastName() << " " << this->getFirstName() << std::endl;
    std::cout << *this->getBirthday() << std::endl;
    std::cout << this->getAdress() << " " << this->getNumber() << std::endl;
    std::cout << "NPA : " << this->getNpa() << std::endl;
 }

 /**
* getInfos
* Return a vector with each informations about the Person
*
* @return std::vector<std::string>
*/
std::vector<std::string> Student::getInfos() const
{
    std::vector<std::string> l_sInfos;
    std::ostringstream * l_Stream = new std::ostringstream();

    l_sInfos.push_back(this->getLastName());
    l_sInfos.push_back(this->getFirstName());
    l_sInfos.push_back(this->getBirthday()->toString());
    l_sInfos.push_back(this->getAdress());

    *l_Stream << this->getNumber();
    l_sInfos.push_back(l_Stream->str());

    // Purge the stream
    delete l_Stream;
    l_Stream = new std::ostringstream();

    *l_Stream << this->getNpa();
    l_sInfos.push_back(l_Stream->str());

    // Return vector of string
    return l_sInfos;
}

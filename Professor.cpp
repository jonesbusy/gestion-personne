/*==============================================================*
 | Implementation file Professor.cpp
 |    implements : Professor class
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
#include "Professor.h"

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
Professor::Professor(std::string lastName, std::string firstName, std::string birthday, std::string adress, USINT number, USINT npa, UINT salary) : Person(lastName, firstName, birthday, adress, number, npa)
{
    this->uSalary = salary;
}

/**
* getSalary
* Get the salary of the professor
*
* @return UINT
*/
UINT Professor::getSalary() const
{
    return this->uSalary;
}

/**
* setSalary
* Set the salary of the professor
*
* @param const UINT salary : the new salary
* @return void
*/
void Professor::setSalary(const UINT salary)
{
    this->uSalary = salary;
}

/**
* display
* Display on screen the informations of the professor
*
* @return void
*/
void Professor::display() const
{
    std::cout << "ID : "<< this->getId()       << std::endl;
    std::cout << "Professeur"        << std::endl;
    std::cout << this->getLastName() << " "                 << this->getFirstName() << std::endl;
    std::cout << *this->getBirthday() << std::endl;
    std::cout << this->getAdress()   << " "                 << this->getNumber() << std::endl;
    std::cout << "NPA : "            << this->getNpa()      << std::endl;
    std::cout << "Salaire : "        << this->getSalary()   << std::endl;
}

/**
* getInfos
* Return a vector with each informations about the Person
*
* @return std::vector<std::string>
*/
std::vector<std::string> Professor::getInfos() const
{
    std::vector<std::string> l_sInfos;
    std::ostringstream * l_Stream = new std::ostringstream();

    // Add informations
    l_sInfos.push_back(this->getLastName());
    l_sInfos.push_back(this->getFirstName());
    l_sInfos.push_back(this->getBirthday()->toString());
    l_sInfos.push_back(this->getAdress());

    *l_Stream << this->getNumber();
    l_sInfos.push_back(l_Stream->str());

    // Purge the stream
    l_Stream = new std::ostringstream();

    *l_Stream << this->getNpa();
    l_sInfos.push_back(l_Stream->str());

    // Purge the stream
    l_Stream = new std::ostringstream();

    *l_Stream << this->getSalary();
    l_sInfos.push_back(l_Stream->str());

    // Return vector of string
    return l_sInfos;
}

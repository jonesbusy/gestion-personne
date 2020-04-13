/*==============================================================*
 | Implementation file Person.cpp
 |    implements : Person class
 |
 | Creator : Valentin Delaye
 | Creation date : 17.08.2009
 |
 | Modification tag : -
 |
 | Version of the file : 1.0
 |
 *==============================================================*/
#include "Person.h"

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
Person::Person(std::string _lastName, std::string _firstName, std::string _birthday, std::string _adress, USINT _number, USINT _npa)
{
    this->sLastName = _lastName;
    this->sFirstName = _firstName;
    this->sAdress = _adress;
    this->sBirthday = new Date(_birthday);
    this->uNumber = _number;
    this->uNpa = _npa;
}

/**
* getId
* Get the id name of the person
*
* @return USINT : the id
*/
USINT Person::getId() const
{
    return this->uId;
}

/**
* getLastName
* Get the last name of the person
*
* @return std::string : last name of the person
*/
std::string Person::getLastName() const
{
    return this->sLastName;
}

/**
* getFirstName
* Get the last name of the person
*
* @return std::string : last name of the person
*/
std::string Person::getFirstName() const
{
    return this->sFirstName;
}

/**
* getBirthday
* Get the birthday of the person
*
* @return std::string : the birthday of the person
*/
Date * Person::getBirthday() const
{
    return this->sBirthday;
}

/**
* getAdress
* Get the adress of the person
*
* @return std::string : the adress of the person
*/
std::string Person::getAdress() const
{
    return this->sAdress;
}

/**
* getNumber
* Get the number of the street
*
* @return unsigned short int : the number of the street
*/
USINT Person::getNumber() const
{
    return this->uNumber;
}

/**
* getNpa
* Get the NPA
*
* @return unsigned short int : the NPA
*/
USINT Person::getNpa() const
{
    return this->uNpa;
}


// Mutators

/**
* setId
* Set new id for the person
*
* @param USINT : the id to set
* @return void
*/
void Person::setId(const USINT _id)
{
    this->uId = _id;
}

/**
* setLastName
* Set the last name of the person
*
* @param std::string lastName : The last name to set
* @return void
*/
void Person::setLastName(const std::string _lastName)
{
    this->sLastName = _lastName;
}

/**
* setFirstName
* Set the first name of the person
*
* @param std::string firstName : The first name to set
* @return void
*/
void Person::setFirstName(const std::string _firstName)
{
    this->sFirstName = _firstName;
}

/**
* setBirthday
* Set the birthday of the person
*
* @param std::string birthday : The birthday to set
* @return void
*/
void Person::setBirthday(const std::string _birthday)
{
    this->sBirthday = new Date(_birthday);
}

/**
* setAdress
* Set the adress of the person
*
* @param std::string adress : The adress to set
* @return void
*/
void Person::setAdress(const std::string _adress)
{
    this->sAdress = _adress;
}

/**
* setNumber
* Set the number of the street
*
* @param std::string number : The number to set
* @return void
*/
void Person::setNumber(const USINT _number)
{
    this->uNumber = _number;
}

/**
* setNpa
* Set the npa
*
* @param std::string npa : The npa to set
* @return void
*/
void Person::setNpa(const USINT _npa)
{
    this->uNpa = _npa;
}

/**
* compare
* Compare to person
*
* @param Person * person : person to compare
* @return bool : true, person are the same, false else
*/
bool Person::compare(Person * person)
{
    return this->getLastName() == person->getLastName() &&
    this->getFirstName() == person->getFirstName() &&
    *this->getBirthday() == *person->getBirthday();
}

// Virtual destructor
Person::~Person() {};

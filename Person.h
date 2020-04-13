/*=====================================================================*
 | Declaration file Person.h
 |    declares : 	Person class
 |
 | For more informations (creation date, creator, etc.), please see the
 | corresponding .cpp file
 |
 *=====================================================================*/

#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include <string>
#include <iostream>
#include <vector>
#include "Date.h"
#include "Typedef.h"

/**
* Abstract class of proprieties of a person
*
* @author	Valentin Delaye
* @version	1.0
*/
class Person
{

    protected :

    // Unique id of the person
    USINT uId;

    // Attributes

    // Last name
    std::string sLastName;
    // First name
    std::string sFirstName;
    // Birthday
    Date * sBirthday;
    // Adress
    std::string sAdress;
    // Number of the street
    USINT uNumber;
    // Npa
    USINT uNpa;

    public :

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
    Person(std::string _lastName, std::string _firstName, std::string _birthday, std::string _adress, USINT _number, USINT _npa);

    // Accessor

    /**
    * getId
    * Get the id name of the person
    *
    * @return USINT : the id
    */
    USINT getId() const;

    /**
    * getLastName
    * Get the last name of the person
    *
    * @return std::string : last name of the person
    */
    std::string getLastName() const;

    /**
    * getFirstName
    * Get the last name of the person
    *
    * @return std::string : last name of the person
    */
    std::string getFirstName() const;

    /**
    * getBirthday
    * Get the birthday of the person
    *
    * @return std::string : the birthday of the person
    */
    Date * getBirthday() const;

    /**
    * getAdress
    * Get the adress of the person
    *
    * @return std::string : the adress of the person
    */
    std::string getAdress() const;

    /**
    * getNumber
    * Get the number of the street
    *
    * @return unsigned short int : the number of the street
    */
    USINT getNumber() const;

    /**
    * getNpa
    * Get the NPA
    *
    * @return unsigned short int : the NPA
    */
    USINT getNpa() const;

    // Mutators

    /**
    * setId
    * Set new id for the person
    *
    * @param USINT : the id to set
    * @return void
    */
    void setId(USINT _id);

    /**
    * setLastName
    * Set the last name of the person
    *
    * @param std::string lastName : The last name to set
    * @return void
    */
    void setLastName(const std::string _lastName);

    /**
    * setFirstName
    * Set the first name of the person
    *
    * @param std::string firstName : The first name to set
    * @return void
    */
    void setFirstName(const std::string _firstName);

    /**
    * setBirthday
    * Set the birthday of the person
    *
    * @param std::string birthday : The birthday to set
    * @return void
    */
    void setBirthday(const std::string _birthday);

    /**
    * setAdress
    * Set the adress of the person
    *
    * @param std::string adress : The adress to set
    * @return void
    */
    void setAdress(const std::string _adress);

    /**
    * setNumber
    * Set the number of the street
    *
    * @param std::string number : The number to set
    * @return void
    */
    void setNumber(const USINT _number);

    /**
    * setNpa
    * Set the npa
    *
    * @param std::string npa : The npa to set
    * @return void
    */
    void setNpa(const USINT _npa);

    /**
    * compare
    * Compare to person
    *
    * @param Person * person : person to compare
    * @return bool : true, person are the same, false else
    */
    virtual bool compare(Person * person);

    /**
    * display
    * Display on screen the informations of the person
    *
    * @return void
    */
    virtual void display() const = 0;

    /**
    * getInfos
    * Return a vector with each informations about the Person
    *
    * @return std::vector<std::string>
    */
    virtual std::vector<std::string> getInfos() const = 0;

    /**
    * Destructor
    * Virtual destructor. Delete the person
    *
    */
    virtual ~Person();

};


#endif // PERSON_H_INCLUDED

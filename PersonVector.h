/*=====================================================================*
 | Declaration file PersonVector.h
 |    declares : 	PersonVector class
 |
 | For more informations (creation date, creator, etc.), please see the
 | corresponding .cpp file
 |
 *=====================================================================*/


#ifndef ACTIONVECTOR_H_INCLUDED
#define ACTIONVECTOR_H_INCLUDED

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

#include "Person.h"
#include "Professor.h"
#include "Student.h"

#include "I_CompareComportement.h"
#include "I_FactoryPerson.h"
#include "I_CheckPerson.h"
#include "I_AskPerson.h"
#include "I_Parser.h"
#include "ErrorPersonVector.h"

#define FIRST_ID 1

/**
* Some action on the vector of Person
*
* @author	Valentin Delaye
* @version	1.0
*/
class PersonVector
{

    protected :

    // Name of the file
    std::string sName;

    // Last id of the person
    USINT lastId;

    // The vector, list of the person
    std::vector<Person *> list;

    // Comportement of sorting
    I_CompareComportement * compareComportement;

    // Comportement of creating concrete object
    I_FactoryPerson * factory;

    // Comportement for add a person from user
    I_AskPerson * askPerson;

    // Comportement for checking informations
    I_CheckPerson * checkFile;

    // Parser
    I_Parser * parser;

    public :

    /**
    * Constructor
    * Construct new vector with filename and comportement
    *
    * @param std::string fileName : the name or path of the file
    * @param I_CompareComportement * : the comportement of sorting
    * @param I_AskComportement *  : the comportement for ask person
    * @param I_CheckPerson     *  : the comportement of checking parameters
    * @param I_Parser          *  : parser for the file
    */
    PersonVector(std::string _fileName, I_CompareComportement * _compareComportement, I_FactoryPerson * _factory,
                              I_AskPerson * _askComportement, I_CheckPerson * _checkComportement,
                              I_Parser * _parser);

    /**
    * Constructor
    * Construct new vector with no param
    *
    */
    PersonVector();

    /**
    * add
    * This function add a person to the vector
    *
    * @param Person* thePerson : The person to add
    * @return void
    */
    void add(Person * _thePerson);

    /**
    * del
    * This function delete a person to the vector
    *
    * @param Person * person : the person to delete
    * @return void
    */
    void del(Person * _person);

    /**
    * modify
    * This function modify the informations of a person in the vector
    *
    * @param Person * : the person to modify
    * @return void
    */
    void modify(Person * _person);

    /**
    * search
    * This function search a information contain in a person
    *
    * @param string : information to search
    * @return vector<Person *> : a vector of person
    */
    std::vector<Person *> * search(std::string value);

    /**
    * showList
    * This show the list of the person
    *
    * @return void
    */
    void showList();

    /**
    * getSize
    * Get the number of person in the vector
    *
    * @param
    * @return unsigned int : number of person
    */
    UINT getSize();

    /**
    * getFileName
    * Return the name of file
    *
    * @return std::string : name of the file
    */
    std::string getFileName();

    /**
    * getPersonFromPosition
    * Get a person from a position in the vector
    *
    * @param
    * @return Person* : the person
    */
    Person * at(UINT _position) throw (ErrorPersonVector *);

    /**
    * getPersonFromId
    * Get a person from the id of the person in the vector
    *
    * @param
    * @return Person* : the person, return NULL if doesn't match
    */
    Person * getPersonFromId(UINT _id);

    /**
    * getLastId
    * Get the higher id in the list
    *
    * @return USINT : last id of the list
    */
    USINT getLastId();

    /**
    * getPosition
    * Get the position in the vector for a person
    *
    * @param
    * @return Person* : the person, throw exception if doesn't match
    */
    USINT getPosition(Person * _person) throw(ErrorPersonVector *);

    /**
    * setCompareComportement
    * Get the comportement of sorting
    *
    * @param I_CompareComportement * : the comportement to set
    * @return void
    */
    void setCompareComportement(I_CompareComportement * _comportement);

    /**
    * setAskComportement
    * Set comportement of asking
    *
    * @param I_AskPerson * : the comportement to set
    * @return void
    */
    void setAskComportement(I_AskPerson * _askComportement);

    /**
    * setCheckComportement
    * Set comportement of checking for parsing file
    *
    * @param I_CheckPerson * : the comportement to set
    * @return void
    */
    void setCheckComportement(I_CheckPerson * _checkComportement);

    /**
    * getCompareComportement
    * Get the comportement of sorting
    *
    * @return I_CompareComportement * : the comportement curent used
    */
    I_CompareComportement * getCompareComportement() const;

    /**
    * sort
    * Sort the vector with associated comportement. Use simple bubble sort
    *
    * @return void
    */
    void sort();

    /**
    * load
    * Read a file and add the informations in the vector
    *
    * @return bool : return false and generate an error message if the file can't be opened
    */
    void load() throw(ErrorPersonVector *);

    /**
    * save
    * Save a file with the informations contained in the vector
    *
    * @return bool : return false and generate an error message if the file can't be saved
    */
    void save() throw(ErrorPersonVector *);

    /**
    * ask
    * Ask from user different kind of informations about the person, finally add it
    *
    * @return void
    */
    void ask();

    private :

    /**
    * checkExtension
    * Check if extension file is correct
    *
    * @param std::string extension : extension to check
    * @return bool : True file extension correct, false else
    */
    bool checkExtension(std::string fileName, std::string extension);

};

#endif // ACTIONVECTOR_H_INCLUDED

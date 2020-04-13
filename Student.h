/*=====================================================================*
 | Declaration file Student.h
 |    declares : 	Student class
 |
 | For more informations (creation date, creator, etc.), please see the
 | corresponding .cpp file
 |
 *=====================================================================*/

#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include "Person.h"

/**
* Reprensent a student
*
* @author	Valentin Delaye
* @version	1.0
*/
class Student : public Person
{

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
    Student(std::string lastName, std::string firstName, std::string birthday, std::string adress, USINT number, USINT npa);

    /**
    * display
    * Display on screen the informations of the person
    *
    * @return void
    */
    void display() const;

    /**
    * getInfos
    * Return a vector with each informations about the Person
    *
    * @return std::vector<std::string>
    */
    std::vector<std::string> getInfos() const;

};


#endif // STUDENT_H_INCLUDED

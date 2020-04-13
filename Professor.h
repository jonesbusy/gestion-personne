/*=====================================================================*
 | Declaration file Professor.h
 |    declares : 	Professor class
 |
 | For more informations (creation date, creator, etc.), please see the
 | corresponding .cpp file
 |
 *=====================================================================*/

#ifndef PROFESSOR_H_INCLUDED
#define PROFESSOR_H_INCLUDED

#include "Person.h"
#include "Typedef.h"

/**
* Reprensent a professor
*
* @author	Valentin Delaye
* @version	1.0
*/
class Professor : public Person
{
    private :

    // Salary of professort
    UINT uSalary;


    public :

    /**
    * Constructor
    * Create a professor with essential information
    * @param std::string : last name of the person
    * @param std::string : first name of the person
    * @param std::string : birthday of the person (format jj\mm\aaaa)
    * @param std::string : adress of the person
    * @param USINT       : number of the street
    * @param USINT       : npa of the person
    * @param
    *
    */
    Professor(std::string lastName, std::string firstName, std::string birthday, std::string adress, USINT number, USINT npa, UINT salary);

    /**
    * getSalary
    * Get the salary of the professor
    *
    * @return UINT
    */
    UINT getSalary() const;

   /**
    * setSalary
    * Set the salary of the professor
    *
    * @param const UINT salary : the new salary
    * @return void
    */
    void setSalary(const UINT salary);

    /**
    * display
    * Display on screen the informations of the professor
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

#endif // PROFESSOR_H_INCLUDED

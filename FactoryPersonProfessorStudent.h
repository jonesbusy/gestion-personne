/*=====================================================================*
 | Declaration file FactoryPersonProfessorStudent.h
 |    declares : 	FactoryPersonProfessorStudent class
 |
 | For more informations (creation date, creator, etc.), please see the
 | corresponding .cpp file
 |
 *=====================================================================*/

#ifndef FACTORYPERSONPROFESSORSTUDENT_H_INCLUDED
#define FACTORYPERSONPROFESSORSTUDENT_H_INCLUDED

#include <vector>
#include <string>
#include <cstdlib>
#include "I_FactoryPerson.h"
#include "Professor.h"
#include "Student.h"
#include "ErrorPersonVector.h"

/**
* Factory for creating students or professors (based on number of parameters)
*
* @author	Valentin Delaye
* @version	1.0
*/
class FactoryPersonProfessorStudent : public I_FactoryPerson
{
    public :

    /**
    * create
    * Method of creating a new concrete object (Professor or Student)
    * from vector of information. Use the number of parameters to decide
    * which class to return
    *
    * @param vector<string> : the vector of informations
    * @return Person * : the the instance of class
    */
    Person * create(std::vector<std::string> _infosList) throw (ErrorPersonVector *);
};


#endif // FACTORYPERSONPROFESSORSTUDENT_H_INCLUDED

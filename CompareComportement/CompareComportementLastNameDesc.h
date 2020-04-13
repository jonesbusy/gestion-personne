/*=====================================================================*
 | Declaration file CompareComportementLastNameDesc.h
 |    declares : 	CompareComportementLastNameDesc class
 |
 | For more informations (creation date, creator, etc.), please see the
 | corresponding .cpp file
 |
 *=====================================================================*/

#ifndef COMPARECOMPORTEMENTLASTNAMEDESC_H_INCLUDED
#define COMPARECOMPORTEMENTLASTNAMEDESC_H_INCLUDED

#include "../I_CompareComportement.h"
#include "../CheckPersonProfessorStudent.h"

/**
* Implementation for comparing the last name
*
* @author	Valentin Delaye
* @version	1.0
*/
class CompareComportementLastNameDesc : public I_CompareComportement
{

    public :


    /**
    * compare
    * Compare an information of two person
    *
    * @param Person * : person 1
    * @param Person * : person 2
    * @return bool    : result of comparison
    */
    bool compare(Person * person1, Person * person2);

    /**
    * egality
    * Compare an information of two person
    *
    * @param Person * : person 1
    * @param Person * : person 2
    * @return bool    : result of comparison
    */
    bool egality(Person * person1, Person * person2);

    /**
    * egality
    * Compare an information of a person a a string value
    *
    * @param Person * : person 1
    * @param string   : information to check
    * @return bool    : result of comparison
    */
    bool egality(Person * person1, std::string);

};

#endif // COMPARECOMPORTEMENTLASTNAMEDESC_H_INCLUDED

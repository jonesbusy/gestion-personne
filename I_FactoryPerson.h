/*=====================================================================*
 | Interface file I_FactoryPerson.h
 *=====================================================================*/

#ifndef I_FACTORYPERSON_INCLUDED
#define I_FACTORYPERSON_INCLUDED

#include "Person.h"
#include "Typedef.h"

/**
* Interface of the factory to create a person from a vector of information
*
* @author	Valentin Delaye
* @version	1.0
*/
class I_FactoryPerson
{
    public :

    /**
    * create
    * Method of creating a new concrete object
    * from vector of information.
    *
    * @param vector<string> : the vector of informations
    * @return Person * : the the instance of class
    */
    virtual Person * create(std::vector<std::string> _infosList) = 0;
};

#endif // I_FACTORYPERSON_INCLUDED

/*=====================================================================*
 | Interface file I_CheckPerson.h
 *=====================================================================*/

#ifndef I_CHECKPERSON_H_INCLUDED
#define I_CHECKPERSON_H_INCLUDED

#include <vector>
#include <string>

/**
* Interface to have a method to check all information contained in the vector of string
*
* @author	Valentin Delaye
* @version	1.0
*/
class I_CheckPerson
{
    public :

    virtual bool checkInfos(std::vector<std::string> &) = 0;
};

#endif // I_CHECKPERSON_H_INCLUDED

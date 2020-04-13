/*==============================================================*
 | Implementation file FactoryPersonProfessorStudent.cpp
 |    implements : FactoryPersonProfessorStudent class
 |
 | Creator : Valentin Delaye
 | Creation date : 19 aout 2009
 | Copyright: EIAJ, all rights reserved
 |
 | Modification tag : //MODIF1
 |
 | Version of the file : 1.0
 |
 *==============================================================*/

#include "FactoryPersonProfessorStudent.h"
#include <iostream>

/**
* create
* Method of creating a new concrete object (Professor or Student)
* from vector of information. Use the number of parameters to decide
* which class to return
*
* @param vector<string> : the vector of informations
* @return Person * : the the instance of class
*/
Person * FactoryPersonProfessorStudent::create(std::vector<std::string> _infosList) throw (ErrorPersonVector *)
{
    // Create concrete objects
    if (_infosList.size() == 7u)
        return new Professor(_infosList.at(0), _infosList.at(1), _infosList.at(2), _infosList.at(3),
                   (USINT) atoi(_infosList.at(4).c_str()),
                   (USINT) atoi(_infosList.at(5).c_str()),
                   (UINT)  atoi(_infosList.at(6).c_str()));
    // If only 6 parameters, its a student
    else if (_infosList.size() == 6u)
        return new Student(_infosList.at(0), _infosList.at(1), _infosList.at(2), _infosList.at(3),
                    (USINT) atoi(_infosList.at(4).c_str()),
                    (USINT) atoi(_infosList.at(5).c_str()));

    // Cannot create object with parameters
    else
        throw new ErrorPersonVector("Canno't create object with this factory ");
}

/*==============================================================*
 | Implementation file Option.cpp
 |    implements : Option class
 |
 |
 | Creator : Valentin Delaye and Aimé Elom Djagba
 | Creation date : 25.08.2009
 |
 | Modification tag : -
 |
 | Version of the file : 1.0
 |
 *==============================================================*/

#include "Option.h"

/**
* Constructor
* Construct an empty option
*
* @author	Valentin Delaye
* @version	1.0
*/
Option::Option() {}

/**
* Constructor
* Construct an complete option
*
* @param USINT no : numero to set
* @param string : the id of the option
* @param string : the texte of the option
* @author	Valentin Delaye
* @version	1.0
*/
Option::Option(const USINT no, std::string id, std::string text)
{
    // Initialize the members
    this->no    = no;
    this->id    = id;
    this->text = text;
}

/**
* Destructor
*
* @author	Valentin Delaye
* @version	1.0
*/
Option::~Option(){}

/**
* getNo
* Return the numero of the option
*
* @return USINT : the numero of the option
* @author Valentin Delaye
* @version 1.0
*/
USINT Option::getNo() const
{
    return this->no;
}

/**
* setNo
* Set the new numero for the option
*
* @param USINT no : the new numero of option
* @return void
* @author Valentin Delaye
* @version 1.0
*/
void Option::setNo(const USINT no)
{
    this->no = no;
}

/**
* getId
* Return the id of the option
*
* @return string : the id of the option
* @author	Valentin Delaye
* @version	1.0
*/
std::string Option::getId() const
{
    return this->id;
}

/**
* setId
* Set new id for the option
*
* @param string : new id
* @return void
* @author Valentin Delaye
* @version 1.0
*/
void Option::setId(std::string id)

{
    this->id = id;
}

/**
* getText
* Return the numero of the option
*
* @return USINT : the numero of the option
* @author Valentin Delaye
* @version 1.0
*/
std::string Option::getText() const
{
    return this->text;
}

/**
* setText
* Set new text for the option
*
* @param string : the new text
* @return void
* @author Valentin Delaye
* @version 1.0
*/
void Option::setText(std::string text)
{
    this->text = text;
}

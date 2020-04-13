/*=====================================================================*
 | Declaration file Option.h
 |    declares : 	Option class
 |
 | For more informations (creation date, creator, etc.), please see the
 | corresponding .cpp file
 |
 *=====================================================================*/

#ifndef OPTION_H_INCLUDED
#define OPTION_H_INCLUDED

#include <iostream>
#include <string>
#include "../Typedef.h"

/**
* Create un struct of option for class menu. The option
* is composed of a numero, id (short explicit string) and
* the text shows to the user
*
* @author	Valentin Delaye and Aimé Elom Djagba
* @version	1.0
*/
class Option
{

    private:

    USINT no;           // Number of option
    std::string id;     // Id of option
    std::string text;   // Text of option

    public:

    /**
    * Constructor
    * Construct an empty option
    *
    * @author	Valentin Delaye
    * @version	1.0
    */
    Option();

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
    Option(const USINT no, std::string id, std::string text);

    /**
    * Destructor
    *
    * @author	Valentin Delaye
    * @version	1.0
    */
    ~Option();

    /**
    * getNo
    * Return the numero of the option
    *
    * @return USINT : the numero of the option
    * @author Valentin Delaye
    * @version 1.0
    */
    USINT getNo() const;

    /**
    * setNo
    * Set the new numero for the option
    *
    * @param USINT no : the new numero of option
    * @return void
    * @author Valentin Delaye
    * @version 1.0
    */
    void setNo(const USINT no);

    /**
    * getId
    * Return the id of the option
    *
    * @return string : the id of the option
    * @author	Valentin Delaye
    * @version	1.0
    */
    std::string getId() const;

    /**
    * setId
    * Set new id for the option
    *
    * @param string : new id
    * @return void
    * @author Valentin Delaye
    * @version 1.0
    */
    void setId(std::string id);

    /**
    * getText
    * Return the numero of the option
    *
    * @return USINT : the numero of the option
    * @author Valentin Delaye
    * @version 1.0
    */
    std::string getText() const;

    /**
    * setText
    * Set new text for the option
    *
    * @param string : the new text
    * @return void
    * @author Valentin Delaye
    * @version 1.0
    */
    void setText(std::string text);

};

#endif // OPTION_H_INCLUDED

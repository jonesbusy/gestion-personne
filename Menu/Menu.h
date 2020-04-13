/*=====================================================================*
 | Declaration file Date.h
 |    declares : 	Date class
 |
 | For more informations (creation date, creator, etc.), please see the
 | corresponding .cpp file
 |
 *=====================================================================*/

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <string>
#include "Option.h"
#include "../Typedef.h"
#include "../ErrorPersonVector.h"


/**
* Create un struct of menu
*
*
* @author	Valentin Delaye
* @version	1.0
*/
class Menu
{
    private:

    // All option in the menu
    std::vector<Option *> listMenu;

    public:

    /**
    * Constructor
    * Construct an empty menu
    *
    * @author	Valentin Delaye
    * @version	1.0
    */
    Menu();

    /**
    * add
    * Add an option to the menu
    *
    * @param Option * : the option to add
    * @author	Valentin Delaye
    * @version	1.0
    */
    void add(Option *option) throw (ErrorPersonVector *);

    /**
    * del
    * Delete an option to the menu
    *
    * @param USINT no : the numero of the option to remove
    * @author	Valentin Delaye
    * @version	1.0
    */
    void del(const USINT no) throw (ErrorPersonVector *);

    /**
    * showMenu
    * Delete an option to the menu
    *
    * @param string : show at top of menu
    * @return void
    * @author	Valentin Delaye
    * @version	1.0
    */
    void showMenu (std::string invitation = "") const;

    /**
    * textOf
    * Return the text form the numero
    *
    * @param USINT no : the numero of the option
    * @return string : the text of the option
    * @author	Valentin Delaye
    * @version	1.0
    */
    std::string textOf(const USINT no) const throw (ErrorPersonVector *);

    /**
    * positionOf
    * Return the position from the numero
    *
    * @param USINT no : the numero of the option
    * @return USINT : the position of the option
    * @author	Valentin Delaye
    * @version	1.0
    */
    USINT positionOf(const USINT no) const throw (ErrorPersonVector *);

    /**
    * textOf
    * Return the texte from and id
    *
    * @param string : the id
    * @return string : the text
    * @author	Valentin Delaye
    * @version	1.0
    */
    std::string textOf(std::string id) const throw (ErrorPersonVector *);

    /**
    * listEmpty
    * Return if the menu is empty
    *
    * @author	Valentin Delaye
    * @return bool : True the list is empty, false else
    * @version	1.0
    */
    bool listEmpty() const;

    /**
    * size
    * Return the number of the option in the menu
    *
    * @author Valentin Delaye
    * @return USINT : size of the menu
    * @version	1.0
    */
    USINT size() const;

    /**
    * exist
    * Return if an option exist
    *
    * @param USINT : the number of option
    * @return bool : true the option exist, false else
    * @author Valentin Delaye
    * @version	1.0
    */
    bool exist(USINT no) const;

    /**
    * choiceOption
    * Ask the user to chose an option and return the number
    *
    * @param string : message to the user
    * @return USINT : the number of the option chosen
    * @author Valentin Delaye
    * @version	1.0
    */
    USINT choiceOption(std::string invitation) const;
};



#endif // MENU_H_INCLUDED

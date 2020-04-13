/*==============================================================*
 | Implementation file Menu.cpp
 |    implements : Menu class
 |
 | Creator : Aimé Elom Djagba et Valentin Delaye
 | Creation date : 25 aout 2009
 | Copyright: EIAJ, all rights reserved
 |
 | Modification tag : //MODIF1
 |
 | Version of the file : 1.0
 |
 *==============================================================*/

#include "Menu.h"

/**
* Constructor
* Construct an empty menu
*
* @author	Valentin Delaye
* @version	1.0
*/
Menu::Menu() {}

/**
* add
* Add an option to the menu
*
* @param Option * : the option to add
* @author	Valentin Delaye
* @version	1.0
*/
void Menu::add(Option * option) throw (ErrorPersonVector *)
{

    // If id or text is empty
    if (option->getText().empty() || option->getId().empty())
        throw new ErrorPersonVector("Erreur ! Impossible de charger une chaine vide");

    // Go through to search if option is not already present
    for (register USINT i = 0 ; i < this->listMenu.size() ; i ++)
    {
        // Idem or no or text do not have to be identical
        if (this->listMenu.at(i)->getId() == option->getId() ||
            this->listMenu.at(i)->getNo() == option->getNo() ||
            this->listMenu.at(i)->getText() == option->getText())
        {
            throw new ErrorPersonVector("Erreur ! Impossible d'ajouter le meme id, no ou texte !");
        }
    }

    //Add the option a the end
    this->listMenu.push_back(option);
}

/**
* del
* Delete an option to the menu
*
* @param USINT no : the numero of the option to remove
* @author	Valentin Delaye
* @version	1.0
*/
void Menu::del(const USINT no) throw (ErrorPersonVector *)
{
    //To save the number of option
    USINT sizelist = this->listMenu.size();

    // Iterate the vector
    for (register USINT i = 0 ; i < this->listMenu.size() ; i++)
    {
        // If they find option
        if (this->listMenu.at(i)->getNo() == no)
        {
            // Delete it
            this->listMenu.erase(this->listMenu.begin() + i);
            break;
        }

    }
    // If there was not change
    if (this->listMenu.size() == sizelist)
        throw new ErrorPersonVector("Erreur ! Option non trouvee");
}

/**
* showMenu
* Delete an option to the menu
*
* @param string : show at top of menu
* @return void
* @author	Valentin Delaye
* @version	1.0
*/
void Menu::showMenu (std::string invitation) const
{
    //Show invitation
    std::cout << std::endl << invitation << std::endl;
    std::cout << "==============================================" << std::endl;

    // Go through all options and show
    for (register USINT i = 0 ; i < this->listMenu.size() ; i++)
    {
       std::cout << std::setw(4) << this->listMenu.at(i)->getNo();
       std::cout << std::setw(this->listMenu.at(i)->getText().size() + 4)
        << this->listMenu.at(i)->getText();
       std::cout << std::endl;
    }
}

/**
* textOf
* Return the text form the numero
*
* @param USINT no : the numero of the option
* @return string : the text of the option
* @author	Valentin Delaye
* @version	1.0
*/
std::string Menu::textOf (const USINT no) const throw (ErrorPersonVector *)
{
    // Iterate the vector
    for (register USINT i = 0 ; i < this->listMenu.size() ; i++)
    {
        // If they find the number
        if(this->listMenu.at(i)->getNo() == no)
            return this->listMenu.at(i)->getText();
    }
    throw new ErrorPersonVector("Erreur ! Option non trouvee");
}

/**
* textOf
* Return the texte from and id
*
* @param string : the id
* @return string : the text
* @author	Valentin Delaye
* @version	1.0
*/
std::string Menu::textOf (std::string id) const throw (ErrorPersonVector *)
{
    //Go through options
    for (register USINT i = 0 ; i < this->listMenu.size() ; i++)
    {
        // If we fin the id, return the text
        if(this->listMenu.at(i)->getId() == id)
            return this->listMenu.at(i)->getText();
    }
    throw new ErrorPersonVector("Erreur ! Option non trouvee");
}

/**
* positionOf
* Return the position from the numero
*
* @param USINT no : the numero of the option
* @return USINT : the position of the option
* @author	Valentin Delaye
* @version	1.0
*/
USINT Menu::positionOf(const USINT no) const throw (ErrorPersonVector *)

{
    // Iterate the vector
    for (register USINT i = 0 ; i < this->listMenu.size() ; i++)
    {
        // One they find the no, return position
        if (this->listMenu.at(i)->getNo() == no)
            return i;
    }
    throw new ErrorPersonVector("Erreur ! Option non trouvee");
}

/**
* listEmpty
* Return if the menu is empty
*
* @author	Valentin Delaye
* @return bool : True the list is empty, false else
* @version	1.0
*/
bool Menu::listEmpty() const
{
    return this->listMenu.empty();
}

/**
* size
* Return the number of the option in the menu
*
* @author Valentin Delaye
* @return USINT : size of the menu
* @version	1.0
*/
USINT Menu::size() const
{
    return this->listMenu.size();
}

/**
* exist
* Return if an option exist
*
* @param USINT : the number of option
* @return bool : true the option exist, false else
* @author Valentin Delaye
* @version	1.0
*/
bool Menu::exist(USINT no) const
{
    // go through all options
    for (register USINT i = 0 ; i < this->listMenu.size() ; i++)
    {
        // If they find that searched
        if (this->listMenu.at(i)->getNo() == no)
            return true;
    }

    return false;
}

/**
* choiceOption
* Ask the user to chose an option and return the number
*
* @param string : message to the user
* @return USINT : the number of the option chosen
* @author Valentin Delaye
* @version	1.0
*/
USINT Menu::choiceOption(std::string invitation) const
{
    // To get information
    USINT info;

    //Seizure
    while(1)
    {
        std::cout << std::endl;
        std::cout << invitation << " : ";        // Show invitation
        std::cin >> info;                        // Seizure

        // Empty the buffer
        while (getchar() != '\n');

        // If option exists
        if (this->exist(info))
            break;

        // Otherwise error of seizure
        else
        {
            std::cout << std::endl << "Erreur de saisie ! " << std::endl;
            std::cin.clear();
        }
    }

    // Return
    return info;
}

/*=====================================================================*
 | Declaration file ParserPerson.h
 |    declares : 	ParserPerson class
 |
 | For more informations (creation date, creator, etc.), please see the
 | corresponding .cpp file
 |
 *=====================================================================*/

#ifndef PARSERPERSON_H_INCLUDED
#define PARSERPERSON_H_INCLUDED

#include <iostream>
#include "I_Parser.h"
#include "Typedef.h"

/**
* Implements methods to parse file
*
* @author	Valentin Delaye
* @version	1.0
*/
class ParserPerson : public I_Parser
{

    public :

    /**
    * parse
    * Parse people infos from an SGBD's line
    *
    * @param std::string _line
    * @return std::vector<std::string> : return people informations list
    */
    std::vector<std::string> parse(std::string _line);

    private :

    /**
    * removeChar
    * Remove each chars like "_search" in the string specified
    *
    * @param const char _search
    * @param const std::string _text
    * @return std::string : string modified
    */
    std::string removeChar(const char _search, const std::string _text);

    /**
    * split
    * Split the string specified on each appear of "_separator"
    *
    * @param std::vector<std::string> &_result : the string splitted vector
    * @param const std::vector<std::string> _text : string to split
    * @param const char _separator
    * @return USINT : number of elements after split()
    */
    USINT split(std::vector<std::string> &_result, const std::string _text, const char _separator);

};


#endif // PARSERPERSONPROFESSORSTUDENT_H_INCLUDED

/*=====================================================================*
 | Interface file I_Parser.h
 *=====================================================================*/

#ifndef I_PARSER_H_INCLUDED
#define I_PARSER_H_INCLUDED

#include <vector>
#include <string>

/**
* Interface to have a method for parsing a file and return informations
*
* @author	Valentin Delaye
* @version	1.0
*/
class I_Parser
{

    public :

    /**
    * parse
    * Parse people infos from an SGBD's line
    *
    * @param std::string _line
    * @return std::vector<std::string> : return people informations list
    */
    virtual std::vector<std::string> parse(std::string _line) = 0;

};

#endif // I_PARSER_H_INCLUDED

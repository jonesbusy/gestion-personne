/*==============================================================*
 | Implementation file ParserPerson.cpp
 |    implements : ParserPerson class
 |
 | Creator : Sebastien Wermeille and Valentin Delaye
 | Creation date : 24 aout 2009
 | Copyright: EIAJ, all rights reserved
 |
 | Modification tag : //MODIF1
 |
 | Version of the file : 1.0
 |
 *==============================================================*/

#include "ParserPerson.h"

/**
* parse
* Parse people infos from an SGBD's line
*
* @param std::string _line
* @return std::vector<std::string> : return people informations list
*/
std::vector<std::string> ParserPerson::parse(std::string _line)
{
    std::vector<std::string> l_sResult;
    //_line = removeChar(' ', _line);   // Delete space
    split(l_sResult, _line, ';');
    return l_sResult;
}

/**
* split
* Split the string specified on each appear of "_separator"
*
* @param std::vector<std::string> &_result : the string splitted vector
* @param const std::vector<std::string> _text : string to split
* @param const char _separator
* @return USINT : number of elements after split
*/
USINT ParserPerson::split(std::vector<std::string> &_result, std::string _text, const char _separator)
{
    _result.clear(); // Clear to be sure to have empty string

    int l_separatorPos;

    register USINT i=0;

    // Cut always when separator finded
    while((l_separatorPos = _text.find_first_of(_separator))>=0 && i < _text.length())
    {
        _result.push_back(_text.substr(0, l_separatorPos));
        _text = _text.erase(0, l_separatorPos+1);
        i++;
    }

    // If more information
    if(_text.length()>0)
    {
        _result.push_back(_text);
        i++;
    }

    return i;
}

/**
* removeChar
* Remove each chars like "_search" in the string specified
*
* @param const char _search
* @param const std::string _text
* @return std::string : string modified
*/
std::string ParserPerson::removeChar(const char _search, const std::string _text)
{
    std::string l_sResult="";
    for(register USINT i=0; i<_text.length(); i++)
    {
        if(_text.at(i) != _search)
            l_sResult += _text[i];
    }
    return l_sResult;
}

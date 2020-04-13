/*=====================================================================*
 | Declaration file Tools.h
 *=====================================================================*/

#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

/**
* MyIsSpace
* Verifies that the character in parameter is in a space
*
* @param char _car : The character that needs to be verified
* @return bool - true : correct / false : wrong
*/
bool isSpace(char _car)
{
	return _car == ' ';
}
/**
* MyIsBackSlash
* Verifies that the character in parameter is a Backslash
*
* @param char _car : The character that needs to be verified
* @return bool - true : correct / false : wrong
*/
bool isBackSlash(char _car)
{
    return _car == '\\';
}

/**
* IsUnionBar
* Verifies that the character in parameter is in a union bar
*
* @param char _car : The character that needs to be verified
* @return bool - true : correct / false : wrong
*/
bool isUnionBar(char _car)
{
   return _car == '-';
}

#endif // TOOLS_H_INCLUDED

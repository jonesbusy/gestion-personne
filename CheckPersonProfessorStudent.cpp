/*==============================================================*
 | Implementation file CheckPersonProfessorStudent.cpp
 |    implements : CheckPersonProfessorStudent class
 |
 | Creator : Valentin Delaye
 | Creation date : 18 aout 2009
 | Copyright: EIAJ, all rights reserved
 |
 | Modification tag : //MODIF1
 |
 | Version of the file : 1.0
 |
 *==============================================================*/

#include "CheckPersonProfessorStudent.h"
#include "Tools.h"

/**
* checkInfos
* Check all information contained in the vector of string
*
* @param vector<string> & : informations to be verified
* @return bool - true : correct / false : wrong
*/
bool CheckPersonProfessorStudent::checkInfos(std::vector<std::string> & _infoVector)
{

    bool l_result = this->checkLastName(_infoVector.at(0)) &&
                    this->checkFirstName(_infoVector.at(1)) &&
                    this->checkBirthday(_infoVector.at(2)) &&
                    this->checkAdress(_infoVector.at(3)) &&
                    this->checkNumber(_infoVector.at(4)) &&
                    this->checkNpa(_infoVector.at(5));

    // If there's an other information, its a Professor and we need to test the format of salary
    if (_infoVector.size() == 7)
        l_result = l_result && this->checkSalary(_infoVector.at(6));
    else if (_infoVector.size() > 7)
        return false;

    return l_result;
}

/**
* checkLastName
* Verifies that the name in parameter is in a correct format
*
* @param string _lastName : The name that needs to be verified
* @return bool - true : correct / false : wrong
*/
bool CheckPersonProfessorStudent::checkLastName(std::string & _lastName)
{

   USINT l_state;
   char l_currentChar;

   l_state = 0;				    // Initial state

   if(_lastName.length() > 0)
   {
      for(register USINT i = 0 ; i<_lastName.length() ; i++) // Check char by char
      {

         l_currentChar=_lastName.at(i);

         // State machine
         switch(l_state)
         {
            // State 0
            case 0:

               if(isupper(l_currentChar))
                  l_state=1;

               else if (islower(l_currentChar))
               {
                   _lastName.at(i) = toupper(l_currentChar);
                   l_state=1;
               }
               else
                  l_state=4;	// Error
               break;

            // State 1
            case 1:
               if(islower(l_currentChar))
                  l_state=1;
               else if (isupper(l_currentChar))
               {
                   _lastName.at(i) = tolower(l_currentChar);
                   l_state=1;
               }
               else if(isUnionBar(l_currentChar))
                  l_state=2;
               else
                  l_state=4;	// Error
               break;

            // State 2
            case 2:
               if(isupper(l_currentChar))
                  l_state=3;
               else if (islower(l_currentChar))
               {
                   _lastName.at(i) = toupper(l_currentChar);
                   l_state=3;
               }
               else
                  l_state=4;	// Error
               break;

            // State 3
            case 3:
               if(islower(l_currentChar))
                  l_state=3;
               else if (isupper(l_currentChar))
               {
                   _lastName.at(i) = tolower(l_currentChar);
                   l_state=3;
               }
               else
                  l_state=4;	// End
               break;

            // State 4
            case 4:
               // No transition
               // Invalide state
               return false;
         }
      }
   }

   return l_state == 1 || l_state == 3;

}

/**
* checkFirstName
* Verifies that the name in parameter is in a correct format
*
* @param string _firstName : The name that needs to be verified
* @return bool - true : correct / false : wrong
*/
bool CheckPersonProfessorStudent::checkFirstName(std::string & _firstName)
{
    // Use the same checker for the last name
    return checkLastName(_firstName);
}

/**
* checkBirthday
* Verifies that the birthday in parameter is in a correct format
*
* @param string _birthday : The birthday that needs to be verified
* @return bool - true : correct / false : wrong
*/
bool CheckPersonProfessorStudent::checkBirthday(std::string & _birthday)
{
   USINT l_state;
   char l_currentChar;

   l_state=0;				// Initial state

   if(_birthday.length() > 0)				                // The string is not empty
   {
      for(register USINT i=0 ; i<_birthday.length() ; i++)  // Check char by char
      {
         l_currentChar=_birthday.at(i);

         // State machine
         switch(l_state)
         {
            // State 0
            case 0:
               if(isdigit(l_currentChar))
                  l_state=1;
               else
                  l_state=11;	// Error

               break;

            // State 1
            case 1:
               if(isdigit(l_currentChar))
                  l_state=2;
               else if(isBackSlash(l_currentChar))
                  l_state=3;
               else
                  l_state=11;	// Error
               break;

            // State 2
            case 2:
               if(isBackSlash(l_currentChar))
                  l_state=3;
               else
                  l_state=11;	// Error
               break;

            // State 3
            case 3:
               if(isdigit(l_currentChar))
                  l_state=4;
               else
                  l_state=11;	// Condition non acheve
               break;

            // State 4
            case 4:
               if(isdigit(l_currentChar))
                  l_state=5;
               else
                  l_state=11;	// Error
               break;

            // State 5
            case 5:
               if(isBackSlash(l_currentChar))
                   l_state=6;
               else
                  l_state=11;
               break;

            // State 6
            case 6:
               if(l_currentChar=='1' || l_currentChar=='2')
                   l_state=7;
               else
                   l_state=11;
               break;

            // State 7
            case 7:
               if(isdigit(l_currentChar))
                   l_state=8;
               else
                   l_state=11;
               break;

            // State 8
            case 8:
               if(isdigit(l_currentChar))
                   l_state=9;
               else
                   l_state=11;
               break;

            // State 9
            case 9:
               if(isdigit(l_currentChar))
                   l_state=10;
               else
                   l_state=11;
               break;

            // State 10
            case 10:
               if(isdigit(l_currentChar))
                   l_state=11;
               else
                   l_state=11;
               break;

            // State 11 (Error)
            case 11:
                return false;
         }
      }
   }

   // If the format jj\mm\aaaa (stage 10), check the date
   return l_state == 10 && Date::verify(_birthday);
}

/**
* checkAdress
* Verifies that the road name in parameter is in a correct format
*
* @param string _adress : The road name that needs to be verified
* @return bool - true : correct / false : wrong
*/
bool CheckPersonProfessorStudent::checkAdress(std::string & _adress)
{
   USINT l_state;
   char l_currentChar;

   l_state=0;				// First state

   if(_adress.size() > 0)   // The string is not empty
   {
      for(register USINT i=0 ; i < _adress.length() ; i++) // Check char by char
      {
         l_currentChar=_adress.at(i);

         // State machine
         switch(l_state)
         {
            // State 0
            case 0:
               if(islower(l_currentChar))
                    l_state=1;
               else if (isupper(l_currentChar))
               {
                    _adress.at(i) = tolower(l_currentChar);
                    l_state=1;
               }
               else
                    l_state=6;	// Condition non acheve
               break;

            // State 1
            case 1:
               if(islower(l_currentChar))
                    l_state=1;
               else if (isupper(l_currentChar))
               {
                    _adress.at(i) = l_currentChar+('a'-'A');
                    l_state=1;
               }
               else if(isSpace(l_currentChar))
                    l_state=2;
               else if(isUnionBar(l_currentChar))
                    l_state=3;
               else
                    l_state=6;	// fini
               break;

            // State 2
            case 2:
               if(islower(l_currentChar))
                    l_state=1;
               else if (isupper(l_currentChar))
               {
                    _adress.at(i) = l_currentChar+('a'-'A');
                    l_state=1;
               }
               else if(isSpace(l_currentChar))
                    l_state=2;
               else if(isUnionBar(l_currentChar))
                    l_state=3;
               else
                    l_state=6;	// End

               break;

            // State 3
            case 3:
               if(islower(l_currentChar))
                  l_state=4;
               else if(isupper(l_currentChar))
               {
                   _adress.at(i) = tolower(l_currentChar);
                   l_state=4;
               }
               else if (isSpace(l_currentChar))
               {
                   l_state=5;
               }
               else
                  l_state=6;	// Condition non acheve
               break;

            // State 4
            case 4:
               if(islower(l_currentChar))
                  l_state=4;
               else if(isupper(l_currentChar))
               {
                   _adress.at(i) = tolower(l_currentChar);
                   l_state=4;
               }
               else if (isSpace(l_currentChar))
               {
                   l_state=5;
               }
               else
                  l_state=6;	// fini
               break;

            // State 5
            case 5:
               if(islower(l_currentChar))
                   l_state=4;
               else if(isupper(l_currentChar))
               {
                   _adress.at(i) = tolower(l_currentChar);
                   l_state=4;
               }
               else if (isSpace(l_currentChar))
               {
                   l_state=5;
               }
               else
                  l_state=6;
               break;

            // State 6 (error)
            case 6:
                return false;
         }
      }
   }
   return l_state==1 || l_state==4;   // Return final state
}

/**
* checkNumber
* Verifies that the number of the house in parameter is in a correct format
*
* @param string _number : The number of the house that needs to be verified
* @return bool - true : correct / false : wrong
*/
bool CheckPersonProfessorStudent::checkNumber(std::string & _number)
{
    // Canno't begin with 0 or be negatif
    if (_number.at(0) == '0' || _number.at(0) == '-')
        return false;

    // Try to convert the string to integer
    USINT l_value = atoi(_number.c_str());

    // Can't convert
    if (l_value == 0)
        return false;

    // Return if valid
    else
        return l_value >= 1 && l_value <= 999;
}

/**
* checkNpa
* Verifies that the NPA in parameter is in a correct format
*
* @param string _npa : The NPA that needs to be verified
* @return bool - true : correct / false : wrong
*/
bool CheckPersonProfessorStudent::checkNpa(std::string & _npa)
{
    // Canno't begin with 0 or be negatif
    if (_npa.at(0) == '0' || _npa.at(0) == '-')
        return false;

    // Try to convert the string to integer
    USINT l_value = atoi(_npa.c_str());

    // Can't convert :(
    if (l_value == 0)
        return false;

    // Return if valid
    else
        return l_value >= 1000 && l_value <= 9999;
}

/**
* checkSalary
* Verifies that the string in parameter is in the correct salary format
*
* @param string _salary : The string that needs to be verified
* @return bool - true : correct / false : wrong
*/
bool CheckPersonProfessorStudent::checkSalary(std::string & _salary)
{
    // Canno't begin with 0 or be negatif
    if (_salary.at(0) == '0' || _salary.at(0) == '-')
        return false;

    // Try to convert the string to integer
    int l_value = atoi(_salary.c_str());

    // Can't convert (or returning INT_MAX, because to big)
    if (l_value == 0 || l_value == INT_MAX)
        return false;

    // Return if valid (max size of unsigned int)
    else
        return l_value >= 1 && l_value <= INT_MAX - 1;
}

/*==============================================================*
 | Implementation file PersonVector.cpp
 |    implements : PersonVector class
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

#include "PersonVector.h"

/**
* Constructor
* Construct new vector with filename and comportement
*
* @param std::string fileName : the name or path of the file
* @param I_CompareComportement * : the comportement of sorting
* @param I_AskComportement *  : the comportement for ask person
* @param I_CheckPerson     *  : the comportement of checking parameters
* @param I_Parser          *  : parser for the file
*/
PersonVector::PersonVector(std::string _fileName, I_CompareComportement * _compareComportement, I_FactoryPerson * _factory,
                          I_AskPerson * _askComportement, I_CheckPerson * _checkComportement,
                          I_Parser * _parser)
{
    if(!this->checkExtension(_fileName, ".bdd"))
        throw new ErrorPersonVector("Nom de fichier incorrect");

    else
    {
        // Set file name and comportement for sorting and factory
        this->lastId = 0;
        this->sName = _fileName;
        this->factory = _factory;
        this->compareComportement = _compareComportement;
        this->checkFile = _checkComportement;
        this->askPerson = _askComportement;
        this->parser    = _parser;
    }

}

/**
* Constructor
* Construct new vector with no param
*
*/
PersonVector::PersonVector() {}

/**
* add
* This function add a person to the vector
*
* @param Person* thePerson : The person to add
* @return void
*/
void PersonVector::add(Person * _thePerson)
{
    // Get the last id if the list not empty and add the person
    if (!this->list.empty())
    {
        this->list.push_back(_thePerson);

        // Change and set the id
        this->list.back()->setId(++this->lastId);
    }

    // Else before add at begin and set the id to one
    else
    {
        this->list.push_back(_thePerson);
        this->list.back()->setId(FIRST_ID);
        this->lastId = FIRST_ID;
    }
}

/**
* del
* This function delete a person to the vector
*
* @param Person * person : the person to delete
* @return void
*/
void PersonVector::del(Person * _person)
{
    // Delete the person
    this->list.erase(this->list.begin() + this->getPosition(_person));

}

/**
* showList
* This show the list of the person
*
* @return void
*/
void PersonVector::showList()
{
    for (register USINT i = 0 ; i < this->getSize() ; i++)
    {
        this->at(i)->display(); // Use polymorphism
        std::cout << "------------------------------------------" << std::endl;
    }
}

/**
* getSize
* Get the number of person in the vector
*
* @param
* @return unsigned int : number of person
*/
UINT PersonVector::getSize()
{
    return this->list.size();
}

/**
* getFileName
* Return the name of file
*
* @return std::string : name of the file
*/
std::string PersonVector::getFileName()
{
    return this->sName;
}

/**
* getPersonFromPosition
* Get a person from a position in the vector
*
* @param
* @return Person* : the person
*/
Person * PersonVector::at(UINT _position) throw(ErrorPersonVector *)
{
    try
    {
        return this->list.at(_position);
    }
    // If try to access out of range the size of the vector, throw our exception
    catch(std::out_of_range)
    {
        throw new ErrorPersonVector("La personne n'existe pas.");
    }
}

/**
* getPersonFromId
* Get a person from the id of the person in the vector
*
* @param
* @return Person* : the person, return NULL if doesn't match
*/
Person * PersonVector::getPersonFromId(UINT _id)
{
    // Iterate the vector
    for (register USINT i = 0 ; i < this->getSize() ; i++)
    {
        // If found return it
        if(this->at(i)->getId() == _id)
        {
            return this->at(i);
        }
    }
    throw new ErrorPersonVector("La personne n'existe pas.");
}

/**
* getLastId
* Get the higher id in the list
*
* @return USINT : last id of the list
*/
USINT PersonVector::getLastId()
{
    return this->lastId;
}


/**
* getPosition
* Get the position in the vector for a person
*
* @param
* @return Person* : the person, throw exception if doesn't match
*/
USINT PersonVector::getPosition(Person * _person) throw(ErrorPersonVector *)
{
    for (register USINT i = 0 ; i < this->getSize() ; i++)
    {
        if (this->at(i) == _person)
            return i;
    }
    throw new ErrorPersonVector("La personne n'existe pas.");
}

/**
* setCompareComportement
* Get the comportement of sorting
*
* @param I_CompareComportement * : the comportement to set
* @return void
*/
void PersonVector::setCompareComportement(I_CompareComportement * _comportement)
{
    this->compareComportement = _comportement;
}

/**
* setAskComportement
* Set comportement of asking
*
* @param I_AskPerson * : the comportement to set
* @return void
*/
void PersonVector::setAskComportement(I_AskPerson * _askComportement)
{
    this->askPerson = _askComportement;
}

/**
* setCheckComportement
* Set comportement of checking for parsing file
*
* @param I_CheckPerson * : the comportement to set
* @return void
*/
void PersonVector::setCheckComportement(I_CheckPerson * _checkComportement)
{
    this->checkFile = _checkComportement;
}

/**
* getCompareComportement
* Get the comportement of sorting
*
* @return I_CompareComportement * : the comportement curent used
*/
I_CompareComportement * PersonVector::getCompareComportement() const
{
    return this->compareComportement;
}

/**
* sort
* Sort the vector with associated comportement. Use simple bubble sort
*
* @return void
*/
void PersonVector::sort()
{

    // Can only sort if 2 element
    if (this->getSize() >= 2)
    {
        // Bubble sort
        for (register UINT i = 0 ; i<this->getSize() - 1 ; i++)
        {
            for (register UINT j = 0 ; j<this->getSize() - 1 ; j++)
            {
                // Swap if necessary (the comportement return true)
                if (this->getCompareComportement()->compare(this->at(j), this->at(j+1)))
                {
                    Person * tmp = this->list.at(j);
                    this->list.at(j) = this->list.at(j + 1);
                    this->list.at(j + 1) = tmp;
                }
            }

        }
    }
}

/**
* load
* Read a file and add the informations in the vector
*
* @return bool : return false and generate an error message if the file can't be opened (cf : getError() to get error message)
*/
void PersonVector::load() throw(ErrorPersonVector *)
{

    // Extension correcte ?
    if(!this->checkExtension(this->sName, ".bdd"))
    {
        throw new ErrorPersonVector("Extension invalide. Veuillez choisir un fichier  se terminant par .bdd");
    }
    else
    {
        // Tentative de lecture du fichier
        std::ifstream handle(this->sName.c_str(), std::ios::in);

        if(!handle) // Impossible d'ouvrir le fichier
        {
            throw new ErrorPersonVector("Impossible d'ouvrir le fichier.");
        }
        else // Ouverture ok
        {
            std::string l_sLine; // Contain each row

            // Purge the vector
            this->list.clear();

            // To count row
            register USINT nbLines = 0;

            // Get the line line
            while (getline(handle, l_sLine))
            {

                // Parse information from the line and create vector of string
                std::vector<std::string> listInfo = this->parser->parse(l_sLine);
                // Check informations (use the checker)
                if (!this->checkFile->checkInfos(listInfo))
                {
                    std::ostringstream exception;
                    exception << "Probleme de lecture a la ligne " << nbLines + 1;
                    throw new ErrorPersonVector(exception.str().c_str());
                }
                // If correct create person (concrete object) and add it (use the factory)
                else
                {
                    this->add(this->factory->create(listInfo));
                }
                nbLines++;
            }
            // If the file is empty
            if(nbLines<1)
            {
               throw new ErrorPersonVector("Le fichier est vide");
            }
            else
            {
                handle.close();
            }
        }
    }
}

/**
* save
* Save a file with the informations contained in the vector
*
* @return bool : return false and generate an error message if the file can't be saved (cf : getError() to get error message)
*/
void PersonVector::save() throw(ErrorPersonVector *)
{
    // Is the the extension correct
    if(!this->checkExtension(this->sName, ".bdd"))
    {
        throw new ErrorPersonVector("Extension invalide. Veuillez choisir un fichier se terminant par .bdd");
    }

    // Save the file
    else
    {
        // Open
        std::ofstream handle(this->sName.c_str(), std::ios::out | std::ios::trunc);
        if(handle)
        {
            // For each person, get informations
            for(register USINT i = 0 ; i<this->getSize() ; i++)
            {
                std::vector<std::string> l_sInfos = this->at(i)->getInfos();
                std::string l_sLine;

                for(register USINT y = 0; y < l_sInfos.size(); y++)
                {
                    l_sLine += l_sInfos.at(y);
                    if(y < l_sInfos.size() + 1)
                        l_sLine+=";";
                }
                handle << l_sLine << std::endl;
            }
            handle.close();
        }
        else
        {
            throw new ErrorPersonVector("Impossible d'enregistrer le fichier");
        }
    }
}

/**
* ask
* Ask from user different kind of informations about the person, finally add it
*
* @return void
*/
void PersonVector::ask()
{
    // Ask info, create the person with factory and finally add it
    this->add(this->factory->create(*this->askPerson->askInfo()));
}

/**
* modify
* This function modify the informations of a person in the vector
*
* @param Person * : the person to modify
* @return void
*/
void PersonVector::modify(Person * _person)
{
    // Recup the id of the person
    USINT id = _person->getId();

    // Delete
    this->del(_person);

    // Add new
    this->add(this->factory->create(*this->askPerson->askInfo()));

    // Modifiy last id
    this->lastId = id;
    this->list.back()->setId(id);
}

/**
* search
* This function search a information contain in a person
*
* @param string : information to search
* @return vector<Person *> * : a vector of person
*/
std::vector<Person *> * PersonVector::search(std::string value)
{

    std::vector<Person *> * searchResult = new std::vector<Person *>;

    for (register USINT i=0 ; i<this->getSize() ; i++)
    {
        // If match add person to search result
        if(this->compareComportement->egality(this->at(i), value))
            searchResult->push_back(this->at(i));
    }

    // At end return the vector of result
    return searchResult;
}



/**
* checkExtension
* Check if extension file is correct
*
* @param std::string extension : extension to check
* @return bool : True file extension correct, false else
*/
bool PersonVector::checkExtension(std::string fileName, std::string extension)
{
    return fileName.length() > 4 && fileName.substr(fileName.length()-4,4) == extension;
}

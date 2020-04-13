/*==============================================================*
 | Implementation file main.cpp
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

// Std library
#include <iostream>
#include <cstdlib>
#include <vector>

// Used to configure menu and structure of person
#include "Student.h"
#include "Professor.h"
#include "PersonVector.h"
#include "Typedef.h"
#include "CompareComportement/CompareComportementLastNameAsc.h"
#include "CompareComportement/CompareComportementLastNameDesc.h"
#include "CompareComportement/CompareComportementFirstNameAsc.h"
#include "CompareComportement/CompareComportementFirstNameDesc.h"
#include "CompareComportement/CompareComportementSalaryAsc.h"
#include "CompareComportement/CompareComportementSalaryDesc.h"
#include "CompareComportement/CompareComportementDateAsc.h"
#include "CompareComportement/CompareComportementDateDesc.h"
#include "CompareComportement/CompareComportementNpaAsc.h"
#include "CompareComportement/CompareComportementNpaDesc.h"
#include "AskComportement/AskProfessor.h"
#include "AskComportement/AskStudent.h"
#include "CheckPersonProfessorStudent.h"
#include "FactoryPersonProfessorStudent.h"
#include "ParserPerson.h"
#include "ErrorPersonVector.h"
#include "Menu/Menu.h"
#include "Menu/Option.h"

using namespace std;

void onUnexpected();         // Function called when unexpected error
void onTerminate();          // Function called when subit end of program
void onExit();               // Function called when end of program
void toContinue();           // Function called when small pause on program needed
USINT getUInt();             // To get valid id from user
string getString(string);    // Get a string and return it

int main()
{

    // Set handlers
    set_unexpected(onUnexpected);
    set_terminate(onTerminate);
    atexit(onExit);


    // Standard configuration
    CompareComportementLastNameAsc * sorter  = new CompareComportementLastNameAsc();
    AskProfessor                   * asker   = new AskProfessor();
    FactoryPersonProfessorStudent  * factory = new FactoryPersonProfessorStudent();
    CheckPersonProfessorStudent    * checker = new CheckPersonProfessorStudent();
    ParserPerson                   * parser  = new ParserPerson();

    // Default file name
    const string defaultFileName = "Personnes.bdd";

    // Global object
    PersonVector * myvector = NULL;

    // Create the menu interface of the beginning
    Menu * loadingMenu = new Menu();
    Menu * mainMenu    = new Menu();
    Menu * addMenu     = new Menu();
    Menu * modifyMenu  = new Menu();
    Menu * sortMenu    = new Menu();
    Menu * searchMenu  = new Menu();

    char choice = 'n';  // To recup the char to exit
    string nameFile;    // Name of the file

    // Create the loading menu
    loadingMenu->add(new Option(1, "createFile",   "Pour creer une nouvelle liste de personne."));
    loadingMenu->add(new Option(2, "loadFile",     "Pour charger un fichier."));

    enum {eNewFIle = 1, eLoadFile = 2};

    // Create the main menu
    mainMenu->add(new Option(1, "addList",      "Pour ajouter une personnne."));
    mainMenu->add(new Option(2, "showList",     "Pour afficher une liste."));
    mainMenu->add(new Option(3, "modifyList",   "Pour modifier une personne."));
    mainMenu->add(new Option(4, "sortList",     "Pour trier une liste."));
    mainMenu->add(new Option(5, "remList",      "Pour supprimer une personne."));
    mainMenu->add(new Option(6, "searchList",   "Pour rechercher une personne."));
    mainMenu->add(new Option(7, "saveList",     "Pour sauvegarder une liste."));
    mainMenu->add(new Option(8, "gotoLoad",     "Pour revenir au menu de chargement."));
    mainMenu->add(new Option(9, "quit",         "Pour quitter le programme."));

    // Create the add person menu
    addMenu->add(new Option(1, "student", "Pour ajouter un etudiant."));
    addMenu->add(new Option(2, "professor", "Pour ajouter un professeur."));
    addMenu->add(new Option(3, "gotoMain", "Pour revenir au menu principal."));

    // Create the modify person menu
    modifyMenu->add(new Option(1, "student", "Pour modifier en tant qu'etudiant."));
    modifyMenu->add(new Option(2, "professor", "Pour modifier en tant que professeur."));
    modifyMenu->add(new Option(3, "gotoMain", "Pour revenir au menu principal."));

    // Create the sorting menu
    sortMenu->add(new Option(1, "lastNameAsc", "Pour trier par odre croissant le nom de famille"));
    sortMenu->add(new Option(2, "lastNameDesc", "Pour trier par odre decroissant le nom de famille"));
    sortMenu->add(new Option(3, "firstNameAsc", "Pour trier par odre croissant le prenom"));
    sortMenu->add(new Option(4, "firstNameDesc", "Pour trier par odre decroissant le prenom"));
    sortMenu->add(new Option(5, "dateAsc", "Pour trier par odre croissant la date de naissance"));
    sortMenu->add(new Option(6, "dateDesc", "Pour trier par odre decroissant la date de naissance"));
    sortMenu->add(new Option(7, "npaAsc", "Pour trier par odre croissant le NPA"));
    sortMenu->add(new Option(8, "npaDesc", "Pour trier par odre decroissant le NPA"));
    sortMenu->add(new Option(9, "salaryAsc", "Pour trier par odre croissant le salaire"));
    sortMenu->add(new Option(10, "salaryDesc", "Pour trier par odre decroissant le salaire"));
    sortMenu->add(new Option(11, "gotoMain", "Pour revenir au menu principal."));

    // Create the search menu
    searchMenu->add(new Option(1, "searchLastName", "Pour rechercher par nom de famille"));
    searchMenu->add(new Option(2, "searchFirstName", "Pour rechercher par prenom"));
    searchMenu->add(new Option(3, "searchBirthday", "Pour chercher par annee de naissance"));
    searchMenu->add(new Option(4, "searchNpa", "Pour rechercher par npa"));
    searchMenu->add(new Option(5, "searchSalary", "Pour rechercher par salaire"));
    searchMenu->add(new Option(6, "gotoMain", "Pour revenir au menu principal."));

    cout << endl << endl;
    cout << "************************GESTION PERSONNES************************" << endl;
    cout << "**                                                             **" << endl;
    cout << "**    ce programme vous permet de gerer une liste contacts,    **" << endl;
    cout << "**    puis de la sauver dans un fichier pour la completer      **" << endl;
    cout << "**                         plus tard                           **" << endl;
    cout << "**                                                             **" << endl;
    cout << "*****************************************************************" << endl;
    cout << endl << endl;

    // Always do some actions
    do
    {
        // Label if return to load menu
        LOADMENU :

        loadingMenu->showMenu("Ouverture/Creation fichier");  // Show the start menu

        // If return to load menu and vector already exists, delete it
        if (myvector != NULL)
        {
            delete myvector;
            myvector = NULL;
        }

        // Get the choice of the user and do action
        switch (loadingMenu->choiceOption("Choisissez votre option svp"))
        {

            // Load file
            case eLoadFile :
            {
                // To have a correct file name
                do
                {
                    try
                    {
                        cout << "Entrez le nom du fichier avec l'extension \".bdd\" [0 : pour stopper] : " << endl;
                        getline(cin, nameFile);

                        // Try to instanciate new PersonVector
                        myvector = new PersonVector(nameFile, sorter, factory, asker, checker, parser);
                        myvector->load(); // Load file if correct
                        break;            // Go to next branch of case
                    }

                    // If extension no .bdd, show error message and re-ask the question
                    catch (ErrorPersonVector * e)
                    {
                        cout << e->what() << endl;

                        // Goto load menu if 0
                        if (nameFile == "0")
                            goto LOADMENU;
                    }
                }
                while(1);
            }

            // New file
            case eNewFIle :
            {

                // Create new file if no load done
                if (myvector == NULL)
                {
                    myvector = new PersonVector(defaultFileName, sorter, factory, asker, checker, parser);
                    cout << endl <<"La liste utilise sera : " << myvector->getFileName() << endl;
                    toContinue();
                }

                // Show main menu
                do
                {

                    mainMenu->showMenu("Menu principal");

                    // Get the choice of the user

                    // Do some action
                    switch(mainMenu->choiceOption("Choisissez votre option svp"))
                    {
                        // Add person
                        case 1:
                        {
                            addMenu->showMenu("Ajout de personnes");

                            // Add student or Professor
                            USINT choice = addMenu->choiceOption("Choisissez votre option svp");

                            // Change ask comportement
                            switch(choice)
                            {
                                case 1 : myvector->setAskComportement(new AskStudent());
                                         break;
                                case 2 : myvector->setAskComportement(new AskProfessor());
                                         break;

                                // Return to main menu
                                case 3 : break;

                            }

                            // Ask informations only if necessary
                            if (choice != 3)
                            {
                                myvector->ask();
                                cout << endl << "Personne ajoutee avec succes." << endl;
                            }
                            // Return to main menu
                            break;
                        }
                        // Show list
                        case 2 :
                        {
                            myvector->showList();
                            cout << endl << "Liste affichee." << endl;

                            // Return to main menu
                            break;
                        }

                        // Modify person
                        case 3:
                        {
                            // Person to modify
                            Person * modifyPerson = NULL;

                            do
                            {
                                // Break if 0
                                try
                                {
                                    USINT idValue = getUInt();
                                    if(idValue == 0)
                                        // Return to main menu
                                        break;
                                    else
                                        // Get the person
                                        modifyPerson = myvector->getPersonFromId(idValue);

                                    // Goto to modif menu
                                    break;
                                }
                                // Id id doesn't exist, print message et re-ask id
                                catch(ErrorPersonVector * e)
                                {
                                    cout << e->what() << endl;
                                }
                            }
                            while(1);

                            // Show menu and chose if modify as student or professor
                            modifyMenu->showMenu("Modification");

                            // Instanciate good class

                            USINT choice = modifyMenu->choiceOption("Veuillez faire votre choix");
                            switch(choice)
                            {
                                case 1 : myvector->setAskComportement(new AskStudent());
                                         break;
                                case 2 : myvector->setAskComportement(new AskProfessor());
                                         break;

                                // Return to main menu
                                case 3 : break;
                            }

                            if (choice != 3)
                            {
                                // Modify the person
                                myvector->modify(modifyPerson);
                                cout << endl <<"Personne modifiee avec succes." << endl;
                            }

                            // Return to main menu
                            break;

                        }
                        // Sort list
                        case 4:
                        {
                            sortMenu->showMenu("Trier");

                            // Different kind of sort (chosen by user)
                            USINT choice = sortMenu->choiceOption("Veuillez choisir l'ordre de tri.");
                            switch(choice)
                            {
                                case 1 :
                                    myvector->setCompareComportement(new CompareComportementLastNameAsc());
                                    break;
                                case 2 :
                                    myvector->setCompareComportement(new CompareComportementLastNameDesc());
                                    break;
                                case 3 :
                                    myvector->setCompareComportement(new CompareComportementFirstNameAsc());
                                    break;
                                case 4 :
                                    myvector->setCompareComportement(new CompareComportementFirstNameDesc());
                                    break;
                                case 5 :
                                    myvector->setCompareComportement(new CompareComportementDateAsc());
                                    break;
                                case 6 :
                                    myvector->setCompareComportement(new CompareComportementDateDesc());
                                    break;
                                case 7 :
                                    myvector->setCompareComportement(new CompareComportementNpaAsc());
                                    break;
                                case 8 :
                                    myvector->setCompareComportement(new CompareComportementNpaDesc());
                                    break;
                                case 9 :
                                    myvector->setCompareComportement(new CompareComportementSalaryAsc);
                                    break;
                                case 10 :
                                    myvector->setCompareComportement(new CompareComportementSalaryDesc());
                                    break;
                                case 11 :
                                    break;
                            }

                            // Sort only if necessary
                            if (choice != 11)
                            {
                                myvector->sort();
                                cout << endl << "Tri effectue avec succes." << endl;
                            }
                            break;
                        }
                        // Delete person from list
                        case 5:
                        {
                            // Break if 0
                            USINT idValue = getUInt();
                            if(idValue == 0)
                                break;

                            // If valid, delete the person
                            else
                            {
                                // Redo if exception
                                do
                                {
                                    try
                                    {
                                        myvector->del(myvector->getPersonFromId(idValue));
                                        cout << endl <<"Personne supprimee avec succes." << endl;
                                        break;
                                    }
                                    // Id id doesn't exist, print message et re-ask id
                                    catch(ErrorPersonVector * e)
                                    {
                                        cout << e->what() << endl;

                                        // Get the id
                                        idValue = getUInt();

                                        // If want quit
                                        if(idValue == 0)
                                            break;
                                    }
                                }
                                while(1);

                            }
                            break;
                        }

                        // Search
                        case 6 :
                        {
                            string value; // To get information of the user

                            searchMenu->showMenu("Recherche");
                            USINT choice = searchMenu->choiceOption("Veuillez choisir une option");

                            // To have good format of information
                            do
                            {
                                try
                                {

                                    // Different action depend on choice
                                    switch(choice)
                                    {
                                        case 1 : myvector->setCompareComportement(new CompareComportementLastNameAsc());
                                                 value = getString("Veuillez entrez le nom de famille");
                                                 break;

                                        case 2 : myvector->setCompareComportement(new CompareComportementFirstNameAsc());
                                                 value = getString("Veuillez entrez le prenom");
                                                 break;

                                        case 3 : myvector->setCompareComportement(new CompareComportementDateAsc());
                                                 value = getString("Veuillez entrez la date [jj\\mm\\aaaa]");
                                                 break;

                                        case 4 : myvector->setCompareComportement(new CompareComportementNpaAsc());
                                                 value = getString("Veuillez entrez le npa");
                                                 break;

                                        case 5 : myvector->setCompareComportement(new CompareComportementSalaryAsc());
                                                 value = getString("Veuillez entrez le salaire");
                                                 break;

                                        case 6 : break;

                                    }

                                    // Search on only if necessary
                                    if (choice != 6)
                                    {
                                        // Search into the vector and return the search result
                                        vector<Person *> * searchResult = myvector->search(value);

                                        // Show the result
                                        for (register USINT i=0 ; i<searchResult->size() ; i++)
                                        {
                                            cout << endl;
                                            searchResult->at(i)->display();
                                            cout << endl;
                                            cout << "-----------------------------------" << endl;
                                        }
                                        // If no result
                                        if (searchResult->empty())
                                            cout << endl << "Aucun resultat" << endl;
                                    }

                                    // Return to main menu
                                    break;
                                }

                                // Catch if error of format
                                catch (ErrorPersonVector * e)
                                {
                                    cout << endl << e->what() << endl;
                                }
                            }
                            while(1);


                            break;
                        }


                        // Save list
                        case 7 :

                            // Try to save
                            try
                            {
                                myvector->save();
                            }
                            // If error
                            catch(ErrorPersonVector * e)
                            {
                                cout << e->what() << endl;
                                break;
                            }
                            cout << endl << "Liste sauvee sous : " << myvector->getFileName() << endl;
                            break;

                        // Goto load menu
                        case 8:
                            goto LOADMENU;

                        // Quit program
                        case 9 :
                        {
                            do
                            {
                                cout << "Etes vous sur de quitter le programme taper [o/n] ? : ";
                                cin >> choice;
                                while(getchar()!= '\n');
                                // Test choice
                                if(choice == 'o'|| choice == 'O')
                                {
                                    // End of main
                                    exit(EXIT_SUCCESS);
                                }
                                // Go to main menu if won't quit
                                else if (choice == 'n' || choice == 'N')
                                    break;
                                // If other value reset the cin and ask again
                                else
                                {
                                    cout << "Erreur de saisie" << endl;
                                    cin.clear();
                                }
                            }
                            while(1);

                        }

                    }

                // Small pause on program
                toContinue();

                }
                while(choice == 'n' || choice == 'N'); // Test of the second condition

            }

            // End new file
            break;
        }
    }
    while(1);
}

/**
* toContinue
* Call when small pause in needed to read a message
*
* @return void
*/
void toContinue()
{
    cout << endl;
    cout << "Pressez ENTER pour continuer... ";
    while(getchar()!= '\n');
    cout << endl;
}

/**
* getString)
* get a string and return it
*
* @param string : message for user
* @return
*/
string getString(string message)
{
    // To get info
    string info;

    cout << endl << message << " : ";
    cin >> info;

    // clear buffer
    while(getchar() != '\n');

    // and return value
    return info;
}


/**
* getUInt()
* get unsigned integer form user and return it
*
* @return USINT : the choice of user
*/
USINT getUInt()
{
    // For getting info
    USINT info;

    do
    {
        std::cout << "Entrez l'ID de la personne (0 pour retour)" << " : ";

        // Get info and clear buffer
        cin >> info;
        while(getchar()!= '\n');

        if(!cin.good())
            cin.clear();
        else
            break;
    }
    while (cout << "Veuillez saisir un entier non negatif" << endl);

    return info;
}


/**
* onUnexpected
* Function called for unexpected error
*
* @return void
*/
void onUnexpected()
{
    std::cout << "Une erreur inconnue est survenue" << std::endl;
    exit(EXIT_FAILURE);
}

/**
* onTerminate
* Function called when subit end of program
*
* @return void
*/
void onTerminate()
{
    std::cout << "Le programme a cesse de fonctionner." << std::endl;
    abort();
}

/**
* onExit
* Function called when normal end or when exit() is called
*
* @return void
*/
void onExit()
{
    std::cout << std::endl << "Merci d'avoir utilise notre programme." << std::endl;
}

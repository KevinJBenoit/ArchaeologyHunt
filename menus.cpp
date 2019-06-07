/****************************************************************************************
** Program name: menus.cpp
** Author: Kevin Benoit
** Date: 6/02/2019
** Description: Contains the definitions for the menu functions. All menus
    will use integers > 1 to select the desired option if applicable. Inputs will be 
    validated through inputValidate.hpp functions to ensure correct input.
****************************************************************************************/

#include <iostream>
#include "inputValidate.hpp"
#include "menus.hpp"
#include <fstream>


/**************************************
Menu to prompt the user to purchase an
Item from the ShopSpace
Calls:inputValidateIntegerAndRange()
Returns int option
***************************************/
int itemMenu()
{
    std::cout << "1. The Eye of Horace - 300 points - 3 heaviness" << std::endl;
    std::cout << "The Eye will reveal where the Mummy is buried." << std::endl;
    std::cout << "______________________________________________" << std::endl;
    std::cout << "2. A Map of the Area - 200 points - 2 heaviness" << std::endl;
    std::cout << "The Map will remove some of the false digging sites"
        << std::endl;
    std::cout << "______________________________________________" << std::endl;
    std::cout << "3. A Tent with water to rest under some shade - 100 points - 1 heaviness " << std::endl;
    std::cout << "The Tent will add some additional steps to the timer"
        << std::endl;
    std::cout << "______________________________________________" << std::endl;
    std::cout << "4. Nothing" << std::endl;
    std::cout << "Keep your money, it may be the difference in order to achieve "
        << "your true goal!" << std::endl;
    std::cout << "______________________________________________" << std::endl;
    std::cout << std::endl;

    int option = inputValidateIntegerAndRange(1, 4);
    return option;
}


/**************************************
Menu to prompt the user to drop an
Item from the backpack
Calls:inputValidateIntegerAndRange()
Returns int option
***************************************/
int dropMenu()
{
    std::cout << "Would you like to drop some Gems?" << std::endl;
    std::cout << "1. Yes" << std::endl;
    std::cout << "2. No" << std::endl;
    int option = inputValidateIntegerAndRange(1, 2);
    
    return option;
}


/**************************************
Menu for outputing the text for the 
losing scenario from the Mummy
***************************************/
void finalMenu1_1()
{
    std::cout << "You uncovered the Mummy" << std::endl;

    //credit: www.asciiworld.com/-Death-Co-.html
    textMenu("loseMummy.txt");
}

/**************************************
Menu for outputing the text for the
losing scenario from the timer
***************************************/
void finalMenu1_2()
{
    textMenu("loseTime.txt");
}

/**************************************
Menu for outputing the text for the
neutral scenario
***************************************/
void finalMenu2_1()
{
    textMenu("tieNoScore.txt");
}

/**************************************
Menu for outputing the text for the
neutral scenario with some positive score
***************************************/
void finalMenu2_2()
{
    textMenu("tieScore.txt");
}

/***************************************
Menu for outputing the text for the
win scenario
****************************************/
void finalMenu3()
{
    textMenu("winStandard.txt");
}


/********************************************
Menu for outputing the text for the
 true win scenario
********************************************/
void finalMenu4()
{
    textMenu("winTrue.txt");
}



/******************************************
Menu function that reads in text from a
.txt file. 
Takes filename and outputs
to console
******************************************/
void textMenu(std::string fileName)
{
    std::ifstream ifs;
    ifs.open(fileName);

    if (ifs.fail())
    {
        std::cout << "Failed to open " << fileName << std::endl;
        return;
    }

    std::string line;
    while (getline(ifs, line))
    {
        std::cout << line << std::endl;
    }

    ifs.close();
}
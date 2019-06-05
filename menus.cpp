/****************************************************************************************
** Program name: menus.cpp
** Author: Kevin Benoit
** Date: 6/02/2019
** Description: Contains the definitions for the menu functions. All menus
    will use integers > 1 to select the desired option. Inputs will be validated through
    inputValidate.hpp functions to ensure correct input.
****************************************************************************************/

#include <iostream>
#include "inputValidate.hpp"
#include "menus.hpp"


/**************************************
Menu for outputing the text for the 
losing scenario
***************************************/

void finalMenu1()
{
    std::cout << "Game Over - You uncoverd the Mummy;" << std::endl;
    //insert ascii art
}

/**************************************
Menu for outputing the text for the
neutral scenario
***************************************/
void finalMenu2_1()
{
    std::cout << "Game Over - nuetral no money" << std::endl;
}

/**************************************
Menu for outputing the text for the
neutral scenario
***************************************/
void finalMenu2_2()
{
    std::cout << "Game Over - nuetral some money" << std::endl;
}

/***************************************
Menu for outputing the text for the
win scenario
****************************************/
void finalMenu3()
{
    std::cout << "Game Over - win;" << std::endl;
}


/********************************************
Menu for outputing the text for the
 true win scenario
********************************************/
void finalMenu4()
{
    std::cout << "Game Over - true win;" << std::endl;
}
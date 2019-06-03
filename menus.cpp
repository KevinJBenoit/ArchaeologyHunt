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

/**********************************************
Menu for the user to pick Player 1 and Player
2's team size.
Takes in a player number as a parameter.
Calls inputValidateIntegerAndRange()
Returns an intger from 1 - 40
***********************************************/
int startMenu()
{
    int size;
    std::cout << "Player , please enter the number of rounds " << std::endl;
    size = inputValidateIntegerAndRange(1, 40);
    std::cout << std::endl << std::endl;

    return size;
}


/**************************************

***************************************/

void subMenu1()
{

}

/**************************************

***************************************/
void subMenu2()
{

}

/****************************************************

*****************************************************/
void subMenu3()
{

}


/********************************************

********************************************/
bool finalMenu()
{
    int option;
    std::cout << "1. Play Again?" << std::endl;
    std::cout << "2. Quit" << std::endl;
    std::cout << "Option: ";
    option = inputValidateIntegerAndRange(1, 2);

    if (option == 1)
    {
        return true;
    }

    else
    {
        return false;
    }
}
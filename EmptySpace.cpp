/******************************************************************************
** Program name: EmptySpace.cpp
** Author: Kevin Benoit
** Date: 5/31/2019
** Description: The implementation file for the derived EmptySpace class.
    Inherits from Space.
*****************************************************************************/

#include "EmptySpace.hpp"
#include <iostream>

/***********************************
Default constructor. Inherits from
Space.
***********************************/
EmptySpace::EmptySpace() : Space()
{
    token = 'x';
    type = 'E';
}


/*************************************
Function that outputs the text if the player
decides to dig this space on the board.
*************************************/
void EmptySpace::spaceEvent()
{
    std::cout << "After hours of digging, you find nothing here." << std::endl
        << std::endl << std::endl;
}
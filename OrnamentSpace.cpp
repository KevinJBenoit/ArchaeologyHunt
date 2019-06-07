/******************************************************************************
** Program name: OrnamentSpace.cpp
** Author: Kevin Benoit
** Date: 6/03/2019
** Description: The implementation file for the derived OrnamentSpace class.
    Inherits from Space.
*****************************************************************************/

#include "OrnamentSpace.hpp"
#include <iostream>

/***********************************
Default constructor. Inherits from
Space. It's token is set to a mimic 'x'.
***********************************/
OrnamentSpace::OrnamentSpace() : Space()
{
    token = 'x';
    type = 'O';
}


/*************************************
Function that outputs the text if the player
decides to dig this space on the board.
*************************************/
void OrnamentSpace::spaceEvent()
{
    std::cout << "After hours of digging, you find a shiny gem! | "
        << "1 Gem added to the backpack, +100 points" 
        << std::endl << std::endl;
}
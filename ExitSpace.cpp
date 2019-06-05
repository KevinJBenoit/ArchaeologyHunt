/******************************************************************************
** Program name: ExitSpace.cpp
** Author: Kevin Benoit
** Date: 6/04/2019
** Description: The implementation file for the derived ExitSpace class.
    Inherits from Space.
*****************************************************************************/


#include "ExitSpace.hpp"
#include <iostream>

/********************************
Default constructor. Creates
the ExitSpace object.
Inherits from Space
********************************/
ExitSpace::ExitSpace() : Space()
{
    token = 'E';
    type = 'G';
}


/*************************************
Function that outputs the text if the player
decides to end the Game
*************************************/
void ExitSpace::spaceEvent()
{
    std::cout << "You get in your car and leave a trail of dust in your wake"
        << "as you drive away from the desert" << std::endl;
}
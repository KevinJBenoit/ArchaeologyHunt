/******************************************************************************
** Program name: BlankSpace.cpp
** Author: Kevin Benoit
** Date: 5/31/2019
** Description: The implementation file for the derived BlankSpace class.
    Inherits from Space.
*****************************************************************************/


#include "BlankSpace.hpp"
#include <iostream>

/**********************************
Default Constructor. Creates a
BlankSpace on the board.
**********************************/
BlankSpace::BlankSpace() : Space()
{
    token = ' ';
    type = 'B';
}


/********************************
Void function. There is no return.
********************************/
void BlankSpace::spaceEvent()
{
}
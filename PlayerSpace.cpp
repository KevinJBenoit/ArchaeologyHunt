/******************************************************************************
** Program name: PlayerSpace.cpp
** Author: Kevin Benoit
** Date: 6/01/2019
** Description: The implementation file for the PlayerSpace class.
*****************************************************************************/


#include "PlayerSpace.hpp"



/************************************
The default constructor. Creates the
PlayerSpace object to represent the
player
*************************************/
PlayerSpace::PlayerSpace() : Space()
{
    token = 'A';
}
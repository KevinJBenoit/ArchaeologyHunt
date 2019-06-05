/******************************************************************************
** Program name: ShopSpace.cpp
** Author: Kevin Benoit
** Date: 6/04/2019
** Description: The implementation file for the derived ShopSpace class.
    Inherits from Space.
*****************************************************************************/


#include "ShopSpace.hpp"
#include <iostream>

/***************************************
Default constructor. Creates a
ShopSpace object. Inherits from Space
***************************************/
ShopSpace::ShopSpace() : Space()
{
    token = 'S';
    type = 'S';
}


/***************************************
Function that outputs the text if the player
decides to visit the Shop
****************************************/
void ShopSpace::spaceEvent()
{
    std::cout << "Welcome to my shop traveler. What would you like to "
        << "trade for?" << std::endl;
}
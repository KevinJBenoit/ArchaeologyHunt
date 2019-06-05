/******************************************************************************
** Program name: MummySpace.hpp
** Author: Kevin Benoit
** Date: 6/04/2019
** Description: The implementation file for the derived MummySpace class.
    Inherits from Space.
*****************************************************************************/

#include "MummySpace.hpp"
#include <iostream>

/***************************************
Default constructor. Creates a
MummySpace object. Inherits from Space
***************************************/
MummySpace::MummySpace() : Space()
{
    token = 'M';
    type = 'M';
}


/***************************************
Function that outputs the text if the player
decides to digs up the MummySpace
****************************************/
void MummySpace::spaceEvent()
{
    std::cout << "Just as you are about to give up digging, you hear a *clang*"
        << std::endl;
    std::cout << "You wipe away the loose sand from a mysterious door. Prying "
        << "it open, you hear from within the black depths a ghostly voice..."
        << std::endl;
    std::cout << "----------------------------------------------------------"
        << std::endl;
    std::cout << " \" aNotheR TheIF heRe To STEAL whAT is MINE. When wiLL They "
        << "LeARn...\"" << std::endl;
    std::cout << "----------------------------------------------------------"
        << std::endl;
    std::cout << "Mummy arms reach out and pull you through the opening, and the "
        << "door slams shut behind you" << std::endl;
}
/******************************************************************************
** Program name: ArtifactSpace.cpp
** Author: Kevin Benoit
** Date: 6/03/2019
** Description: The implementation file for the derived ArtifactSpace class.
    Inherits from Space.
*****************************************************************************/

#include "ArtifactSpace.hpp"
#include "Gem.hpp"
#include <iostream>

/***********************************
Default constructor. Inherits from
Space. It's token is set to a mimic 'x'.
***********************************/
ArtifactSpace::ArtifactSpace() : Space()
{
    token = 'x';
    type = 'P';
    //content = new Gem(); //****************************************************************potential memory leak??????
}


/*************************************
Function that outputs the text if the player
decides to dig this space on the board.
*************************************/
void ArtifactSpace::spaceEvent()
{
    std::cout << "Just as you are about to give up digging, you hear a *clang*"
        << std::endl
        << " as your shovel hits the ground. You wipe the loose sand away from"
        << std::endl
        << " an ornate box. You open it up and see the unmistakable engravings"
        << std::endl
        << " of the Pharaoh's ancient language. You have found your prize!"
        << std::endl
        << " Now all you have to do is get out of here..."
        << std::endl << std::endl;
}
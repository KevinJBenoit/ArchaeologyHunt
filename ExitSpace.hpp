/******************************************************************************
** Program name: ExitSpace.hpp
** Author: Kevin Benoit
** Date: 6/04/2019
** Description: Contains the class declaration for the derived ExitSpace
    class. The ExitSpace will end the game when the player enters it. It will
    be off the board.
*****************************************************************************/

#ifndef EXITSPACE_HPP
#define EXITSPACE_HPP

#include "Space.hpp"

class ExitSpace : public Space
{

    public:
        ExitSpace();

        void spaceEvent();
};

#endif
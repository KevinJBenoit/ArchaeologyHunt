/******************************************************************************
** Program name: EmptySpace.hpp
** Author: Kevin Benoit
** Date: 5/31/2019
** Description: Contains the class declaration for the derived EmptySpace
    class. Each EmptySpace inherits from the parent Space class. An EmptySpace
    will be marked on the board as a dig site but will not benefit or hinder
    the player.
*****************************************************************************/

#ifndef EMPTYSPACE_HPP
#define EMPTYSPACE_HPP

#include "Space.hpp"


class EmptySpace : public Space
{
    public:
        EmptySpace();

        void spaceEvent();
};

#endif
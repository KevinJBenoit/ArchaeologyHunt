/******************************************************************************
** Program name: BlankSpace.hpp
** Author: Kevin Benoit
** Date: 5/31/2019
** Description: Contains the class declaration for the derived BlankSpace
    class. Each BlankSpace inherits from the parent Space class. A BlankSpace
    will represent the negative space between dig sites on the board. A player
    moving onto a BlankSpace will have nothing happen at all.
*****************************************************************************/


#ifndef BLANKSPACE_HPP
#define BLANKSPACE_HPP

#include "Space.hpp"

class BlankSpace : public Space
{
    public:
        BlankSpace();

        void spaceEvent();
};

#endif
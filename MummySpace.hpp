<<<<<<< HEAD
#pragma once
=======
/******************************************************************************
** Program name: MummySpace.hpp
** Author: Kevin Benoit
** Date: 6/04/2019
** Description: Contains the class declaration for the derived MummySpace
    class. The MummySpace will be an automatic gameOver condition that
    causes the player to lose.
*****************************************************************************/

#ifndef MUMMYSPACE_HPP
#define MUMMYSPACE_HPP

#include "Space.hpp"

class MummySpace : public Space
{
    public:
        MummySpace();

        void spaceEvent();
};
#endif
>>>>>>> feat/MummySpace

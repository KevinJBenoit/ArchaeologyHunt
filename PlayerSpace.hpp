/******************************************************************************
** Program name: PlayerSpace.hpp
** Author: Kevin Benoit
** Date: 6/01/2019
** Description: Contains the class declaration for the derived PlayerSpace
    class. A PlayerSpace inherits from the parent Space class. A PlayerSpace
    represents the location on the board the player is in, denoted by it's
    token 'A' for Archaelogist.
*****************************************************************************/

#ifndef PLAYERSPACE_HPP
#define PLAYERSPACE_HPP

#include "Space.hpp"

class PlayerSpace : public Space
{
    private:
        int score;
        //how to deal with backpack of items for inventor.....

    public:
        PlayerSpace();

};

#endif
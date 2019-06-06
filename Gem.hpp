/******************************************************************************
** Program name: Gem.hpp
** Author: Kevin Benoit
** Date: 6/03/2019
** Description: Contains the class declaration for the derived Gem class. Each
    Gem in the Player container will increase their score and the weight
    of the container.
*****************************************************************************/

#ifndef GEM_HPP
#define GEM_HPP

#include "Item.hpp"

class Gem : public Item
{
    private:
        int value;

    public:
        Gem();

        int getValue();
};

#endif
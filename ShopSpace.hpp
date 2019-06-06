/******************************************************************************
** Program name: ShopSpace.hpp
** Author: Kevin Benoit
** Date: 6/04/2019
** Description: Contains the class declaration for the derived ShopSpace
    class. The ShopSpace will allow the Player to purchase items with points
    and add them to their backpack container
*****************************************************************************/

#ifndef SHOPSPACE_HPP
#define SHOPSPACE_HPP

#include "Space.hpp"

class ShopSpace : public Space
{
    public:
        ShopSpace();

        void spaceEvent();
};

#endif
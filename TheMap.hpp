/******************************************************************************
** Program name: TheMap.hpp
** Author: Kevin Benoit
** Date: 6/05/2019
** Description: Contains the class declaration for the derived TheMap class.
    TheMap is an item to be put in the Player container and will remove some of
    the false dig sites, aka EmptySpaces.
*****************************************************************************/

#ifndef THEMAP_HPP
#define THEMAP_HPP

#include "Item.hpp"

class TheMap : public Item
{
    public:
        TheMap();
};

#endif
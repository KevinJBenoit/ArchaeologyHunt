/******************************************************************************
** Program name: TheEye.hpp
** Author: Kevin Benoit
** Date: 6/04/2019
** Description: Contains the class declaration for the derived TheEye class.
    TheEye is an item to be put in the Player container and will reveal the
    MummySpace on the Map.
*****************************************************************************/


#ifndef THEEYE_HPP
#define THEEYE_HPP

#include "Item.hpp"

class TheEye : public Item
{
    public:
        TheEye();
};

#endif
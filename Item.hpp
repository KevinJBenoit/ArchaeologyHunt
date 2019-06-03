/******************************************************************************
** Program name: Item.hpp
** Author: Kevin Benoit
** Date: 5/31/2019
** Description: Contains the class declaration for the base Item class. Each
    Item represents something that the player can put into their inventory.
    Each Item has has a integer price and string name. Virtual functions will
    also be inherited by derived classes.
*****************************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Item
{
    protected:
        int weight;
        std::string name;

    public:
        virtual int getWeight();
        virtual std::string getName();

        Item();
};

#endif
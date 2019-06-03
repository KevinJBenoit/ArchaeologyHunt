/******************************************************************************
** Program name: Item.cpp
** Author: Kevin Benoit
** Date: 5/31/2019
** Description: The implementation file for the base Item class.
*****************************************************************************/

#include "Item.hpp"


/***********************************
Default constructor. Creates an invalid
Item.
***********************************/
Item::Item()
{
    weight = -100;
    name = "InvalidItem";
}

/*************************************
Getter function for accessing this Item's
price.
**************************************/
int Item::getWeight()
{
    return weight;
}


/*************************************
Getter function for accessing this Item's
name.
**************************************/
std::string Item::getName()
{
    return name;
}
/******************************************************************************
** Program name: TheMap.cpp
** Author: Kevin Benoit
** Date: 6/05/2019
** Description: The implementation file for the derived TheMap class.
*****************************************************************************/

#include "TheMap.hpp"


/*******************************************
Default constructor. Creates TheMap object.
Inherits from Item
********************************************/
TheMap::TheMap() : Item()
{
    weight = 2;
    name = "The Map";
}
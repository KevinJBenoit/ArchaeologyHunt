/******************************************************************************
** Program name: TheTent.cpp
** Author: Kevin Benoit
** Date: 6/05/2019
** Description: The implementation file for the derived TheMap class.
*****************************************************************************/


#include "TheTent.hpp"

/***********************************
Default constructor. Creates TheTent
object. Inherits from Item
************************************/
TheTent::TheTent() : Item()
{
    weight = 1;
    name = "The Tent";
}
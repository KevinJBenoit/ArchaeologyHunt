/******************************************************************************
** Program name: TheEye.cpp
** Author: Kevin Benoit
** Date: 6/03/2019
** Description: The implementation file for the derived TheEye class.
*****************************************************************************/

#include "TheEye.hpp"


/*****************************************
Default constructor. Creates TheEye object.
Inherits from Item.
******************************************/
TheEye::TheEye() : Item()
{
    weight = 3;
    name = "The Eye of Horace";
}
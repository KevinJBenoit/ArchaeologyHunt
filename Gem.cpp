/******************************************************************************
** Program name: Gem.cpp
** Author: Kevin Benoit
** Date: 6/03/2019
** Description: The implementation file for the derived Gem class.
*****************************************************************************/


#include "Gem.hpp"



/**********************************
Default constructor. Creats a Gem
object. Scoped to Item
**********************************/
Gem::Gem() : Item()
{
    weight = 1;
    value = 100;
    name = "Gem";
}

/**********************************
Getter function for accessing the
value of the Gem
**********************************/
int Gem::getValue()
{
    return value;
}
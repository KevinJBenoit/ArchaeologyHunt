/******************************************************************************
** Program name: OrnamentSpace.hpp
** Author: Kevin Benoit
** Date: 6/03/2019
** Description: Contains the class declaration for the derived OrnamentSpace
    class. Each OrnamentSpace inherits from the parent Space class. 
    An OrnamentSpace will be marked on the board as a dig site but will 
    add points to the player's score that can be used to purchase items.
*****************************************************************************/

#ifndef ORNAMENTSPACE_HPP
#define ORNAMENTSPACE_HPP

#include "Space.hpp"


class OrnamentSpace : public Space
{
public:
    OrnamentSpace();

    void spaceEvent();
};
#endif
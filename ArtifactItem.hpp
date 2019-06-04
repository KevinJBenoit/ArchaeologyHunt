/******************************************************************************
** Program name: ArtifactItem.hpp
** Author: Kevin Benoit
** Date: 6/03/2019
** Description: Contains the class declaration for the derived ArtifactItem 
    class. The ArtifactItem in the Player container will set the necessary 
    win condition upon exiting the Game.
*****************************************************************************/

#ifndef ARTIFACTITEM_HPP
#define ARTIFACT_HPP

#include "Item.hpp"

class ArtifactItem : public Item
{

public:
    ArtifactItem();
};

#endif
/******************************************************************************
** Program name: ArtifactItem.cpp
** Author: Kevin Benoit
** Date: 6/03/2019
** Description: The implementation file for the derived ArtifactItem class.
*****************************************************************************/


#include "ArtifactItem.hpp"



/**********************************
Default constructor. Creats a Gem
object. Scoped to Item
**********************************/
ArtifactItem::ArtifactItem() : Item()
{
    weight = 3;
    name = "Pharaoh's Artifact";
}

/******************************************************************************
** Program name: ArtifactSpace.hpp
** Author: Kevin Benoit
** Date: 6/03/2019
** Description: Contains the class declaration for the derived ArtifactSpace
    class. A ArtifactSpace inherits from the parent Space class.
    An ArtifactSpace will be marked on the board as a dig site but will
    fulfill the necessary condition for a successful GameOver.
*****************************************************************************/

#ifndef ARTIFACTSPACE_HPP
#define ARTIFACTSPACE_HPP

#include "Space.hpp"


class ArtifactSpace : public Space
{
public:
    ArtifactSpace();

    void spaceEvent();
};
#endif
/******************************************************************************
** Program name: Space.cpp
** Author: Kevin Benoit
** Date: 5/31/2019
** Description: The implementation file for the base abstract class Space.
*****************************************************************************/


#include "Space.hpp"


/***************************************
Default Constructor. Used to create
an empty Space.
***************************************/
Space::Space()
{
    top = nullptr;
    bottom = nullptr;
    left = nullptr;
    right = nullptr;
    token = 'N';
    type = 'N';
}

/***************************************
Virtual Destructor. Will be ineherited by
derived classes
***************************************/
Space::~Space()
{
}


/****************************************
Getter/setter functions for this Space's
top variable.
****************************************/
Space * Space::getTop()
{
    return top;
}

void Space::setTop(Space *topIn)
{
    top = topIn;
}

/****************************************
Getter/setter functions for this Space's
bottom variable.
****************************************/
Space * Space::getBottom()
{
    return bottom;
}

void Space::setBottom(Space *bottomIn)
{
    bottom = bottomIn;
}

/****************************************
Getter/setter functions for this Space's
left variable.
****************************************/
Space * Space::getLeft()
{
    return left;
}

void Space::setLeft(Space *leftIn)
{
    left = leftIn;
}

/****************************************
Getter/setter functions for this Space's
right variable.
****************************************/
Space * Space::getRight()
{
    return right;
}

void Space::setRight(Space * rightIn)
{
    right = rightIn;
}

/****************************************
Getter/setter functions for this Space's
token variable.
****************************************/
char Space::getToken()
{
    return token;
}

void Space::setToken(char tokenIn)
{
    token = tokenIn;
}

/*****************************************
Function that changes this Space's token
to a 'blank' space on the board when printed
******************************************/
void Space::removeToken()
{
    token = ' ';
}


/****************************************
Getter function for this Space's
type variable.
****************************************/
char Space::getType()
{
    return type;
}
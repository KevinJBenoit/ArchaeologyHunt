/******************************************************************************
** Program name: Player.cpp
** Author: Kevin Benoit
** Date: 6/03/2019
** Description: The implementation file for the class Player.
*****************************************************************************/

#include "Player.hpp"




/************************************
Default constructor. Creates a Player
object
************************************/
Player::Player()
{
    score = 0;
}

/*************************************
Destructor. Frees memory in the backpack
*************************************/
Player::~Player()
{
    for (int i = 0; i < static_cast<int>(backpack.size()); i++)
    {
        delete backpack.at(i);
    }
}

/************************************
Getter/setter functions for the Players
score member variable.
*************************************/
int Player::getScore()
{
    return score;
}

void Player::setScore(int scoreIn)
{
    score = scoreIn;
}

/*************************************
Function for changing the player's score.
Pass in the value to add to the current.
Takes: int valueIn
**************************************/
void Player::adjustScore(int valueIn)
{
    score += valueIn;
}


/*************************************
Getter function for accessing the Player's
backpack vector.
*************************************/
std::vector<Item*> Player::getBackpack()
{
    return backpack;
}




void Player::addToBackpack(Item* thing)
{
    backpack.push_back(thing);
}
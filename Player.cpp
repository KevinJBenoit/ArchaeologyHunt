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
    heaviness = 0;
    gemCount = 0;
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



/************************************
Function for adding an Item to the Players
inventory container. Will also increase the
heaviness. IMPLEMENT WEIGHT CHECK HERE??????????????????????????????????????????????????????????????
*************************************/
void Player::addToBackpack(Item* thing)
{
    if (thing->getName() == "Gem")
    {
        gemCount++;
        score += 100;
    }
    backpack.push_back(thing);
    heaviness += thing->getWeight();
}

/*************************************
Getter function for accessing the Player's
heaviness.
**************************************/
int Player::getHeaviness()
{
    return heaviness;
}



int Player::getGemCount()
{
    return gemCount;
}



/*************************************
Function for dropping an Item from the
backpack container
**************************************/
void Player::dropGem()
{
    if (gemCount > 0)
    {
        for (int i = 0; i < static_cast<int>(backpack.size()); i++)
        {
            if (backpack.at(i)->getName() == "Gem")
            {
                heaviness -= backpack.at(i)->getWeight();
                //drop the gem
                delete backpack.at(i); //***********************************************CHECK HERE
                backpack.erase(backpack.begin() + i);
                score -= 100;
                
                //exit the function
                return;
            }
        }
    }
}
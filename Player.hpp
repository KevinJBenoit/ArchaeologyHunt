/******************************************************************************
** Program name: Player.hpp
** Author: Kevin Benoit
** Date: 6/03/2019
** Description: Contains the class declaration for the Player class.
    Each Player has a container for the user to carry Items with a capacity
    limit. The Player having these Items are needed for the user to win the
    game.
*****************************************************************************/


#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "Item.hpp"

class Player
{
    private:
        std::vector<Item*> backpack;
        int score;
        int heaviness;

    public:
        Player();
        ~Player();

        int getScore();
        void setScore(int scoreIn);
        void adjustScore(int valueIn);
        int getHeaviness();

        std::vector<Item*> getBackpack();
        void addToBackpack(Item* thing);
};

#endif

/******************************************************************************
** Program name: Game.hpp
** Author: Kevin Benoit
** Date: 5/31/2019
** Description: Contains the class declaration for the Game class. The Game
    acts as Menu functions for running the game by using a DoublyLinked List
    Structure of Spaces to create and run the board.
*****************************************************************************/




#ifndef GAME_HPP
#define GAME_HPP

#include "Space.hpp"
#include "PlayerSpace.hpp"
#include <vector>
#include <memory>


class Game
{
    private:
        char directionsArray[4];
        int timer;
        Space* head[10];
        //cplusplus.com/forum/general/55651/
        std::vector<Space *> nodes;

        Space * player;

    public:
        Game();
        ~Game();

        void setup();
        void round();
        void movePlayer();

        void createBoard();
        void printBoard();

        int getTimer();
};

#endif
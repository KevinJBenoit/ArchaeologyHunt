/******************************************************************************
** Program name: Game.hpp
** Author: Kevin Benoit
** Date: 5/31/2019
** Description: Contains the class declaration for the Game class. The Game
    acts as Menu functions for running the game by using a Quadruple LinkedList
    Structure of Spaces to create and run the board logic.
*****************************************************************************/


#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Space.hpp"
#include <vector>
#include <memory>


class Game
{
    private:
        char directionsArray[4];
        int timer;
        Space* head[10];
        std::vector<Space *> nodes;

        Space * player;
        Player user;
        Space * shop;

        void purchase();
        void playerDrop();
        bool gameOver;
        int endConditions;
        bool shopOpen = false;

    public:
        Game();
        ~Game();

        void setup();
        void round();
        void movePlayer();
        void dig(char type);

        void createBoard();
        void printBoard();

        int getTimer();
        void printScore();
        int getEndConditions();
        bool getGameOver();
        int getScore();
};
#endif
/******************************************************************************
** Program name: main.cpp
** Author: Kevin Benoit
** Date: 5/31/2019
** Description: Runs the FinalProject - Archaelogy Hunt game. A 2D 
    DoublyLinkedList structure will be used as the basis of the program, where 
    each Node will contain a Space * to a derived Space class that affects the
    game in some way. The player will be the cursor and be able to move around
    the board with WASD keys. Unused boundaries will be set to nullptr.
    A separate Player class will keep track of the score and the players
    inventory of items using a <stack>.
    The time limit will be implemented by limiting the number of steps the
    player can take.
    The Menu functions will be held by the Game class which runs the game.
*****************************************************************************/

#include "Game.hpp"
#include "inputValidate.hpp"

int main()
{

    Game game1 = Game();

    game1.setup();

    do
    {
        game1.round();
    } while (game1.getTimer() > 0);




    system("pause"); //*********************************************************REMMOVE
    return 0;
}
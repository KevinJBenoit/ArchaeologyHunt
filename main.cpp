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
#include "menus.hpp"
#include "inputValidate.hpp"

int main()
{
    bool endGame = false;
    int ending;

    Game game1 = Game();

    game1.setup();

    do
    {
        game1.round();
        endGame = game1.getGameOver();

    } while (game1.getTimer() > 0 && !endGame);


    //check for which endConditions
    ending = game1.getEndConditions();

    if (ending < 0)
    {
        finalMenu1(); //losing end
    }
    else if (ending == 0)
    {
        if (game1.getScore() > 0)
        {
            finalMenu2_2(); //neutral end some score/gems
        }
        else
        {
            finalMenu2_1(); //neutral end no score/gems
        }
        
    }
    else if (ending == 1)
    {
        if (game1.getScore() > 500)
        {
            finalMenu4();//true win end
        }
        else
        {
            finalMenu3(); //win end
        }   
    }


    system("pause"); //*********************************************************REMMOVE
    return 0;
}
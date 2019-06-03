/******************************************************************************
** Program name: Game.cpp
** Author: Kevin Benoit
** Date: 5/31/2019
** Description: The implementation file for the Game class.
*****************************************************************************/


#include "Game.hpp"
#include <iostream>
#include "EmptySpace.hpp"
#include "BlankSpace.hpp"
#include "inputValidate.hpp"
#include <algorithm>

/*********************************
Default constructor. Creates the
Game object and sets up initial
variables
**********************************/
Game::Game()
{
    directionsArray[0] = 'w', directionsArray[1] = 'a';
    directionsArray[2] = 's', directionsArray[3] = 'd';
    timer = 50;

    //generate the ratio of spaces
    for (int i = 0; i < 20; i++)
    {
        //Credit: cplusplus.com/forum/general/157242/
        nodes.emplace_back(new EmptySpace());
    }
    for (int i = 0; i < 80; i++)
    {
        nodes.emplace_back(new BlankSpace());
    }
    
    //shuffle the spaces
    std::random_shuffle(nodes.begin(), nodes.end());
    
}


/*****************************************
Destructor. Frees memory allocated
during the game
*****************************************/
Game::~Game()
{
    for (int i = 0; i < static_cast<int>(nodes.size()); i++)
    {
        delete nodes.at(i);
    }
}


/**************************************
Function that sets up the conditions for
the game. Creates the board and outputs
opening text.
Calls:createBoard()
Rturns: none
***************************************/
void Game::setup()
{
    Space * setupCursor = head[0];
    bool startFound = false;
    int counter = 0;
    int headCounter = 0;
    //generate the board design
    createBoard();


    /****************
    Find a BlankSpace
    to put the player
    *****************/
    while (headCounter <= 9 && startFound == false)
    {
        //start in the top left corner
        setupCursor = head[headCounter];
        //find a BlankSpace to place the player
        while (startFound == false && counter <= 9)
        {
            if (setupCursor->getToken() == ' ')
            {
                //found a blank space
                startFound = true;
            }
            else
            {
                setupCursor = setupCursor->getRight();
                counter++;
            }
        }

        //increment the row
        headCounter++;
    }
    
    //place the player and token there
    setupCursor->setToken('A');
    player = setupCursor;

    std::cout << "Starting Board:" << std::endl;
    printBoard();
}





/*************************************
Function that runs one round of the
game. Player is able move around the board
through validated input
Calls: movePlayer(), printBoard()
Returns: none
***************************************/
void Game::round()
{
    movePlayer();




    printBoard();

}

/*************************************
Function that runs one round of the
game. Player is able move around the board
through validated input
Calls: inputValidateCharArray()
Returns: none
***************************************/
void Game::movePlayer()
{
    char direction = inputValidateCharArray(directionsArray, 4);

    //move up
    if (direction == 'w' && player->getTop() != nullptr)
    {
        player->setToken(' ');
        player = player->getTop();
        player->setToken('A');
    }

    //move down
    else if (direction == 's' && player->getBottom() != nullptr)
    {
        player->setToken(' ');
        player = player->getBottom();
        player->setToken('A');
    }
    //move left
    else if (direction == 'a' && player->getLeft() != nullptr)
    {
        player->setToken(' ');
        player = player->getLeft();
        player->setToken('A');
    }
    //move right
    else if (direction == 'd' && player->getRight() != nullptr)
    {
        player->setToken(' ');
        player = player->getRight();
        player->setToken('A');
    }
}

/***********************************
Function that creates the 2D Doubly Linked
List of Spaces that represents the board.
Will be navigatable by the player.
************************************/
void Game::createBoard()
{
    int vectorIncrementor = 0;
    int tempCounter;

    /*************************************************
    First, create a series of Linear Linked Lists
    *************************************************/

    for (int i = 0; i < 10; i++)
    {
        //establish the heads with right only
        head[i] = nodes.at(vectorIncrementor);
        nodes.at(vectorIncrementor)->setRight(nodes.at(vectorIncrementor + 1));
        vectorIncrementor++;

        //establish the middle values with left and right
        tempCounter = vectorIncrementor;
        for (int j = tempCounter; j < tempCounter + 8; j++)
        {
            nodes.at(vectorIncrementor)->setRight(nodes.at(vectorIncrementor + 1));
            nodes.at(vectorIncrementor)->setLeft(nodes.at(vectorIncrementor - 1));
            vectorIncrementor++;
        }

        //establish the tail of the row with left only
        nodes.at(vectorIncrementor)->setLeft(nodes.at(vectorIncrementor - 1));
        vectorIncrementor++;
    }


    /***********************************************
    Then, stich everything together by linking
    the tops and bottoms
    ***********************************************/
    Space * cursorSpace;
    Space * bottomCursor;
    Space * topCursor;

    /************************
    link the bottom pointers 
    exclude the bottom row
    *************************/
    for (int i = 0; i < 9; i++)
    {
        cursorSpace = head[i];
        //cursor that follows the top one
        bottomCursor = head[i+1];

        //establish bottom link
        cursorSpace->setBottom(bottomCursor);

        //move both over
        cursorSpace = cursorSpace->getRight();
        bottomCursor = bottomCursor->getRight();

        //loop until end of row
        while(cursorSpace != nullptr)
        {
            cursorSpace->setBottom(bottomCursor);

            cursorSpace = cursorSpace->getRight();
            bottomCursor = bottomCursor->getRight();
        }
    }

    /************************
    link the top pointers
    exclude the top row
    *************************/
    for (int i = 9; i > 1; i--)
    {
        cursorSpace = head[i];
        //cursor that follows the bottom one
        topCursor = head[i-1];

        //establish top link
        cursorSpace->setTop(topCursor);

        //move both over
        cursorSpace = cursorSpace->getRight();
        topCursor = topCursor->getRight();

        //loop until end of row
        while (cursorSpace != nullptr)
        {
            cursorSpace->setTop(topCursor);

            cursorSpace = cursorSpace->getRight();
            topCursor = topCursor->getRight();
        }
    }
}




/*************************************
Function that outputs to the console the
current state of the 2D DoublyLinked List/
board.
***************************************/
void Game::printBoard()
{
    Space * cursorSpace;

    for (int i = 0; i < 12; i++)
    {
        std::cout << '-';
    }
    std::cout << std::endl;
    
    //print the conents
    for (int i = 0; i < 10; i++)
    {
        cursorSpace = head[i];
        std::cout << '|';
        for (int i = 0; i < 10; i++)
        {
            std::cout << cursorSpace->getToken();
            cursorSpace = cursorSpace->getRight();
        }
        std::cout << '|' << std::endl;
    }

    //print the floor
    for (int i = 0; i < 12; i++)
    {
        std::cout << '-';
    }
    std::cout << std::endl;
}


/*****************************************
Getter function for accessing the member
variable timer
Returns: int timer
******************************************/
int Game::getTimer()
{
    return timer;
}
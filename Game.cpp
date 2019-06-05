/******************************************************************************
** Program name: Game.cpp
** Author: Kevin Benoit
** Date: 5/31/2019
** Description: The implementation file for the Game class.
*****************************************************************************/

#define ROUNDS 30

#include "Game.hpp"
#include "menus.hpp"
#include <iostream>
#include "EmptySpace.hpp"
#include "BlankSpace.hpp"
#include "ExitSpace.hpp"
#include "ShopSpace.hpp"
#include "ArtifactSpace.hpp"
#include "OrnamentSpace.hpp"
#include "Gem.hpp"
#include "ArtifactItem.hpp"
#include "inputValidate.hpp"
#include <algorithm>

/*********************************
Default constructor. Creates the
Game object and sets up initial
variables
**********************************/
Game::Game()
{
    user = Player();

    directionsArray[0] = 'w', directionsArray[1] = 'a';
    directionsArray[2] = 's', directionsArray[3] = 'd';
    timer = ROUNDS;

    //generate the ratio of spaces
    for (int i = 0; i < 10; i++)
    {
        //Credit: cplusplus.com/forum/general/157242/
        nodes.emplace_back(new EmptySpace());
    }
    for (int i = 0; i < 10; i++)
    {
        //Credit: cplusplus.com/forum/general/157242/
        nodes.emplace_back(new OrnamentSpace());
    }
    for (int i = 0; i < 79; i++)
    {
        nodes.emplace_back(new BlankSpace());
    }
    //generate the winning space
    nodes.emplace_back(new ArtifactSpace());


    //shuffle the spaces
    std::random_shuffle(nodes.begin(), nodes.end());
    
    //place the ExitSpace at the end so it isn't used in board generation
    nodes.emplace_back(new ExitSpace());
    //place a ShopSpace
    nodes.emplace_back(new ShopSpace());

    gameOver = false;
    endConditions = 0;
    shopOpen = true;
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
    
    //move token and generate space event
    movePlayer();

    if (gameOver)
    {
        printBoard();
        return;
    }

    //print score
    printScore();


    //print board
    printBoard();
    
    timer--;
}

/*************************************
Function that moves the player 1 space. 
Player is able move around the board
except past the borders.
Calls: inputValidateCharArray()
Returns: none
***************************************/
void Game::movePlayer()
{
    char direction = inputValidateCharArray(directionsArray, 4);
    char spaceType = ' ';

    //move up
    if (direction == 'w' && player->getTop() != nullptr)
    {
        player->setToken(' ');
        player = player->getTop();

        //check for a space event
        spaceType = player->getToken();

        //if not a BlankSpace, generate event
        if (spaceType != ' ')
        {
            dig(player->getType());
        }

        player->setToken('A');
    }

    //move down
    else if (direction == 's' && player->getBottom() != nullptr)
    {
        player->setToken(' ');
        player = player->getBottom();

        //check for a space event
        spaceType = player->getToken();

        //if not a BlankSpace, generate event
        if (spaceType != ' ')
        {
            dig(player->getType());
        }

        player->setToken('A');
    }
    //move left
    else if (direction == 'a' && player->getLeft() != nullptr)
    {
        player->setToken(' ');
        player = player->getLeft();

        //check for a space event
        spaceType = player->getToken();

        //if not a BlankSpace, generate event
        if (spaceType != ' ')
        {
            dig(player->getType());
        }

        player->setToken('A');
    }
    //move right
    else if (direction == 'd' && player->getRight() != nullptr)
    {
        player->setToken(' ');
        player = player->getRight();

        //check for a space event
        spaceType = player->getToken();

        //if not a BlankSpace, generate event
        if (spaceType != ' ')
        {
            dig(player->getType());
        }

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
    Credit: geeksforgeeks.org/construct-a-linked-list-from-2d-matrix-iterative-approach/
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
    for (int i = 9; i > 0; i--)
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

    /**************************
    Link the ExitSpace and
    ShopSpacein the border
    ***************************/
    head[0]->setTop(nodes.at(vectorIncrementor));
    vectorIncrementor++;

    head[9]->setBottom(nodes.at(vectorIncrementor));
    cursorSpace = head[9]->getBottom();
    cursorSpace->setTop(head[9]);
    shop = cursorSpace;
    vectorIncrementor++;
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
        if (i == 1)
        {
            std::cout << 'E';
        }
        else
        {
            std::cout << '-';
        }
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
        //printing the shop
        if (i == 1 && shopOpen)
        {
            switch (shopOpen)  
            {
            case true: std::cout << nodes.at(101)->getToken(); //if changing board size fix this*********************************
                break;
            case false: std::cout << '-';
            }
       
        }
        else if (i == 1 && shop->getToken() == 'A')
        {
            std::cout << 'A';
        }
        else
        {
            std::cout << '-';
        }
    }
    std::cout << std::endl;
}


/*****************************************
Function that outputs the current score
of the user
*****************************************/
void Game::printScore()
{
    std::cout << "Score: " << user.getScore() << std::endl;
    //print the backpack

    std::cout << "Backpack: ";
    std::cout << "Encumbrance: " << user.getHeaviness() << "/10"
        << std::endl;
    if (user.getBackpack().size() > 0)
    {
        for (int i = 0; i < static_cast<int>(user.getBackpack().size()); i++)
        {
            std::cout << user.getBackpack().at(i)->getName() << " | ";
        }
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

/*****************************************
Getter function for accessing the
endConditions vairable
Returns: int endConditions
******************************************/
int Game::getEndConditions()
{
    return endConditions;
}

/*****************************************
Getter function for accessing the gameOver
variable
Returns: bool gameOver
******************************************/
bool Game::getGameOver()
{
    return gameOver;
}


/*****************************************
Getter function for accessing the Player's
score variable
Returns: int score
******************************************/
int Game::getScore()
{
    return user.getScore();
}


/*****************************************
Function for resolving Space Events.
Calls: Space::spaceEvent()
Returns: none
******************************************/
void Game::dig(char type)
{
    player->spaceEvent();

    //if EmptySpace
    if (type == 'E')
    {
        return;
    }

    //if OrnamentSpace
    else if (type == 'O') 
    {
        //add to player's inventory
        user.addToBackpack(new Gem());
        //increase the player's score
        user.adjustScore(100);
    }

    //if ArtifactSpace
    else if (type == 'P')
    {
        user.addToBackpack(new ArtifactItem());
        endConditions++;
    }

    //if ExitSpace
    else if (type == 'G')
    {
        gameOver = true;
    }

    //if ShopSpace
    else if (type == 'S')
    {

        int option = itemMenu();
        //menu function
        if (option == 1)
        {
            //purchase The Eye of Horace
        }
        else if (option == 2)
        {
            //purchase The Map
        }
        else if (option == 3)
        {
            //purchase The Tent
        }
        else if (option == 4)
        {
            std::cout << "Fine, keep your money. ";
        }

        std::cout << "Just so you know, the door locks on your way out! MUAHAHA"
            << std::endl << std::endl;

        //"lock" the Shop
        shopOpen = false;
        head[9]->setBottom(nullptr);
    }
}
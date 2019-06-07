/******************************************************************************
** Program name: Game.cpp
** Author: Kevin Benoit
** Date: 5/31/2019
** Description: The implementation file for the Game class.
*****************************************************************************/

#define ROUNDS 60

#include "Game.hpp"
#include "menus.hpp"
#include <iostream>
#include "EmptySpace.hpp"
#include "BlankSpace.hpp"
#include "ExitSpace.hpp"
#include "ShopSpace.hpp"
#include "MummySpace.hpp"
#include "ArtifactSpace.hpp"
#include "OrnamentSpace.hpp"
#include "Gem.hpp"
#include "ArtifactItem.hpp"
#include "TheEye.hpp"
#include "TheMap.hpp"
#include "TheTent.hpp"
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
        nodes.emplace_back(new EmptySpace);
    }

    for (int i = 0; i < 10; i++)
    {
        //Credit: cplusplus.com/forum/general/157242/
        nodes.emplace_back(new OrnamentSpace);
    }

    for (int i = 0; i < 78; i++)
    {
        //Credit: cplusplus.com/forum/general/157242/
        nodes.emplace_back(new BlankSpace);
    }

    //generate the winning space
    nodes.emplace_back(new ArtifactSpace);

    //generate the losing space
    nodes.emplace_back(new MummySpace);


    //shuffle the spaces
    std::random_shuffle(nodes.begin(), nodes.end());
    //make sure mummy doesnt spawn in front of exit or shop
    if (nodes.at(0)->getType() == 'M')
    {
        std::iter_swap(nodes.begin() + 0, nodes.begin() + 1);
    }
    if (nodes.at(90)->getType() == 'M')
    {
        std::iter_swap(nodes.begin() + 90, nodes.begin() + 91);
    }
    
    //place the Shop and ExitSpace at the end so it isn't used in board generation
    nodes.emplace_back(new ExitSpace);
    //place a ShopSpace
    nodes.emplace_back(new ShopSpace);

    gameOver = false;
    endConditions = 0;
    shopOpen = true;
}


/*****************************************
Destructor. Frees memory allocated
during the game by the Linked List board
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
Calls:createBoard(), printBoard()
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
Calls: movePlayer(), printBoard() printScore()
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
    if (timer < 0)
    {
        gameOver = true;
    }
}

/*************************************
Function that moves the player 1 space. 
Player is able move around the board
except past the borders.
Calls: inputValidateCharArray(), dig()
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
Function that creates the 2D Quadruple Linked
List of Spaces that represents the board.
Will be navigatable by the player.
Calls: class Space* functions
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

    /***********************
    link the bottom pointers 
    exclude the bottom row
    ************************/
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
current state of the 2D Quadruple LinkedList/
board.
Calls: class Space* functions
***************************************/
void Game::printBoard()
{
    Space * cursorSpace;
    std::cout << "Steps Left: " << timer << std::endl;
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
    
    //print the contents
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
        //printing the shop open
        if (i == 1 && shopOpen)
        {
            switch (shopOpen)  
            {
            case true: std::cout << nodes.at(101)->getToken();
                break;
            case false: std::cout << '-';
            }
       
        }
        //if the player is standing on the ShopSpace
        else if (i == 1 && shop->getToken() == 'A')
        {
            std::cout << 'A';
        }
        //print the shop closed
        else
        {
            std::cout << '-';
        }
    }
    std::cout << std::endl << std::endl;
}


/*****************************************
Function that outputs the current score, 
Items in the backpack, and weight of the
backpack of the user.
*****************************************/
void Game::printScore()
{
    std::cout << "Score: " << user.getScore() << std::endl;
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
Player::addToBackpack, dropGem()
Game::purchase()
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
        if (user.getHeaviness() == 10)
        {
            std::cout << "You can only carry so much. Unfortunately you have "
                << "to leave this Gem behind" << std::endl;
        }
        else
        {
            //add to player's inventory
            user.addToBackpack(new Gem);
        }
    }

    //if ArtifactSpace
    else if (type == 'P')
    {
        if (user.getHeaviness())
        {
            int difference = user.getHeaviness() - 7;
            //if more space is needed
            if (difference > 0)
            {
                std::cout << "You found your prize! However you have to drop "
                    << difference << " Gems in order to carry it" << std::endl;

                for (int i = 0; i < difference; i++)
                {
                    user.dropGem();
                }
            }
            
        }
        user.addToBackpack(new ArtifactItem);
        endConditions++;
    }

    //if MummySpace
    else if (type == 'M')
    {
        gameOver = true;
        endConditions -= 100;
    }

    //if ExitSpace
    else if (type == 'G')
    {
        gameOver = true;
    }

    //if ShopSpace
    else if (type == 'S')
    {
        purchase();


        std::cout << std::endl << std::endl;
        std::cout << "Just so you know, the door locks on your way out! MUAHAHA"
            << std::endl << std::endl << std::endl;

        //"lock" the Shop
        shopOpen = false;
        head[9]->setBottom(nullptr);
    }
}




/*****************************************
Function for the user to add Items to their
inventory from the ShopSpace.
Calls: itemMenu(), dropMenu()
Player::dropGem(), addToBackpack()
Game::purchase, playerDrop()
******************************************/
void Game::purchase()
{
    int option = itemMenu();

    //purchase The Eye
    if (option == 1)
    {
        //user can't afford The Eye
        if (user.getScore() < 300)
        {
            std::cout << "Sorry, you can't afford The Eye" << std::endl
                << std::endl;
            purchase();
        }

        //user can't carry The Eye
        else if (user.getHeaviness() > 7)
        {
            std::cout << "Sorry, you can't carry The Eye" << std::endl;
            int drop = dropMenu();
            if (drop == 1)
            {
                playerDrop();
            }

            purchase();
        }

        //able to purchase
        else
        {
            std::cout << "Thank you for your business!" << std::endl;
            user.addToBackpack(new TheEye);
            //pay
            for (int i = 0; i < 3; i++)
            {
                user.dropGem();
            }

            //find the MummySpace node and change it's token
            for (int i = 0; i < static_cast<int>(nodes.size()); i++)
            {
                if (nodes.at(i)->getType() == 'M')
                {
                    nodes.at(i)->setToken('M');
                }
            }
        }

    }
    //purchase The Map
    else if (option == 2)
    {
        //user can't afford The Map
        if (user.getScore() < 200)
        {
            std::cout << "Sorry, you can't afford The Map" << std::endl
                << std::endl;
            purchase();
        }

        //user can't carry The Map
        else if (user.getHeaviness() > 8)
        {
            std::cout << "Sorry, you can't carry The Map" << std::endl;
            int drop = dropMenu();
            if (drop == 1)
            {
                playerDrop();
            }

            purchase();
        }

        //able to purchase
        else
        {
            std::cout << "Thank you for your business!" << std::endl;
            user.addToBackpack(new TheMap);
            //pay
            for (int i = 0; i < 2; i++)
            {
                user.dropGem();
            }

            //find 5 EmptySpaces nodes and change their token
            for (int i = 0; i < 5; i++)
            {
                //start from the top down
                if (i % 2 == 0)
                {
                    for (int i = 0; i < static_cast<int>(nodes.size()); i++)
                    {
                        if (nodes.at(i)->getType() == 'E')
                        {
                            nodes.at(i)->setToken(' ');
                        }
                    }
                }
                //start from the bottom up
                else
                {
                    for (int i = static_cast<int>(nodes.size())-1; i >= 0; i--)
                    {
                        if (nodes.at(i)->getType() == 'E')
                        {
                            nodes.at(i)->setToken(' ');
                        }
                    }
                }
            }
        }
    }

    //purchase The Tent
    else if (option == 3)
    {
        //user can't afford The Tent
        if (user.getScore() < 100)
        {
            std::cout << "Sorry, you can't afford The Tent" << std::endl
                << std::endl;
            purchase();
        }

        //user can't carry The Map
        else if (user.getHeaviness() > 9)
        {
            std::cout << "Sorry, you can't carry The Tent" << std::endl;
            int drop = dropMenu();
            if (drop == 1)
            {
                playerDrop();
            }

            purchase();
        }

        //able to purchase
        else
        {
            std::cout << "Thank you for your business!" << std::endl;
            user.addToBackpack(new TheTent);
            //pay
            user.dropGem();

            //add time to the timer
            timer += 10;
        }
    }
    else if (option == 4)
    {
        std::cout << "Fine, keep your money. ";
    }
}


/*****************************************
Menu for allowing the player to drop items
from their backpack. Lowers the heaviness
and score
Calls: Player::dropGem()
Game::playerDrop()
inputValidateIntegerAndRange()
*****************************************/
void Game::playerDrop()
{
    std::cout << "How many would you like to drop?: " 
        << "0 to " << user.getGemCount() << std::endl;
    int number = inputValidateIntegerAndRange(0, user.getGemCount());

    for (int i = 0; i < number; i++)
    {
        user.dropGem();
    }
    
    std::cout << "Current Weight: " << user.getHeaviness() << "/10" << std::endl
        << std::endl;
    std::cout << "Would you like to drop more gems?" << std::endl;
    std::cout << "1. Yes" << std::endl;
    std::cout << "2. No" << std::endl;
    int option = inputValidateIntegerAndRange(1, 2);
    if (option == 1)
    {
        playerDrop();
    }

    return;
}
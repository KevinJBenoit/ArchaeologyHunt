/****************************************************************************************
** Program name: inputValidate.cpp
** Author: Kevin Benoit
** Date: 6/02/2019
** Description: Contains the definitions for the several variations of inputValidate functions
    The functions will check for specified type and range. If they are not the function will
    give a prompt on how to correct and loop until the proper input is given.
****************************************************************************************/

#include "inputValidate.hpp"
#include <iostream>
#include <limits>

/****************************************************
Validate the user input is an integer
Credit: cplusplus.com/forum/beginner/26821/
****************************************************/
int inputValidateInteger()
{
    int integer;
    bool invalid = false;

    //get user's input
    std::cin >> integer;

    //peek to see whats next, check if the integer was the only input entered
    //Credit: cplusplus.com/forum/beginner/30834/
    if (std::cin.peek() != '\n')
    {
        invalid = true;
    }

    //if not all chars were digits
    if (invalid == true || std::cin.fail())
    {
        do
        {
            std::cin.clear();
            //discards all unread chars in the input buffe
            //Credit: stackoverflow.com/questions/10585392/
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter only integers." << std::endl;
            //reset the flag
            invalid = false;
            std::cin >> integer;

            if (std::cin.peek() != '\n')
            {
                invalid = true;
            }
        } while (invalid || std::cin.fail());
    }
    std::cin.clear();
    //Credit: stackoverflow.com/questions/10585392/
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return integer;
}
/*****************************************
Builds on inputValidateInteger() to check if user
input is a valid integer and lies within the specified
range of (min, max). Returns a valid integer.
*****************************************/
int inputValidateIntegerAndRange(int min, int max)
{
    int integer;
    bool invalid;

    integer = inputValidateInteger();


    if (integer < min || integer > max)
    {
        do
        {
            std::cout << "Please only enter an integer in the range (" << min << ", " << max << "). Retry: " << std::endl;
            integer = inputValidateInteger();
            if (integer < min || integer > max)
            {
                invalid = true;
            }
            else
            {
                invalid = false;
            }
        } while (invalid);

    }
    return integer;
}



/****************************************************
Validate the user input is an double
Credit: cplusplus.com/forum/beginner/26821/
****************************************************/
double inputValidateDouble()
{
    double decimal;
    bool invalid = false;

    //get user's input
    std::cin >> decimal;

    //peek to see whats next, check if the integer was the only input entered
    //Credit: cplusplus.com/forum/beginner/30834/
    if (std::cin.peek() != '\n')
    {
        invalid = true;
    }

    //if not all chars were digits
    if (invalid == true || std::cin.fail())
    {
        do
        {
            std::cin.clear();
            //discards all unread chars in the input buffe
            //Credit: stackoverflow.com/questions/10585392/
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter only decimals." << std::endl;
            //reset the flag
            invalid = false;
            std::cin >> decimal;

            if (std::cin.peek() != '\n')
            {
                invalid = true;
            }
        } while (invalid || std::cin.fail());
    }
    std::cin.clear();
    //Credit: stackoverflow.com/questions/10585392/
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return decimal;
}



/*****************************************
Builds on inputValidateDouble() to check if user
input is a valid decimal and lies within the specified
range of (min, max). Returns a valid decimal.
*****************************************/
double inputValidateDoubleAndRange(double min, double max)
{
    double decimal;
    bool invalid;

    decimal = inputValidateDouble();


    if (decimal < min || decimal > max)
    {
        do
        {
            std::cout << "Please only enter an decimal in the range (" << min << ", " << max << "). Retry: " << std::endl;
            decimal = inputValidateDouble();
            if (decimal < min || decimal > max)
            {
                invalid = true;
            }
            else
            {
                invalid = false;
            }
        } while (invalid);

    }
    return decimal;
}


/****************************************************
Validate the user input is a char
Credit: cplusplus.com/forum/beginner/26821/
****************************************************/
char inputValidateChar()
{
    char letter;
    bool invalid = false;

    //get user's input
    std::cin >> letter;

    //peek to see whats next, check if the integer was the only input entered
    //Credit: cplusplus.com/forum/beginner/30834/
    if (std::cin.peek() != '\n')
    {
        invalid = true;
    }

    //if not all chars were digits
    if (invalid == true || std::cin.fail())
    {
        do
        {
            std::cin.clear();
            //discards all unread chars in the input buffe
            //Credit: stackoverflow.com/questions/10585392/
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter only chars." << std::endl;
            //reset the flag
            invalid = false;
            std::cin >> letter;

            if (std::cin.peek() != '\n')
            {
                invalid = true;
            }
        } while (invalid || std::cin.fail());
    }
    std::cin.clear();
    //Credit: stackoverflow.com/questions/10585392/
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return letter;
}


/*****************************************
Builds on inputValidateChar() to check if user
input is a valid char and is in the passed array
of chars. Returns a char
*****************************************/
char inputValidateCharArray(char arrayIn[], int size)
{
    char letter;
    bool valid = false;
    int counter;

    do
    {
        //get a valid char
        letter = inputValidateChar();
        counter = 0;
        //check letter with valid chars in array
        do {
            if (arrayIn[counter] == letter) //not tripping for some reason
            {
                valid = true;
            }

            counter++;

        } while (!valid && counter < size);

        //message prompt
        if (!valid)
        {
            std::cout << "Please enter a valid char: ";
            for (int i = 0; i < size; i++)
            {
                std::cout << arrayIn[i] << " ";
            }
            std::cout << std::endl;
        }

    } while (!valid);
    
    return letter;
}

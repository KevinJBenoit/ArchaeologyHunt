/******************************************************************************
** Program name: Space.hpp
** Author: Kevin Benoit
** Date: 5/31/2019
** Description: Contains the class declaration for the base abastract Space
    class. Each Space represents a node structure with pointers to Spaces
    above, bellow, left, and right of it. The data contents will be a base 
    class Item pointer. Virtual and pure vitrual functions will be inherited
    by the derived classes.
*****************************************************************************/


#ifndef SPACE_HPP
#define SPACE_HPP

#include "Item.hpp"


class Space
{
    protected:
        Space * top;
        Space * bottom;
        Space * left;
        Space * right;
        Item * content;
        char token;
        char type;
    
    public:
        virtual Space * getTop();
        virtual void setTop(Space * topIn);
        virtual Space * getBottom();
        virtual void setBottom(Space * bottomIn);
        virtual Space * getLeft();
        virtual void setLeft(Space * leftIn);
        virtual Space * getRight();
        virtual void setRight(Space * rightIn);
        virtual char getToken();
        virtual void setToken(char tokenIn);
        virtual char getType();

        virtual Item* getContent();


        Space();
        virtual ~Space();

        virtual void spaceEvent() = 0;
        virtual void removeToken();
};

#endif

/**
    ITSC 3112-001 Group Project
    VerticalMoveTile.h
    Purpose: Holds prototype declarations for VerticalMoveTile.cpp

    @author Nathan Holzworth, Abhinav Kasu, Johathan Walters
    @version 1.0 11/27/18
*/

#ifndef VERTICALMOVETILE_H_INCLUDED
#define VERTICALMOVETILE_H_INCLUDED

#include "NumberTile.h"

using namespace std;

class VerticalMoveTile : public NumberTile
{
public:

    /**
        Description

        @params
    */
    VerticalMoveTile(int x, int y, int value);



    /**
        Description

        @params
    */
    bool canMoveHorizontal() const;

    /**
        Description

        @returns
    */
    bool canMoveVertical() const;

    /**
        Description

        @params
    */
    string getCombinedTileType(NumberTile* t) const;

    /**
        Description

        @params
    */
    string getConsoleIcon();
};

#endif // VERTICALMOVETILE_H_INCLUDED



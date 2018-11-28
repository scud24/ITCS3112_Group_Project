/**
    ITSC 3112-001 Group Project
    FreeMoveTile.h
    Purpose: Holds prototype declarations for FreeMoveTile.cpp

    @author Nathan Holxworth
    @version 1.0 11/27/18
*/

#ifndef FREEMOVETILE_H_INCLUDED
#define FREEMOVETILE_H_INCLUDED

#include "NumberTile.h"

using namespace std;

class FreeMoveTile : public NumberTile
{
public:

    /**
        Description

        @params
    */
    FreeMoveTile(int x, int y, int value);

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

#endif // FREEMOVETILE_H_INCLUDED




/**
    ITSC 3112-001 Group Project
    HorizontalMoveTile.h
    Purpose: Holds prototype declarations for HorizontalMoveTile.cpp

    @author Nathan Holxworth
    @version 1.0 11/27/18
*/

#ifndef HORIZONTALMOVETILE_H_INCLUDED
#define HORIZONTALMOVETILE_H_INCLUDED

#include "NumberTile.h"

using namespace std;

class HorizontalMoveTile : public NumberTile
{
public:

    /**
        Description

        @params
    */
    HorizontalMoveTile(int x, int y, int value);


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
};

#endif // HORIZONTALMOVETILE_H_INCLUDED



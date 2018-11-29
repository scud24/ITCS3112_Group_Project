/**
    ITSC 3112-001 Group Project
    FreeMoveTile.h
    Purpose: Holds prototype declarations for FreeMoveTile.cpp

    @author Nathan Holzworth, Abhinav Kasu, Johathan Walters
    @version 1.0 11/27/18
*/

#ifndef FREEMOVETILE_H_INCLUDED
#define FREEMOVETILE_H_INCLUDED

// Include required header files 
#include "NumberTile.h"

using namespace std;

class FreeMoveTile : public NumberTile
{
public:

    /**
        Constructor: Create tile that can only move freely.

        @param x cordinate value on grid.
        @param y cordinate value on grid.
        @param value the number Tile should hold. 
    */
    FreeMoveTile(int x, int y, int value);

    /**
        Determine if tile can move horizontally.
        
        @param none
        @return True or False for the move.
    */
    bool canMoveHorizontal() const;

    /**
        Determine if tile can move vertically.

        @param none
        @return True or False for the move.
    */
    bool canMoveVertical() const;

    /**
        Gets the Tile type Vertical or Horizontal.

        @param t The Tile
        @return String denoting the Tile type.
    */
    string getCombinedTileType(NumberTile* t) const;

    /**
        Gets the Tile icons textual representation.

        @param none
        @return String denoting the Tile type.
    */
    string getConsoleIcon();
};

#endif // FREEMOVETILE_H_INCLUDED


